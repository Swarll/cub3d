/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: becentrale <becentrale@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 14:52:35 by becentrale        #+#    #+#             */
/*   Updated: 2020/07/23 15:55:21 by becentrale       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     only_one_checker(t_map *map, int y)
{
    int x;

    x = 0;
    while(map->map[y][x])
    {
        if (map->map[y][x] != '1' && !ft_isspace(map->map[y][x]))
            return (0);
        x++;
    }
    return 1;
}

void    exit_map(char *status, t_map *map)
{
    free_map(map);
    exit(write(2, status, ft_strlen(status)));
}
