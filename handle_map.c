/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:56:25 by grigaux           #+#    #+#             */
/*   Updated: 2020/10/22 18:57:04 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char    *set_map(char *line, t_gameinf *game)
{
	int i;
	int act_l;
	char **tmp;

	i = 0;
	act_l = 0;
	if (game->map)
	{
		while(game->map[act_l])
			act_l++;
		if (!(tmp = malloc(sizeof(char**) * (act_l + 1))))
			return (0);
		while(game->map[i])
		{
			tmp[i] = ft_strdup(game->map[i]);
			i++;
		}
		tmp[i] = 0;
		free_d_p(game->map);
		i = 0;
		if(!(game->map = malloc(sizeof(char**) * (act_l + 2))))
			return(0);
		while(tmp[i])
		{
			game->map[i] = ft_strdup(tmp[i]);
			i++;
		}
		game->map[i++] = ft_strdup(line);
		game->map[i] = 0;
		free_d_p(tmp);
		if (!(line_checker(game, i - 1)))
			exit_struct("Error\nThe map doesn't fit with rules inside the map", game);
	}
	else
	{
		if(!(game->map = malloc(sizeof(char**) * 2)))
			return(0);
		game->map[i] = ft_strdup(line);
		game->map[i + 1] = 0;
		if (!boundaries_checker(game, 0))
			exit_struct("Error\nThe map doesn't fit with rules on the boundaries", game);
	}
	return 0;
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
				game->pos_y = i + 0.5;
				game->pos_x = j + 0.5;
				if (act == 'E')
				{
					game->dir_x = 1;
					game->plane_y = 0.66;
				}
				else if (act == 'W')
				{
					game->dir_x = -1;
					game->plane_y = -0.66;
				}
				else if (act == 'S')
				{
					game->dir_y = 1;
					game->plane_x = -0.66;
				}
				else if (act == 'N')
				{
					game->dir_y = -1;
					game->plane_x = 0.66;
				}
				
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
