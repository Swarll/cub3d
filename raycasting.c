/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:41:57 by grigaux           #+#    #+#             */
/*   Updated: 2020/09/10 16:38:51 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    initialize_game(t_gameinf *game)
{
    game->mlx_ptr = 0;
    game->win_ptr = 0;
    game->spawn_y = 0;
    game->spawn_x = 0;
    game->spawn_dir = 0;
}

int     seek_spawn(t_map *map, t_gameinf *game)
{
    int y;
    int x;
    char act;

    y = 0;
    x = 0;
    while (map->map[y])
    {
        while (map->map[y][x])
        {
            act = map->map[y][x];
            if (!ft_isspace(act) && (act == 'N' || act == 'S' || act == 'E' || act == 'W'))
            {
                game->spawn_y = y;
                game->spawn_x = x;
                game->spawn_dir = map->map[y][x];
                return (1);
            }
            x++;
        }
        y++;
    }
    return (0);
}

void    *start_ray(t_map *map)
{
    t_gameinf   *game; ///////// init

    if (!(game = malloc(sizeof(t_gameinf))))
        return (0);
    initialize_game(game);
    if (!(game->mlx_ptr = mlx_init()))
        return (0);
    game->win_ptr = mlx_new_window(game->mlx_ptr, map->res_x, map->res_y, "cub");
    mlx_loop(game->win_ptr);
    if (!(seek_spawn(map, game)))
        exit_all(map, game, "Error\nSpawn not found into map");
    mlx_pixel_put(game->mlx_ptr, game->win_ptr, 1, 1, 0200);
    return (0);
}