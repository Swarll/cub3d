/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillaume <Guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:41:57 by grigaux           #+#    #+#             */
/*   Updated: 2020/10/02 13:20:38 by Guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    set_loops(t_gameinf *game, t_map *map)
{
    mlx_hook(game->win_ptr, 2, 0, key_pressed, game);
    mlx_loop(game->mlx_ptr);
    (void)map;
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

int     seek_spawn(t_map *map, t_gameinf *game)
{
    int i;
    int j;
    char act;

    i = 0;
    j = 0;
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            act = map->map[i][j];
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

void    *start_ray(t_map *map)
{
    t_gameinf   *game;

    if (!(game = malloc(sizeof(t_gameinf))))
        return (0);
    initialize_game(game);
    if (!(game->mlx_ptr = mlx_init()))
        return (0);
    if (!(seek_spawn(map, game)))
        exit_all(map, game, "Error\nSpawn not found into map");
    game->win_ptr = mlx_new_window(game->mlx_ptr, map->res_x, map->res_y, "cub");
    start_game(game, map);
    set_loops(game, map);
    // mlx_loop(game->mlx_ptr);
    return (0);
}