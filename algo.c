/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:21:34 by grigaux           #+#    #+#             */
/*   Updated: 2020/10/22 19:03:27 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		dda_calc(t_gameinf *game)
{
	int hit;
	int side;

	hit = 0;
	while (!hit)
	{
		if (game->side_dist_x < game->side_dist_y)
		{
			game->side_dist_x += game->delta_dist_x;
			game->square_x += game->step_x;
			side = 0;
		}
		else
		{
			game->side_dist_y += game->delta_dist_y;
			game->square_y += game->step_y;
			side = 1;
		}
		if (game->map[game->square_y][game->square_x] == '1')
			hit = 1;
	}
	return (side);
}

void	after_dda(t_gameinf *game, int side)
{
	if (side == 0)
		game->perp_wall_dist = (game->square_x - game->pos_x + (1 -
			game->step_x) / 2) / game->ray_dir_x;
	else
		game->perp_wall_dist = (game->square_y - game->pos_y + (1 -
			game->step_y) / 2) / game->ray_dir_y;
	game->line_height = (int)(game->res_y / game->perp_wall_dist);
	game->draw_start = (game->line_height * (-1)) / 2 + game->res_y / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->line_height / 2 + game->res_y / 2;
	if (game->draw_end >= game->res_y)
		game->draw_end = game->res_y - 1;
}

void	before_dda2(t_gameinf *game)
{
	if (game->ray_dir_x < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->pos_x - game->square_x) * game->delta_dist_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->square_x + 1.0 - game->pos_x) *
			game->delta_dist_x;
	}
	if (game->ray_dir_y < 0)
	{
		game->step_y = -1;
		game->side_dist_y = (game->pos_y - game->square_y) * game->delta_dist_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->square_y + 1.0 - game->pos_y) *
			game->delta_dist_y;
	}
}

void	before_dda(int x, t_gameinf *game)
{
	game->camera_x = 2 * x / (double)game->res_x - 1;
	game->ray_dir_x = game->dir_x + game->plane_x * game->camera_x;
	game->ray_dir_y = game->dir_y + game->plane_y * game->camera_x;
	game->square_x = (int)game->pos_x;
	game->square_y = (int)game->pos_y;
	game->delta_dist_x = fabs(1 / game->ray_dir_x);
	game->delta_dist_y = fabs(1 / game->ray_dir_y);
	before_dda2(game);
}

void	start_algo(t_gameinf *game)
{
	int		x;
	int		side;
	double	z_buffer[game->res_x];

	x = 0;
	while (x < game->res_x)
	{
		before_dda(x, game);
		side = dda_calc(game);
		after_dda(game, side);
		draw_line(x, game, side);
		z_buffer[x] = game->perp_wall_dist;
		x++;
	}
	draw_sprites(game, count_sprites(game), z_buffer);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr, 0, 0);
}
