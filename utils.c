/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becentrale <becentrale@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:58:52 by Guillaume         #+#    #+#             */
/*   Updated: 2020/07/23 15:54:20 by becentrale       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char    *free_map(t_map *map)
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
    return ("Error\n");
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
        if (num[i] >= 30 && num[i] <= 39)
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