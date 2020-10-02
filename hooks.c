/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillaume <Guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:47:03 by Guillaume         #+#    #+#             */
/*   Updated: 2020/10/02 13:20:50 by Guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    key_pressed(int key, t_gameinf *game, t_map *map)
{
    if (key == 0x7B)
    {
        double old_dir_x = game->dir_x;
        game->dir_x = game->dir_x * cos(3.0) - game->dir_y * sin(3.0);
        game->dir_y = old_dir_x * sin(3.0) + game->dir_y * cos(3.0);
        double old_plane_x = game->plane_x;
        game->plane_x = game->plane_x * cos(3.0) - game->plane_y * sin(5.0);
        game->plane_y = old_plane_x * sin(3.0) + game->plane_y * cos(3.0);
    }
    start_game(game, map);
    return 0;
}