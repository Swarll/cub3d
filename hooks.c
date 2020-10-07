/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:47:03 by Guillaume         #+#    #+#             */
/*   Updated: 2020/10/07 09:33:20 by grigaux          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    key_press_hook(int keycode, t_gameinf *game)
{
    double rot_speed;
    double move_speed;
    double old_dir_x;
    double old_plane_x;

    rot_speed = 3.0 / 150;
    move_speed = 5.0 / 50;

    if (keycode == 123) // right arrow
    {
        old_dir_x = game->dir_x;
        game->dir_x = game->dir_x * cos(rot_speed) - game->dir_y * sin(rot_speed);
        game->dir_y = old_dir_x * sin(rot_speed) + game->dir_y * cos(rot_speed);
        old_plane_x = game->plane_x;
        game->plane_x = game->plane_x * cos(rot_speed) - game->plane_y * sin(rot_speed);
        game->plane_y = old_plane_x * sin(rot_speed) + game->plane_y * cos(rot_speed);
    }
    else if (keycode == 124) // left arrow
    {
        old_dir_x = game->dir_x;
        game->dir_x = game->dir_x * cos(-rot_speed) - game->dir_y * sin(-rot_speed);
        game->dir_y = old_dir_x * sin(-rot_speed) + game->dir_y * cos(-rot_speed);
        old_plane_x = game->plane_x;
        game->plane_x = game->plane_x * cos(-rot_speed) - game->plane_y * sin(-rot_speed);
        game->plane_y = old_plane_x * sin(-rot_speed) + game->plane_y * cos(-rot_speed);
    }
    else if (keycode == 13) // up
    {
        if (game->map[(int)game->pos_y][(int)(game->pos_x + game->dir_x * move_speed)] &&
        game->map[(int)game->pos_y][(int)(game->pos_x + game->dir_x * move_speed)] == '0')
            game->pos_x += game->dir_x * move_speed;
        if (game->map[(int)(game->pos_y + game->dir_y * move_speed)][(int)game->pos_x] &&
        game->map[(int)(game->pos_y + game->dir_y * move_speed)][(int)game->pos_x] == '0')
            game->pos_y += game->dir_y * move_speed;
    }
    else if (keycode == 1) // down
    {
        if (game->map[(int)game->pos_y][(int)(game->pos_x - game->dir_x * move_speed)] &&
        game->map[(int)game->pos_y][(int)(game->pos_x - game->dir_x * move_speed)] == '0')
            game->pos_x -= game->dir_x * move_speed;
        if (game->map[(int)(game->pos_y - game->dir_y * move_speed)][(int)game->pos_x] &&
        game->map[(int)(game->pos_y - game->dir_y * move_speed)][(int)game->pos_x] == '0')
            game->pos_y -= game->dir_y * move_speed;
    }
    else if (keycode == 0) // left
    {
        if (game->map[(int)game->pos_y][(int)(game->pos_x - game->dir_y * move_speed)] &&
        game->map[(int)game->pos_y][(int)(game->pos_x - game->dir_y * move_speed)] == '0')
            game->pos_x -= game->dir_y * move_speed;
        if (game->map[(int)(game->pos_y + game->dir_x * move_speed)][(int)game->pos_x] &&
        game->map[(int)(game->pos_y + game->dir_x * move_speed)][(int)game->pos_x] == '0')
            game->pos_y += game->dir_x * move_speed;
    }
    else if (keycode == 2) // right
    {
        if (game->map[(int)(game->pos_y + game->dir_x * move_speed)][(int)game->pos_x] &&
        game->map[(int)(game->pos_y + game->dir_x * move_speed)][(int)game->pos_x] == '0')
            game->pos_x += game->dir_y * move_speed;
        if (game->map[(int)game->pos_y][(int)(game->pos_x - game->dir_y * move_speed)] &&
        game->map[(int)game->pos_y][(int)(game->pos_x - game->dir_y * move_speed)] == '0')
            game->pos_y -= game->dir_x * move_speed;
    }
    else if (keycode == 53) // esc
    {
        mlx_destroy_image(game->mlx_ptr, game->img_ptr);
        mlx_destroy_window(game->mlx_ptr, game->win_ptr);
        free_struct(game);
        exit(0);
    }
    start_game(game);
    return 0;
}