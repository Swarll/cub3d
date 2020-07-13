/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:57:52 by Guillaume         #+#    #+#             */
/*   Updated: 2020/07/01 11:39:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    initialize_map(t_map *map)
{
    map->res_x = 0;
    map->res_y = 0;
    map->north_path = 0;
    map->south_path = 0;
    map->west_path = 0;
    map->east_path = 0;
    map->sprite_path = 0;
    map->floor_color = 0;
    map->ceiling_color = 0;
    map->map = 0;
}

int    set_map(char *line, t_map *map)
{
    int len;
    int i;

    i = 0;
    while (map->map[i] != NULL)
        i++;
    len = ft_strlen(line);
    if (!(map->map[i] = malloc(sizeof(char) * len)))
        return (free_map(map));
    map->map[i] = line;
    return (1);
}

int    handle_line(char *line, t_map *map) 
{
    char    **tmp;
    
    initialize_map(map);
    if ('R' == line[0])
    {
        tmp = ft_split(line, ' ');
        map->res_x = ft_atoi(tmp[1]);
        map->res_y = ft_atoi(tmp[2]);
        free(tmp);
    }
    else if (ft_strncmp("NO", line, 2) == 0)
    {
        if (!(tmp = ft_split(line, ' ')))
            return (free_map(map));
        map->north_path = tmp[1];
    }
    else if (ft_strncmp("SO", line, 2) == 0)
    {
        if (!(tmp = ft_split(line, ' ')))
            return (free_map(map));
        map->south_path = tmp[1];
    }
    else if (ft_strncmp("WE", line, 2) == 0)
    {
        if (!(tmp = ft_split(line, ' ')))
            return (free_map(map));
        map->west_path = tmp[1];
    }
    else if (ft_strncmp("EA", line, 2) == 0)
    {
        if (!(tmp = ft_split(line, ' ')))
            return (free_map(map));
        map->east_path = tmp[1];
    }
    else if ('S' == line[0])
    {
        if (!(tmp = ft_split(line, ' ')))
            return (free_map(map));
        map->sprite_path = tmp[1];
    }
    else if ('F' == line[0])
    {
        if (!(tmp = ft_split(line, ' ')))
            return (free_map(map));
        map->floor_color = tmp[1];
    }
    else if ('C' == line[0])
    {
        if (!(tmp = ft_split(line, ' ')))
            return (free_map(map));
        map->ceiling_color = tmp[1];
    }
    else
    {
        return (set_map(line, map));
    }
    return (1);
}