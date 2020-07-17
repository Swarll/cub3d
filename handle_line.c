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
    map->map = NULL;
}

char    *set_map(char *line, t_map *map)
{
    char *tmp;

    printf("heyhey\n");
    if (map && map->map)
    {
        printf("heyheyhey\n");
        tmp = ft_strjoin(map->map, line);
        free(map->map);
        if (!(map->map = malloc(sizeof(char) * (ft_strlen(tmp) + 2))))
            return 0;
        map->map = ft_strdup(tmp);
        map->map[ft_strlen(tmp)] = '\n';
        map->map[ft_strlen(tmp) + 1] = '\0';
    }
    else
    {
        printf("hey\n");
        if(!(map->map = malloc(sizeof(char) * (ft_strlen(line) + 2))))
            return 0;
        map->map = ft_strdup(line);
        map->map[ft_strlen(line)] = '\n';
        map->map[ft_strlen(line) + 1] = '\0';
        printf("ho\n");
    }
    printf("hoho\n");
    // printf("%s", map->map);
    return 0;

    // int i;
    // // char **tmp;

    // i = 0;
    // if (map->map)
    // {
    // //     if (!(tmp = malloc(sizeof(char *) * map_size(map->map))))
    // //         return(free_map(map));
    // //     while (map->map[i])
    // //     {
    // //         if (!(tmp[i] = malloc(sizeof(char) * ft_strlen(map->map[i]))))
    // //         {
    // //             free_d_map(tmp);
    // //             return (free_map(map));
    // //         }
    // //         tmp[i] = ft_memcpy(tmp[i], map->map[i], ft_strlen(map->map[i]));
    // //         i++;
    // //     }
    // //     free_d_map(map->map);
    // //     if (!(map->map = malloc(sizeof(char *) * (i + 1))))
    // //     {
    // //         free_d_map(tmp);
    // //         return (free_map(map));
    // //     }
    // //     i = 0;
    // //     while(tmp[i])
    // //     {
    // //         if (!(map->map[i] = malloc(sizeof(char) * ft_strlen(tmp[i]))))
    // //         {
    // //             free_d_map(tmp);
    // //             return (free_map(map));
    // //         }
    // //         map->map[i] = ft_memcpy(map->map[i], tmp[i], ft_strlen(tmp[i]));
    // //     }
    // //     free_d_map(tmp);
    // }
    // else
    // {
    //     if (!(map->map = malloc(sizeof(char**) * 2)))
    //         return (free_map(map));
    //     map->map[1] = 0;
    // }

    // if (!(map->map[i] = malloc(sizeof(char*) * (ft_strlen(line) + 1))))
    //     return (free_map(map));
    // // map->map[i] = ft_memcpy(map->map[i], line, ft_strlen(line));
    // // map->map[i][ft_strlen(line) + 1] = '\0';

    // // for (int j = 0; map->map[j]; j++)
    // // {
    // //     printf("%s\n", map->map[j]);
    // // }
    // return (0);
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