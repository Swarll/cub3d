/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:58:52 by Guillaume         #+#    #+#             */
/*   Updated: 2020/09/10 16:21:18 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     free_map(t_map *map)////////completer?
{
    if (map)
    {
        if (map->north_path) 
        {
            map->north_path = 0;
            free(map->north_path);
        }
        if (map->south_path)
        {
            map->south_path = 0;
            free(map->south_path);
        }
        if (map->east_path)
        {
            map->east_path = 0;
            free(map->east_path);
        }
        if (map->west_path)
        {
            map->west_path = 0;
            free(map->west_path);
        }
        if (map->sprite_path)
        {
            map->sprite_path = 0;
            free(map->sprite_path);
        }
        if (map->map)
            free_d_p(map->map);
        map = 0;
        free(map);
    }
    return (1);
}

int     free_game(t_gameinf *game)
{
    if (game)
    {
        if (game->mlx_ptr)
        {
            game->mlx_ptr = 0;
            free(game->mlx_ptr);
        }
        if (game->win_ptr)
        {
            game->win_ptr = 0;
            free(game->win_ptr);
        }
        game = 0;
        free(game);
    }
    return (1);
}

void    exit_all(t_map *map, t_gameinf *game, char *status)
{
    free_game(game);
    exit_map(status, map);
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