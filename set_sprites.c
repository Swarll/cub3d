/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:49:43 by grigaux           #+#    #+#             */
/*   Updated: 2020/10/20 14:59:14 by grigaux          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double  get_dist(t_gameinf *game, t_sprite sprite)
{
    return ((game->pos_x - sprite.x ) * (game->pos_x - sprite.x) +
        (game->pos_y - sprite.y) * (game->pos_y - sprite.y));
}

void    update_sprites(t_gameinf *game, int count)
{
    int i;

    i = 0;
    while (i < count)
    {
        game->sprites[i].dist = get_dist(game, game->sprites[i]);
        i++;
    }
}

void    sort_sprites(t_gameinf *game, int count)
{
    int i;
    int j;
    int swapped;
    t_sprite tmp;

    i = 0;
    j = 1;
    swapped = 1;
    update_sprites(game, count);
    while (i < count && swapped == 1)
    {
        swapped = 0;
        j = i + 1;
        while (j < count)
        {
            if (game->sprites[i].dist < game->sprites[j].dist)
            {
                tmp = game->sprites[i];
                game->sprites[i] = game->sprites[j];
                game->sprites[j] = tmp;
                swapped = 1;
            }
            j++;
        }
        i++;
    }
    // printf("SORTED:\n");
    // for (int i = 0; i < count; i++)
    //     printf("%f\n", game->sprites[i].dist);
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
        x = 0;
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
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == '2')
            {
                game->sprites[i].x = x;
                game->sprites[i].y = y;
                game->sprites[i].dist = get_dist(game, game->sprites[i]);
                i++;
            }
            x++;
        }
        y++;
    }
    // printf("UNSORTED:\n");
    // for (int i = 0; i < count_sprites(game); i++)
    //     printf("%f\n", game->sprites[i].dist);
}


void set_sprites(t_gameinf *game)
{
    int count;

    count = count_sprites(game);
    if (!(game->sprites = malloc(sizeof(t_sprite) * count)))
        exit_struct("Problem during malloc of count_sprites", game);
    fill_sprites(game);
    sort_sprites(game, count);
}