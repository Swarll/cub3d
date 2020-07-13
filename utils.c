/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillaume <Guillaume@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:58:52 by Guillaume         #+#    #+#             */
/*   Updated: 2020/06/25 17:36:45 by Guillaume        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char    *free_map(t_map *map)
{
    if (map != NULL)
    {
        if (map->north_path != NULL)
            free(map->north_path);
        if (map->south_path != NULL)
            free(map->south_path);
        if (map->east_path != NULL)
            free(map->east_path);
        if (map->west_path != NULL)
            free(map->west_path);
        if (map->sprite_path != NULL)
            free(map->sprite_path);
        if (map->map != NULL)
            free(map->map);
        free(map);
    }
    return ("Error\n");
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