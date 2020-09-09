/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 14:52:35 by becentrale        #+#    #+#             */
/*   Updated: 2020/09/09 15:58:03 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     boundaries_checker(t_map *map, int y)
{
    int x;

    x = 0;
    while(map->map[y] && map->map[y][x])
    {
        if (map->map[y][x] != '1' && !ft_isspace(map->map[y][x]))
            return (0);
        x++;
    }
    return 1;
}

int     past_line_checker(t_map *map, int y)
{
    int x;

    x = 0;
    while (map->map[y-1][x])
    {
        if (map->map[y-1][x] == '0' && !(map->map[y][x] || ft_isspace(map->map[y][x])))
            return (0);
        x++;
    }
    return (1);
}

int     line_checker(t_map *map, int y)
{
    int x;
    char last_c;

    x = 0;
    while (map->map[y][x])
    {
        if (!ft_isspace(map->map[y][x]))
            last_c = map->map[y][x];
        if (map->map[y][x] == '0' && (x == 0 || !(map->map[y-1][x] || 
            ft_isspace(map->map[y][x-1]) || ft_isspace(map->map[y-1][x]))))
            return (0);
        x++;
    }
    if (last_c != '1')
        return (0);
    if (y > 0)
        return (past_line_checker(map, y));
    return (1);
}

int     last_line_checker(t_map *map)
{
    int y;

    y = 0;
    while (map->map && map->map[y])
        y++;
    return (boundaries_checker(map, y-1));    
}

void    exit_map(char *status, t_map *map)
{
    free_map(map);
    exit(write(2, status, ft_strlen(status)));
}
