/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:49:43 by grigaux           #+#    #+#             */
/*   Updated: 2020/10/15 17:28:40 by grigaux          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double  get_dist(int x, int y, t_gameinf *game)
{
    
}

void    fill_sprites(t_gameinf *game)
{
    int y;
    int x;
    int i;

    y = 0;
    x = 0;
    i = 0;
    while (game->map[y])
    {
        while (game->map[y][x])
        {
            if (game->map[y][x] == '2')
            {
                game->sprites[i].x = x;
                game->sprites[i].y = y;
                game->sprites[i].dist = get_dist(x, y, game);
                i++;
            }
            x++;
        }
        y++;
    }
}

int  count_sprites(t_gameinf *game)
{
    int y;
    int x;
    int count;

    y = 0;
    x = 0;
    count = 0;
    while (game->map[y])
    {
        while (game->map[y][x])
        {
            if (game->map[y][x] == '2')
                count++;
            x++;
        }
        y++;
    }
    return (count);
}

void set_sprites(t_gameinf *game)
{
    if (!(game->sprites = malloc(sizeof(t_sprite) * count_sprites(game))))
        exit_struct("Problem during malloc of count_sprites", game);
    fill_sprites(game);
}