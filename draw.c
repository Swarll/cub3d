/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:23:43 by grigaux           #+#    #+#             */
/*   Updated: 2020/10/21 15:16:02 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_sprites(t_gameinf *game, int count, double *z_buffer)
{
	int i;
	int stripe;
	int y;
    
	i = 0;
	update_sprites(game, count);
	while (i < count)
	{
		game->s.sprite_x = game->sprites[i].x - game->pos_x;
		game->s.sprite_y = game->sprites[i].y - game->pos_y;
		game->s.inv_det = 1.0 / (game->plane_x * game->dir_y - game->dir_x * game->plane_y);
		game->s.transform_x = game->s.inv_det * (game->dir_y * game->s.sprite_x - game->dir_x * game->s.sprite_y);
		game->s.transform_y = game->s.inv_det * (-game->plane_y * game->s.sprite_x + game->plane_x * game->s.sprite_y);

		game->s.sprite_screen_x = (int)((game->res_x / 2) * (1 + game->s.transform_x / game->s.transform_y));

		game->s.sprite_height = abs((int)(game->res_y / game->s.transform_y));
		game->s.draw_start_y = -game->s.sprite_height / 2 + game->res_y / 2;
		if (game->s.draw_start_y < 0)
			game->s.draw_start_y = 0;
		game->s.draw_end_y = game->s.sprite_height / 2 + game->res_y / 2;
		if (game->s.draw_end_y >= game->res_y)
			game->s.draw_end_y = game->res_y - 1;
		
		game->s.sprite_width = abs((int)(game->res_y / game->s.transform_y));
		game->s.draw_start_x = -game->s.sprite_width / 2 + game->s.sprite_screen_x;
		if (game->s.draw_start_x < 0)
			game->s.draw_start_x = 0;
		game->s.draw_end_x = game->s.sprite_width / 2 + game->s.sprite_screen_x;
		if (game->s.draw_end_x >= game->res_x)
			game->s.draw_end_x = game->res_x - 1;
		
		stripe = game->s.draw_start_x;
		while (stripe < game->s.draw_end_x)
		{
			game->s.tex_x = (int)(256 * (stripe - (-(game->s.sprite_width) / 2 + game->s.sprite_screen_x)) * game->texts[4].size_x / game->s.sprite_width / 256);
			if (game->s.transform_y > 0 && stripe > 0 && stripe < game->res_x && game->s.transform_y < z_buffer[stripe])
			{
				y = game->s.draw_start_y;
				while (y < game->s.draw_end_y)
				{
					game->s.d = (y) * 256 - game->res_y * 128 + game->s.sprite_height * 128;
					game->s.tex_y = ((game->s.d * game->texts[4].size_y) / game->s.sprite_height / 256);
					if (game->texts[4].text_i[game->texts[4].size_x * game->s.tex_y + game->s.tex_x])
						game->img[stripe + y * game->res_x] = game->texts[4].text_i[game->texts[4].size_x * game->s.tex_y + game->s.tex_x];
					y++;
				}
			}
			stripe++;
		}
		i++;
	}
}

t_text seek_text(t_gameinf *game, int side)
{
	if (side == 0)
	{
		if (game->ray_dir_x > 0)
			return (game->texts[2]);
		else
			return (game->texts[3]);
	}
	else
	{
		if (game->ray_dir_y > 0)
			return (game->texts[1]);
		else
			return (game->texts[0]);
	}
	
}

int     draw_text(t_gameinf *game, int x, int y, int side)
{
	double wall_x;
	int text_x;
	double step;
	double text_pos;
	int text_y;
	t_text text;

	text = seek_text(game, side);
	if (side == 0)
		wall_x = game->pos_y + game->perp_wall_dist * game->ray_dir_y;
	else
		wall_x = game->pos_x + game->perp_wall_dist * game->ray_dir_x;
	wall_x -= floor((wall_x));
	text_x = (int)(wall_x * (double)text.size_x);
	if (side == 0 && game->ray_dir_x > 0)
		text_x = text.size_x - text_x - 1;
	if (side == 1 && game->ray_dir_y < 0)
		text_x = text.size_x - text_x - 1;
	step = 1.0 * text.size_y / game->line_height;
	text_pos = (game->draw_start - game->res_y / 2 + game->line_height / 2) * step;
	while (y < game->draw_end)
	{
		text_y = (int)text_pos & (text.size_y - 1);
		text_pos += step;
		game->img[x + y++ * game->res_x] = text.text_i[text.size_y * text_y + text_x];
	}
	return (y);
}

void    draw_line(int x, t_gameinf *game, int side)
{
	int y;
	int a;
	
	if (!game->img_ptr)
		game->img_ptr = mlx_new_image(game->mlx_ptr, game->res_x, game->res_y);
	game->img = (int*)mlx_get_data_addr(game->img_ptr, &a, &a, &a);
	y = 0;
	while (y < game->draw_start)
	{
		game->img[x + y++ * game->res_x] = 0x00F000; ////////changer avec couleurs du .cub
	}
	if (y < game->draw_end)
	{
		y = draw_text(game, x, y, side);
	}
	while (y < game->res_y)
	{
		game->img[x + y++ * game->res_x] = 0x0000FF; ////////changer avec couleurs du .cub
	}
}
