/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:58:52 by Guillaume         #+#    #+#             */
/*   Updated: 2020/10/06 10:25:34 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     free_struct(t_gameinf *game)////////completer?
{
    if (game)
    {
        if (game->north_path) 
        {
            game->north_path = 0;
            free(game->north_path);
        }
        if (game->south_path)
        {
            game->south_path = 0;
            free(game->south_path);
        }
        if (game->east_path)
        {
            game->east_path = 0;
            free(game->east_path);
        }
        if (game->west_path)
        {
            game->west_path = 0;
            free(game->west_path);
        }
        if (game->sprite_path)
        {
            game->sprite_path = 0;
            free(game->sprite_path);
        }
        if (game->map)
            free_d_p(game->map);
        game = 0;
        free(game);
    }
    return (1);
}

void    free_d_p(char **to_free)
{
    int i;

    i = 0;
    while (to_free[i])
    {
        to_free[i] = 0;
        free(to_free[i]);
        i++;
    }
    to_free = 0;
    free(to_free);
}

int     map_size(char   **map)
{
    int i;

    i = 0;
    while (map[i])
        i++;
    return (i);
}

int     is_number(char  *num)
{
    int i;

    i = 0;
    while (num[i])
    {
        if (num[i] < 48 || num[i] > 57)
            return (0);
        i++;
    }
    return (1);
}

int     ft_isspace(char c)
{
    if (c != ' ' && c != '\t' && c != '\n' 
        && c != '\r' && c != 'v' && c != 'f')
        return 0;
    return 1;
}

int     empty_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
        if (ft_isspace(line[i]))
            i++;
        else
            return (1);
    return (0);
}