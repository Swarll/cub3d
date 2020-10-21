/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:41:57 by grigaux           #+#    #+#             */
/*   Updated: 2020/10/21 15:16:10 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    set_loops(t_gameinf *game)
{	
	mlx_hook(game->win_ptr, 2, 0, key_press_hook, game);
	mlx_hook(game->win_ptr, 3, 0, key_release_hook, game);
	mlx_hook(game->win_ptr, 17, 0, destroy, game);
	mlx_loop_hook(game->mlx_ptr, move_hook, game);
	mlx_loop(game->mlx_ptr);
}

void    init_sprites(t_gameinf *game)
{	
	game->s.sprite_x = 0;
	game->s.sprite_y = 0;
	game->s.inv_det = 0;
	game->s.transform_x = 0;
	game->s.transform_y = 0;
	game->s.sprite_screen_x = 0;
	game->s.sprite_height = 0;
	game->s.draw_start_y = 0;
	game->s.draw_start_x = 0;
	game->s.draw_end_y = 0;
	game->s.draw_end_x = 0;
	game->s.sprite_width = 0;
	game->s.tex_x = 0;
	game->s.d = 0;
	game->s.tex_y = 0;
}

void    init_text(t_gameinf *game)
{
	int i;

	i = 0;
	while (i <= 4)
	{
		game->texts[i].text_v = 0;
		game->texts[i].text_c = 0;
		game->texts[i].text_i = 0;
		game->texts[i].size_x = 0;
		game->texts[i].size_y = 0;
		game->texts[i].bpp = 0;
		game->texts[i].sl = 0;
		game->texts[i].end = 0;
		i++;
	}
}

void    init_game(t_gameinf *game)
{
	game->mlx_ptr = 0;
	game->win_ptr = 0;
	game->img_ptr = 0;
	game->img = 0;
	game->pos_y = 0;
	game->pos_x = 0;
	game->dir_x = 0;
	game->dir_y = 0;
	game->plane_x = 0;
	game->plane_y = 0.66;
	game->camera_x = 0;
	game->ray_dir_x = 0;
	game->ray_dir_y = 0;
	game->square_x = 0;
	game->square_y = 0;
	game->side_dist_x = 0;
	game->side_dist_y = 0;
	game->delta_dist_x = 0;
	game->delta_dist_y = 0;
	game->perp_wall_dist = 0;
	game->step_x = 0;
	game->step_y = 0;
	game->line_height = 0;
}

void    init_map(t_gameinf *game)
{
	game->res_x = 0;
	game->res_y = 0;
	game->north_path = 0;
	game->south_path = 0;
	game->west_path = 0;
	game->east_path = 0;
	game->sprite_path = 0;
	game->floor_color[0] = 0;
	game->floor_color[1] = 0;
	game->floor_color[2] = 0;
	game->ceiling_color[0] = 0;
	game->ceiling_color[1] = 0;
	game->ceiling_color[2] = 0;
	game->map = 0;
	game->left_arr = 0;
	game->right_arr = 0;
	game->left = 0;
	game->right = 0;
	game->forward = 0;
	game->backward = 0;
	init_game(game);
	init_text(game);
	init_sprites(game);
}

int     seek_spawn(t_gameinf *game)
{
	int i;
	int j;
	char act;

	i = 0;
	j = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			act = game->map[i][j];
			if (act && (act == 'N' || act == 'S' || act == 'E' || act == 'W'))
			{
				game->pos_y = i + 0.5;
				game->pos_x = j + 0.5;
				if (act == 'E')
				{
					game->dir_x = 1;
					game->plane_y = 0.66;
				}
				else if (act == 'W')
				{
					game->dir_x = -1;
					game->plane_y = -0.66;
				}
				else if (act == 'S')
				{
					game->dir_y = 1;
					game->plane_x = -0.66;
				}
				else if (act == 'N')
				{
					game->dir_y = -1;
					game->plane_x = 0.66;
				}
				
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void    *start_ray(t_gameinf *game)
{
	if (!(game->mlx_ptr = mlx_init()))
		return (0);
	if (!(seek_spawn(game)))
		exit_struct("Error\nSpawn not found into map", game);
	if (!(set_text(game)))
		exit_struct("Error\nError while loading textures", game);
	set_sprites(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->res_x, game->res_y, "cub");
	start_algo(game);
	set_loops(game);
	return (0);
}