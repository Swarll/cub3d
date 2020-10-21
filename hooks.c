/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 12:47:03 by Guillaume         #+#    #+#             */
/*   Updated: 2020/10/21 13:08:27 by grigaux          ###   ########.fr       */
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
