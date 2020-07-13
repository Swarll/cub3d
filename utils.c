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

int     free_map(t_map *map)
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
        if (map->floor_color != NULL)
            free(map->floor_color);
        if (map->ceiling_color != NULL)
            free(map->ceiling_color);
        if (map->map != NULL)
            free(map->map);
        free(map);
    }
    return (-1);
}