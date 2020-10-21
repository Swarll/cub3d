/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:57:52 by Guillaume         #+#    #+#             */
/*   Updated: 2020/10/21 14:30:12 by grigaux          ###   ########.fr       */
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

char	*handle_line4(char *line, t_gameinf *game)
{
	char	**tmp;
	
	if ('C' == line[0])
	{
		
		if (!(tmp = ft_split(line, ' ')) || !(tmp[1]))
			exit_struct("Error\nError with Cellar color", game);
		if (!(tmp = ft_split(tmp[1], ',')) || !(tmp[0]) || !(is_number(tmp[0])) || !(tmp[1]) ||
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
		if (!(tmp = ft_split(tmp[1], ',')) || !(tmp[0]) || !(is_number(tmp[0])) || !(tmp[1]) ||
			!(is_number(tmp[1])) || !(tmp[2]) || !(is_number(tmp[2])))
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

char    *handle_line(char *line, t_gameinf *game) 
{
	char    **tmp;
	
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