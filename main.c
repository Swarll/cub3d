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
	char *line = 0;
    
    if (!(fd = open(argv, O_RDONLY)))
        return("Error\nNot valid file");
    while ((i = get_next_line(fd, &line)) > 0) 
    {
        handle_line(line, map);
    }
    free(line);
    close(fd);
    return (0);
}

int main(int argc, char *argv[])
{   
    void    *mlx_ptr;
    void    *win_ptr;
    t_map   *map;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 1200, 800, "Test");

    mlx_loop(win_ptr);

    if (argc == 1 && argv[0] != 0)
    {
        if (!(map = malloc(sizeof(struct s_map))))
            return (0);
        handle_dot_cub(argv[0], map);
    }
    return(0);
}