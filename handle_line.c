/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:57:52 by Guillaume         #+#    #+#             */
/*   Updated: 2020/10/22 19:08:45 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*handle_line4(char *line, t_gameinf *game)
{
	char	**tmp;

	if ('C' == line[0])
	{
		if (!(tmp = ft_split(line, ' ')) || !(tmp[1]))
			exit_struct("Error\nError with Cellar color", game);
		if (!(tmp = ft_split(tmp[1], ',')) || !(tmp[0]) ||
			!(is_number(tmp[0])) || !(tmp[1]) ||
			!(is_number(tmp[1])) || !(tmp[2]) || !(is_number(tmp[2])))
			exit_struct("Error\nError with Cellar color", game);
		else
		{
			game->ceiling_color[0] = ft_atoi(tmp[0]);
			game->ceiling_color[1] = ft_atoi(tmp[1]);
			game->ceiling_color[2] = ft_atoi(tmp[2]);
			free(tmp);
		}
	}
	else if (line[0])
		return (set_map(line, game));
	return (0);
}

char	*handle_line3(char *line, t_gameinf *game)
{
	char	**tmp;

	if ('S' == line[0])
	{
		if (!(tmp = ft_split(line, ' ')) || !(tmp[1]))
			exit_struct("Error\nError with sprite path", game);
		game->sprite_path = tmp[1];
		free(tmp);
	}
	else if ('F' == line[0])
	{
		if (!(tmp = ft_split(line, ' ')) || !(tmp[1]))
			exit_struct("Error\nError with Floor color", game);
		if (!(tmp = ft_split(tmp[1], ',')) || !(tmp[0]) || !(is_number(tmp[0]))
			|| !(tmp[1]) || !(is_number(tmp[1])) || !(tmp[2])
			|| !(is_number(tmp[2])))
			exit_struct("Error\nError with Floor color", game);
		else
		{
			game->floor_color[0] = ft_atoi(tmp[0]);
			game->floor_color[1] = ft_atoi(tmp[1]);
			game->floor_color[2] = ft_atoi(tmp[2]);
			free(tmp);
		}
	}
	else
		return (handle_line4(line, game));
	return (0);
}

char	*handle_line2(char *line, t_gameinf *game)
{
	char	**tmp;

	if (ft_strncmp("SO", line, 2) == 0)
	{
		if (!(tmp = ft_split(line, ' ')) || !(tmp[1]))
			exit_struct("Error\nError with SO path", game);
		game->south_path = tmp[1];
		free(tmp);
	}
	else if (ft_strncmp("WE", line, 2) == 0)
	{
		if (!(tmp = ft_split(line, ' ')) || !(tmp[1]))
			exit_struct("Error\nError with WE path", game);
		game->west_path = tmp[1];
		free(tmp);
	}
	else if (ft_strncmp("EA", line, 2) == 0)
	{
		if (!(tmp = ft_split(line, ' ')) || !(tmp[1]))
			exit_struct("Error\nError with EA path", game);
		game->east_path = tmp[1];
		free(tmp);
	}
	else
		return (handle_line3(line, game));
	return (0);
}

char	*handle_line(char *line, t_gameinf *game)
{
	char	**tmp;

	if ('R' == line[0])
	{
		if (!(tmp = ft_split(line, ' ')))
			exit_struct("Error\nError with resolution size", game);
		if (tmp && tmp[1] && is_number(tmp[1]) && tmp[2] && is_number(tmp[2]))
		{
			game->res_x = ft_atoi(tmp[1]);
			game->res_y = ft_atoi(tmp[2]);
		}
		else
			exit_struct("Error\nBad resolution format", game);
		free(tmp);
	}
	else if (ft_strncmp("NO", line, 2) == 0)
	{
		if (!(tmp = ft_split(line, ' ')) || !(tmp[1]))
			exit_struct("Error\nError with NO path", game);
		game->north_path = tmp[1];
		free(tmp);
	}
	else
		return (handle_line2(line, game));
	return (0);
}
