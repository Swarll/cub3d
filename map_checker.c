/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 14:52:35 by becentrale        #+#    #+#             */
/*   Updated: 2020/10/08 16:15:30 by grigaux          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     boundaries_checker(t_gameinf *game, int y)
{
    int x;

    x = 0;
    while(game->map[y] && game->map[y][x])
    {
        if (game->map[y][x] != '1' && !ft_isspace(game->map[y][x]))
            return (0);
        x++;
    }
    return 1;
}

int     past_line_checker(t_gameinf *game, int y)
{
    int x;

    x = 0;
    while (game->map[y-1][x])
    {
        if (game->map[y-1][x] == '0' && !(game->map[y][x] || ft_isspace(game->map[y][x])))
            return (0);
        x++;
    }
    return (1);
}

int     line_checker(t_gameinf *game, int y)
{
    int x;
    char last_c;

    x = 0;
    while (game->map[y][x])
    {
        if (ft_isspace(game->map[y][x]) && game->map[y][x - 1] && game->map[y][x - 1] == '0')
            return (0);
        if (!ft_isspace(game->map[y][x]))
            last_c = game->map[y][x];
        if (game->map[y][x] == '0' && (x == 0 || !(game->map[y-1][x] || 
            ft_isspace(game->map[y][x-1]) || ft_isspace(game->map[y-1][x]))))
            return (0);
        x++;
    }
    if (last_c != '1')
        return (0);
    if (y > 0)
        return (past_line_checker(game, y));
    return (1);
}

int     last_line_checker(t_gameinf *game)
{
    int y;

    y = 0;
    while (game->map && game->map[y])
        y++;
    return (boundaries_checker(game, y-1));    
}

void    exit_struct(char *status, t_gameinf *game)
{
    free_struct(game);
    exit(write(2, status, ft_strlen(status)));
}
