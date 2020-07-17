/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:14:03 by Guillaume         #+#    #+#             */
/*   Updated: 2020/07/01 11:21:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char *handle_dot_cub(char *argv, t_map *map)
{
    int fd;
    int i;
	char *line;
    char **tmp;

    tmp = ft_split(argv, '.');
    if (!(fd = open(argv, O_RDONLY)) || !(tmp[1]) || ft_strncmp("cub", tmp[1], 3) != 0)
        return("Error\nNot valid file");
    initialize_map(map);
    while ((i = get_next_line(fd, &line)) > 0) 
    {
        if (line && line[0])
        {
            printf("%s\n", line);
            handle_line(line, map);
            line = 0;
            free(line);
        }
    }
    free(tmp);
    close(fd);
    return (0);
}

int main(int argc, char *argv[])
{
    char    *res;
    // void    *mlx_ptr;
    // void    *win_ptr;
    t_map   *map;

    if (argc == 2 && argv[0] != 0)
    {
        printf("ARGC ARGV GOOD\n");////////
        if (!(map = malloc(sizeof(struct s_map))))
            return (0);
        res = handle_dot_cub(argv[1], map);
        if (map)
            free_map(map);
            
        // mlx_ptr = mlx_init();
        // win_ptr = mlx_new_window(mlx_ptr, 1200, 800, "Test");

        // mlx_loop(win_ptr);

    }
    return(0);
}