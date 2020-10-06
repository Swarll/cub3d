/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:14:03 by Guillaume         #+#    #+#             */
/*   Updated: 2020/10/06 10:31:19 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    handle_dot_cub(char *argv, t_gameinf *game)
{
    int fd;
    int i;
	char *line;
    char **tmp;

    tmp = ft_split(argv, '.');
    if (!(fd = open(argv, O_RDONLY)) || !(tmp[1]) || ft_strncmp("cub", tmp[1], 3) != 0)
        exit_struct("Error\nNot valid file", game);
    initialize_map(game);
    while ((i = get_next_line(fd, &line)) > 0) 
    {
        if (line)
        {
            handle_line(line, game);
            line = 0;
            free(line);
        }
    }        
    if (line)
    {
        handle_line(line, game);
        line = 0;
        free(line);
        if (!(last_line_checker(game)))
            exit_struct("Error\nLast line is incorrect", game);
    }
    free(tmp);
    close(fd);
}

int main(int argc, char *argv[])
{
    t_gameinf   *game;

    if (argc == 2 && argv[0] != 0)
    {
        if (!(game = malloc(sizeof(t_gameinf))))
            return (0);
        handle_dot_cub(argv[1], game);
        if (!(start_ray(game)))
            return (0);
        if (game)
            free_struct(game);
    }
    return(0);
}