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
    map->floor_color[0] = 0;
    map->floor_color[1] = 0;
    map->floor_color[2] = 0;
    map->ceiling_color[0] = 0;
    map->ceiling_color[1] = 0;
    map->ceiling_color[2] = 0;
    map->map = 0;
}

char    *set_map(char *line, t_map *map)
{
    int i;
    char **tmp;

    i = 0;
    if (map->map)
    {
        if (!(tmp = malloc(sizeof(char *) * map_size(map->map))))
            return(0);
        while (map->map[i])
        {
            ft_memcpy(tmp[i], map->map[i], ft_strlen(map->map[i]));
            i++;
        }
        free_d_map(map->map);
        if (!(map->map = malloc(sizeof(char *) * (i + 1))))
            return(0);
        i = 0;
        while(tmp[i])
        {
            if (!(map->map[i] = malloc(sizeof(char) * ft_strlen(tmp[i]))))
                return (0);
            ft_memcpy(map->map[i], tmp[i], ft_strlen(tmp[i]));
        }
        free_d_map(tmp);
    }
    else
    {
        if (!(map->map = malloc(sizeof(char *) * 1)))
            return(0);
    }
    if (!(map->map[i] = malloc(sizeof(char) * ft_strlen(line))))
        return (0);
    ft_memcpy(map->map[i], line, ft_strlen(line));
    return (0);
}

char    *handle_line(char *line, t_map *map) 
{
    char    **tmp;
    
    if ('R' == line[0])
    {
        printf("R\n"); //////////
        if (!(tmp = ft_split(line, ' ')))
            return (free_map(map));
        if (tmp && tmp[1] && is_number(tmp[1]) && tmp[2] && is_number(tmp[2]))
        {
            map->res_x = ft_atoi(tmp[1]);
            map->res_y = ft_atoi(tmp[2]);
        }
        else
            return (free_map(map));
        free(tmp);
    }
    else if (ft_strncmp("NO", line, 2) == 0)
    {
        printf("NO\n"); //////////
        if (!(tmp = ft_split(line, ' ')) || !(tmp[1]))
            return (free_map(map));
        map->north_path = tmp[1];
        free(tmp);
    }
    else if (ft_strncmp("SO", line, 2) == 0)
    {
        printf("SO\n"); //////////
        if (!(tmp = ft_split(line, ' ')) || !(tmp[1]))
            return (free_map(map));
        map->south_path = tmp[1];
        free(tmp);
    }
    else if (ft_strncmp("WE", line, 2) == 0)
    {
        printf("WE\n"); //////////
        if (!(tmp = ft_split(line, ' ')) || !(tmp[1]))
            return (free_map(map));
        map->west_path = tmp[1];
        free(tmp);
    }
    else if (ft_strncmp("EA", line, 2) == 0)
    {
        printf("EA\n"); //////////
        if (!(tmp = ft_split(line, ' ')) || !(tmp[1]))
            return (free_map(map));
        map->east_path = tmp[1];
        free(tmp);
    }
    else if ('S' == line[0])
    {
        printf("S\n"); //////////
        if (!(tmp = ft_split(line, ' ')) || !(tmp[1]))
            return (free_map(map));
        map->sprite_path = tmp[1];
        free(tmp);
    }
    else if ('F' == line[0])
    {
        printf("F\n"); //////////
        if (!(tmp = ft_split(line, ' ')) || !(tmp[1]))
            return (free_map(map));
        if (tmp)
            free(tmp);
        if (!(tmp = ft_split(line, ',')) || !(tmp[0]) || !(is_number(tmp[0])) || !(tmp[1]) ||
            !(is_number(tmp[1])) || !(tmp[2]) || !(is_number(tmp[3])))
            return (free_map(map));
        else
        {
            map->floor_color[0] = ft_atoi(tmp[0]);
            map->floor_color[1] = ft_atoi(tmp[1]);
            map->floor_color[2] = ft_atoi(tmp[2]);
            free(tmp);
        }
    }
    else if ('C' == line[0])
    {
        printf("C\n"); //////////
        if (!(tmp = ft_split(line, ' ')) || !(tmp[1]))
            return (0);
        if (tmp)
            free(tmp);
        if (!(tmp = ft_split(line, ',')) || !(tmp[0]) || !(is_number(tmp[0])) || !(tmp[1]) ||
            !(is_number(tmp[1])) || !(tmp[2]) || !(is_number(tmp[3])))
            return (0);
        else
        {
            map->ceiling_color[0] = ft_atoi(tmp[0]);
            map->ceiling_color[1] = ft_atoi(tmp[1]);
            map->ceiling_color[2] = ft_atoi(tmp[2]);
            free(tmp);
        }
    }
    else
    {
        printf("MAP\n"); //////////
        return (set_map(line, map));
    }
    return (0);
}