/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:41:57 by grigaux           #+#    #+#             */
/*   Updated: 2020/10/06 10:33:16 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    set_loops(t_gameinf *game)
{	
    mlx_hook(game->win_ptr, 2, 0, key_press_hook, game);
	// mlx_hook(v->window, 3, 0, key_release_hook, game, map);
    mlx_loop(game->mlx_ptr);
}

void    initialize_game(t_gameinf *game)
{
    game->mlx_ptr = 0;
    game->win_ptr = 0;
    game->pos_y = 0;
    game->pos_x = 0;
    game->dir_x = 0;
    game->dir_y = 0;
    game->plane_x = 0;
    game->plane_y = 0.66;
    game->time = 0;
    game->old_time = 0;
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
    game->draw_start = 0;
    game->draw_end = 0;
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
                game->pos_y = i;
                game->pos_x = j;
                if (act == 'E')
                {
                    game->dir_x = -1;
                    game->dir_y = 0;
                }
                else if (act == 'W')
                {
                    game->dir_x = 1;
                    game->dir_y = 0;
                }
                else if (act == 'S')
                {
                    game->dir_x = 0;
                    game->dir_y = 1;
                }
                else
                {
                    game->dir_x = 0;
                    game->dir_y = -1;
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
    initialize_game(game);
    if (!(game->mlx_ptr = mlx_init()))
        return (0);
    if (!(seek_spawn(game)))
        exit_struct("Error\nSpawn not found into map", game);
    game->win_ptr = mlx_new_window(game->mlx_ptr, game->res_x, game->res_y, "cub");
    start_game(game);
    set_loops(game);
    // mlx_loop(game->mlx_ptr);
    return (0);
}