/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:56:34 by grigaux           #+#    #+#             */
/*   Updated: 2020/10/09 17:10:34 by grigaux          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     set_text(t_gameinf *game)
{
    void    *tmp;
    int a;


    printf("segv\n");
    tmp = mlx_xpm_file_to_image(game->mlx_ptr, game->north_path, &a, &a);
    game->text_n = (int *)mlx_get_data_addr(tmp, &a, &a, &a);
    tmp = mlx_xpm_file_to_image(game->mlx_ptr, game->south_path, &a, &a);
    game->text_s = (int *)mlx_get_data_addr(tmp, &a, &a, &a);
    tmp = mlx_xpm_file_to_image(game->mlx_ptr, game->east_path, &a, &a);
    game->text_e = (int *)mlx_get_data_addr(tmp, &a, &a, &a);
    tmp = mlx_xpm_file_to_image(game->mlx_ptr, game->west_path, &a, &a);
    game->text_w = (int *)mlx_get_data_addr(tmp, &a, &a, &a);
    printf("nosegv\n");
    // game->text_s = mlx_xpm_file_to_image(game->mlx_ptr, game->south_path, 0, 0);
    // game->text_e = mlx_xpm_file_to_image(game->mlx_ptr, game->east_path, 0, 0);
    // game->text_w = mlx_xpm_file_to_image(game->mlx_ptr, game->west_path, 0, 0);
    return (1);
}