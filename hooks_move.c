/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 13:07:56 by grigaux           #+#    #+#             */
/*   Updated: 2020/10/22 18:19:06 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	b_f_hook(t_gameinf *game, double move_speed, int mod_x, int mod_y)
{
	if (game->forward)
	{
		if (game->map[(int)(game->pos_y)][(int)(game->pos_x + (0.2 * mod_x)
		+ game->dir_x * move_speed)] != '1')
			game->pos_x += game->dir_x * move_speed;
		if (game->map[(int)(game->pos_y + (0.2 * mod_y) + game->dir_y
		* move_speed)][(int)(game->pos_x)] != '1')
			game->pos_y += game->dir_y * move_speed;
		start_algo(game);
	}
	if (game->backward)
	{
		if (game->map[(int)game->pos_y][(int)(game->pos_x - (0.2 * mod_x)
		- game->dir_x * move_speed)] != '1')
			game->pos_x -= game->dir_x * move_speed;
		if (game->map[(int)(game->pos_y - (0.2 * mod_y) - game->dir_y
		* move_speed)][(int)game->pos_x] != '1')
			game->pos_y -= game->dir_y * move_speed;
		start_algo(game);
	}
}

void	l_r_hook(t_gameinf *game, double move_speed, int mod_x, int mod_y)
{
	if (game->left)
	{
		if (game->map[(int)((game->pos_y - game->dir_x * move_speed)
		- mod_y)][(int)game->pos_x] != '1')
			game->pos_y -= game->dir_x * move_speed;
		if (game->map[(int)game->pos_y][(int)((game->pos_x + game->dir_y
		* move_speed) + mod_x)] != '1')
			game->pos_x += game->dir_y * move_speed;
		start_algo(game);
	}
	if (game->right)
	{
		if (game->map[(int)game->pos_y][(int)((game->pos_x
		- game->dir_y * move_speed) + mod_x)] != '1')
			game->pos_x -= game->dir_y * move_speed;
		if (game->map[(int)((game->pos_y + game->dir_x * move_speed)
		+ mod_y)][(int)game->pos_x] != '1')
			game->pos_y += game->dir_x * move_speed;
		start_algo(game);
	}
}

void	rotation_hook(t_gameinf *game, double rot_speed, double odir_x,
double old_x)
{
	if (game->right_arr)
	{
		odir_x = game->dir_x;
		game->dir_x = game->dir_x * cos(-rot_speed) - game->dir_y
			* sin(-rot_speed);
		game->dir_y = odir_x * sin(-rot_speed) + game->dir_y * cos(-rot_speed);
		old_x = game->plane_x;
		game->plane_x = game->plane_x * cos(-rot_speed) - game->plane_y
			* sin(-rot_speed);
		game->plane_y = old_x * sin(-rot_speed) + game->plane_y
			* cos(-rot_speed);
		start_algo(game);
	}
	if (game->left_arr)
	{
		odir_x = game->dir_x;
		game->dir_x = game->dir_x * cos(rot_speed) - game->dir_y
		* sin(rot_speed);
		game->dir_y = odir_x * sin(rot_speed) + game->dir_y * cos(rot_speed);
		old_x = game->plane_x;
		game->plane_x = game->plane_x * cos(rot_speed) - game->plane_y
		* sin(rot_speed);
		game->plane_y = old_x * sin(rot_speed) + game->plane_y * cos(rot_speed);
		start_algo(game);
	}
}

int		move_hook(t_gameinf *game)
{
	double rot_speed;
	double move_speed;
	double mod_x;
	double mod_y;

	rot_speed = 0.02;
	move_speed = 0.05;
	mod_y = 0.2;
	mod_x = 0.2;
	if (game->dir_y >= 0)
		mod_y = -0.2;
	if (game->dir_x >= 0)
		mod_x = -0.2;
	rotation_hook(game, rot_speed, 0, 0);
	l_r_hook(game, move_speed, mod_x, mod_y);
	b_f_hook(game, move_speed, mod_x, mod_y);
	return (0);
}
