/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:47:03 by Guillaume         #+#    #+#             */
/*   Updated: 2020/10/08 17:54:46 by grigaux          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int    destroy(t_gameinf *game)
{
    mlx_destroy_image(game->mlx_ptr, game->img_ptr);
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    free_struct(game);
    exit(0);
    return (0);
}

int    key_press_hook(int keycode, t_gameinf *game)
{
    if (keycode == 123)
        game->right_arr = 1;
    else if (keycode == 124)
        game->left_arr = 1;
    else if (keycode == 13)
        game->forward = 1;
    else if (keycode == 1)
        game->backward = 1;
    else if (keycode == 0)
        game->left = 1;
    else if (keycode == 2)
        game->right = 1;
    else if (keycode == 53) 
        destroy(game);
    return 0;
}

int     key_release_hook(int keycode, t_gameinf *game)
{
    if (keycode == 123)
        game->right_arr = 0;
    else if (keycode == 124)
        game->left_arr = 0;
    else if (keycode == 13)
        game->forward = 0;
    else if (keycode == 1)
        game->backward = 0;
    else if (keycode == 0)
        game->left = 0;
    else if (keycode == 2)
        game->right = 0;
    return (0);
}

int     move_hook(t_gameinf *game)
{
    double rot_speed;
    double move_speed;
    double old_dir_x;
    double old_plane_x;

    rot_speed = 0.02;
    move_speed = 0.05;
    if (game->right_arr)
    {
        old_dir_x = game->dir_x;
        game->dir_x = game->dir_x * cos(rot_speed) - game->dir_y * sin(rot_speed);
        game->dir_y = old_dir_x * sin(rot_speed) + game->dir_y * cos(rot_speed);
        old_plane_x = game->plane_x;
        game->plane_x = game->plane_x * cos(rot_speed) - game->plane_y * sin(rot_speed);
        game->plane_y = old_plane_x * sin(rot_speed) + game->plane_y * cos(rot_speed);
        start_game(game);
    }
    if (game->left_arr)
    {
        old_dir_x = game->dir_x;
        game->dir_x = game->dir_x * cos(-rot_speed) - game->dir_y * sin(-rot_speed);
        game->dir_y = old_dir_x * sin(-rot_speed) + game->dir_y * cos(-rot_speed);
        old_plane_x = game->plane_x;
        game->plane_x = game->plane_x * cos(-rot_speed) - game->plane_y * sin(-rot_speed);
        game->plane_y = old_plane_x * sin(-rot_speed) + game->plane_y * cos(-rot_speed);
        start_game(game);
    }
    if (game->forward)
    {
        if (game->map[(int)game->pos_y][(int)(game->pos_x + game->dir_x * move_speed)] &&
        game->map[(int)(game->pos_y)][(int)((game->pos_x) + game->dir_x * move_speed)] != '1')
            game->pos_x += game->dir_x * move_speed;
        if (game->map[(int)(game->pos_y + game->dir_y * move_speed)][(int)game->pos_x] &&
        game->map[(int)(game->pos_y  + game->dir_y * move_speed)][(int)(game->pos_x)] != '1')
            game->pos_y += game->dir_y * move_speed;
        start_game(game);
    }
    if (game->backward)
    {
        if (game->map[(int)game->pos_y][(int)(game->pos_x - game->dir_x * move_speed)] &&
        game->map[(int)game->pos_y][(int)(game->pos_x - game->dir_x * move_speed)] != '1')
            game->pos_x -= game->dir_x * move_speed;
        if (game->map[(int)(game->pos_y - game->dir_y * move_speed)][(int)game->pos_x] &&
        game->map[(int)(game->pos_y - game->dir_y * move_speed)][(int)game->pos_x] != '1')
            game->pos_y -= game->dir_y * move_speed;
        start_game(game);
    }
    if (game->left)
    {
        if (game->map[(int)game->pos_y][(int)(game->pos_x - game->dir_y * move_speed)] &&
        game->map[(int)game->pos_y][(int)(game->pos_x - game->dir_y * move_speed)] != '1')
            game->pos_x -= game->dir_y * move_speed;
        if (game->map[(int)(game->pos_y + game->dir_x * move_speed)][(int)game->pos_x] &&
        game->map[(int)(game->pos_y + game->dir_x * move_speed)][(int)game->pos_x] != '1')
            game->pos_y += game->dir_x * move_speed;
        start_game(game);
    }
    if (game->right)
    {
        if (game->map[(int)(game->pos_y + game->dir_x * move_speed)][(int)game->pos_x] &&
        game->map[(int)(game->pos_y + game->dir_x * move_speed)][(int)game->pos_x] != '1')
            game->pos_x += game->dir_y * move_speed;
        if (game->map[(int)game->pos_y][(int)(game->pos_x - game->dir_y * move_speed)] &&
        game->map[(int)game->pos_y][(int)(game->pos_x - game->dir_y * move_speed)] != '1')
            game->pos_y -= game->dir_x * move_speed;
        start_game(game);
    }
    return (0);
}