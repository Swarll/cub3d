/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 15:56:34 by grigaux           #+#    #+#             */
/*   Updated: 2020/10/21 12:12:19 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		set_text2(t_gameinf *game)
{
	if (!(game->texts[3].text_v = mlx_xpm_file_to_image(game->mlx_ptr, 
		game->west_path, &game->texts[3].size_x, &game->texts[3].size_y)))
		return (0);
	if (!(game->texts[3].text_c = mlx_get_data_addr(game->texts[3].text_v, 
		&game->texts[3].bpp, &game->texts[3].sl, &game->texts[3].end)))
		return (0);
	if (!(game->texts[3].text_i = (int*)game->texts[3].text_c))
		return (0);
	if (!(game->texts[4].text_v = mlx_xpm_file_to_image(game->mlx_ptr, 
		game->sprite_path, &game->texts[4].size_x, &game->texts[4].size_y)))
		return (0);
	if (!(game->texts[4].text_c = mlx_get_data_addr(game->texts[4].text_v, 
		&game->texts[4].bpp, &game->texts[4].sl, &game->texts[4].end)))
		return (0);
	if (!(game->texts[4].text_i = (int*)game->texts[4].text_c))
		return (0);
	return (1);
}
int     set_text(t_gameinf *game)
{
	if (!(game->texts[0].text_v = mlx_xpm_file_to_image(game->mlx_ptr, 
		game->north_path, &game->texts[0].size_x, &game->texts[0].size_y)))
		return (0);
	if (!(game->texts[0].text_c = mlx_get_data_addr(game->texts[0].text_v, 
		&game->texts[0].bpp, &game->texts[0].sl, &game->texts[0].end)))
		return (0);
	if (!(game->texts[0].text_i = (int*)game->texts[0].text_c))
		return (0);
	if (!(game->texts[1].text_v = mlx_xpm_file_to_image(game->mlx_ptr, 
		game->south_path, &game->texts[1].size_x, &game->texts[1].size_y)))
		return (0);
	if (!(game->texts[1].text_c = mlx_get_data_addr(game->texts[1].text_v, 
		&game->texts[1].bpp, &game->texts[1].sl, &game->texts[1].end)))
		return (0);
	if (!(game->texts[1].text_i = (int*)game->texts[1].text_c))
		return (0);
	if (!(game->texts[2].text_v = mlx_xpm_file_to_image(game->mlx_ptr, 
		game->east_path, &game->texts[2].size_x, &game->texts[2].size_y)))
		return (0);
	if (!(game->texts[2].text_c = mlx_get_data_addr(game->texts[2].text_v, 
		&game->texts[2].bpp, &game->texts[2].sl, &game->texts[2].end)))
		return (0);
	if (!(game->texts[2].text_i = (int*)game->texts[2].text_c))
		return (0);
	return (set_text2(game));
}