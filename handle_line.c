/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:57:52 by Guillaume         #+#    #+#             */
/*   Updated: 2020/09/07 10:22:20 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    initialize_map(t_map *map)
{
    printf("initiliazing...\n");
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
    printf("initialization ended\n");
}

char    *set_map(char *line, t_map *map)
{
    int i;
    int act_l;
    char **tmp;

    i = 0;
    act_l = 0;
    if (map->map)
    {
        while(map->map[act_l])
            act_l++;
        if (!(tmp = malloc(sizeof(char**) * (act_l + 1))))
            return(0);
        while(map->map[i])
        {
            tmp[i] = ft_strdup(map->map[i]);
            i++;
        }
        tmp[i] = 0;
        free_d_p(map->map);
        i = 0;
        if(!(map->map = malloc(sizeof(char**) * (act_l + 2))))
            return(0);
        while(tmp[i])
        {
            map->map[i] = ft_strdup(tmp[i]);
            i++;
        }
        map->map[i++] = ft_strdup(line);
        map->map[i] = 0;
        free_d_p(tmp);
        if (!(line_checker(map, i - 1)))
            exit_map("The map doesn't fit with rules1", map);
    }
    else
    {
        if(!(map->map = malloc(sizeof(char**) * 2)))
            return(0);
        map->map[i] = ft_strdup(line);
        map->map[i + 1] = 0;
        if (!boundaries_checker(map, 0))
            exit_map("The map doesn't fit with rules2", map);
    }
    return 0;
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
    else if (line[0])
    {
        printf("MAP\n"); //////////
        return (set_map(line, map));
    }
    return (0);
}