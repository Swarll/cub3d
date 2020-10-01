/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:21:34 by grigaux           #+#    #+#             */
/*   Updated: 2020/10/01 19:26:05 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    draw_line(int x, t_map *map, t_gameinf *game)
{
    int y = 0;

    while (y < game->draw_start)
        mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y++, 0xFFFFFF);
    while (y < game->draw_end)
        mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y++, 0xFF0000);
    while (y < map->res_y)
        mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y++, 0x0000FF);

}

int    dda_calc(t_map *map, t_gameinf *game)
{
    int hit;
    int side;

    hit = 0;
    while (!hit)
    {
        if (game->side_dist_x < game->side_dist_y)
        {
            game->side_dist_x += game->delta_dist_x;
            game->square_x += game->step_x;
            side = 0;
        }
        else
        {
            game->side_dist_y += game->delta_dist_y;
            game->square_y += game->step_y;
            side = 1;
        }
        if (map->map[game->square_y][game->square_x] == '1')
            hit = 1;
    }
    return (side);
}

void    basis_calc2(t_map *map, t_gameinf *game, int side)
{
    if (side == 0)
        game->perp_wall_dist = (game->square_x - game->pos_x + (1 - game->step_x) / 2) / game->ray_dir_x;
    else
        game->perp_wall_dist = (game->square_y - game->pos_y + (1 - game->step_y) / 2) / game->ray_dir_y;
    game->line_height = (int)(map->res_y / game->perp_wall_dist);
    game->draw_start = (game->line_height * (-1)) / 2 + map->res_y / 2;
    if (game->draw_start < 0)
        game->draw_end = game->line_height / 2 + map->res_y / 2;
    if (game->draw_end >= map->res_y)
        game->draw_end = map->res_y - 1;
}

void    basis_calc1(int x, t_map *map, t_gameinf *game)
{
    game->camera_x = 2 * x / (double)map->res_x - 1;
    game->ray_dir_x = game->dir_x + game->plane_x * game->camera_x;
    game->ray_dir_y = game->dir_y + game->plane_y * game->camera_x;
    game->square_x = (int)game->pos_x;
    game->square_y = (int)game->pos_y;
    game->delta_dist_x = fabs(1 / game->ray_dir_x);
    game->delta_dist_y = fabs(1 / game->ray_dir_y);
    if (game->ray_dir_x < 0)
    {
        game->step_x = -1;
        game->side_dist_x = (game->pos_x - game->square_x) * game->delta_dist_x;
    }
    else
    {
        game->step_x = 1;
        game->side_dist_x = (game->square_x + 1.0 - game->pos_x) * game->delta_dist_x;
    }
    if (game->ray_dir_y < 0)
    {
        game->step_y = -1;
        game->side_dist_y = (game->pos_y - game->square_y) * game->delta_dist_y;
    }
    else
    {
        game->step_y = 1;
        game->side_dist_y = (game->square_y + 1.0 - game->pos_y) * game->delta_dist_y;
    }
}

void    start_game(t_gameinf *game, t_map *map)
{
    int x;

    x = 0;
    while (x < map->res_x)
    {
        basis_calc1(x, map, game);
        basis_calc2(map, game, dda_calc(map, game));
        draw_line(x, map, game);
        x++;
    }
}