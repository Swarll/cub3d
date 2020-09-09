/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:14:03 by Guillaume         #+#    #+#             */
/*   Updated: 2020/09/09 15:58:38 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    handle_dot_cub(char *argv, t_map *map)
{
    int fd;
    int i;
	char *line;
    char **tmp;

    tmp = ft_split(argv, '.');
    if (!(fd = open(argv, O_RDONLY)) || !(tmp[1]) || ft_strncmp("cub", tmp[1], 3) != 0)
        exit_map("Error\nNot valid file", map);
    initialize_map(map);
    while ((i = get_next_line(fd, &line)) > 0) 
    {
        if (line)
        {
            handle_line(line, map);
            line = 0;
            free(line);
        }
    }        
    if (line)
    {
        handle_line(line, map);
        line = 0;
        free(line);
        if (!(last_line_checker(map)))
            exit_map("Error\nLast line is incorrect", map);
    }
    free(tmp);
    close(fd);
}

int main(int argc, char *argv[])
{
    // void    *mlx_ptr;
    // void    *win_ptr;
    t_map   *map;

    if (argc == 2 && argv[0] != 0)
    {
        if (!(map = malloc(sizeof(t_map *))))
            return (0);
        handle_dot_cub(argv[1], map);
        // mlx_ptr = mlx_init();
        // win_ptr = mlx_new_window(mlx_ptr, 1200, 800, "Test");

        // mlx_loop(win_ptr);
        if (map)
            free_map(map);
    }
    return(0);
}