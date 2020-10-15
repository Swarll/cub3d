/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 16:21:34 by grigaux           #+#    #+#             */
/*   Updated: 2020/10/15 15:51:07 by grigaux          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_text seek_text(t_gameinf *game, int side)
{
    if (side == 0)
    {
        if (game->ray_dir_x > 0)
            return (game->texts[2]);
        else
            return (game->texts[3]);
    }
    else
    {
        if (game->ray_dir_y > 0)
            return (game->texts[1]);
        else
            return (game->texts[0]);
    }
    
}

int    draw_text(t_gameinf *game, int x, int y, int side)
{
    double wall_x;
    int text_x;
    double step;
    double text_pos;
    int text_y;
    t_text text;

    text = seek_text(game, side);
    if (side == 0)
        wall_x = game->pos_y + game->perp_wall_dist * game->ray_dir_y;
    else
        wall_x = game->pos_x + game->perp_wall_dist * game->ray_dir_x;
    wall_x -= floor((wall_x));
    text_x = (int)(wall_x * (double)text.size_x);
    if (side == 0 && game->ray_dir_x > 0)
        text_x = text.size_x - text_x - 1;
    if (side == 1 && game->ray_dir_y < 0)
        text_x = text.size_x - text_x - 1;
    step = 1.0 * text.size_y / game->line_height;
    text_pos = (game->draw_start - game->res_y / 2 + game->line_height / 2) * step;
    while (y < game->draw_end)
    {
        text_y = (int)text_pos & (text.size_y - 1);
        text_pos += step;
        game->img[x + y++ * game->res_x] = text.text_i[text.size_y * text_y + text_x];
    }
    return (y);
    
}

void    draw_line(int x, t_gameinf *game, int side)
{
    int y;
    int a;
    
    if (!game->img_ptr)
        game->img_ptr = mlx_new_image(game->mlx_ptr, game->res_x, game->res_y);
    game->img = (int*)mlx_get_data_addr(game->img_ptr, &a, &a, &a);
    y = 0;
    while (y < game->draw_start)
    {
        game->img[x + y++ * game->res_x] = 0x00F000; ////////changer avec couleurs du .cub
    }
    if (y < game->draw_end)
    {
        y = draw_text(game, x, y, side);
    }
    while (y < game->res_y)
    {
        game->img[x + y++ * game->res_x] = 0x0000FF; ////////changer avec couleurs du .cub
    }
}

int    dda_calc(t_gameinf *game)
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
        if (game->map[game->square_y][game->square_x] == '1')
            hit = 1;
    }
    return (side);
}

void    basis_calc2(t_gameinf *game, int side)
{
    if (side == 0)
        game->perp_wall_dist = (game->square_x - game->pos_x + (1 - game->step_x) / 2) / game->ray_dir_x;
    else
        game->perp_wall_dist = (game->square_y - game->pos_y + (1 - game->step_y) / 2) / game->ray_dir_y;
    game->line_height = (int)(game->res_y / game->perp_wall_dist);
    game->draw_start = (game->line_height * (-1)) / 2 + game->res_y / 2;
    if (game->draw_start < 0)
        game->draw_start = 0;
    game->draw_end = game->line_height / 2 + game->res_y / 2;
    if (game->draw_end >= game->res_y)
        game->draw_end = game->res_y - 1;
}

void    basis_calc1(int x, t_gameinf *game)
{
    game->camera_x = 2 * x / (double)game->res_x - 1;
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

void    start_game(t_gameinf *game)
{
    int x;
    int side;

    x = 0;
    while (x < game->res_x)
    {
        basis_calc1(x, game);
        side = dda_calc(game);
        basis_calc2(game, side);
        draw_line(x, game, side);
        x++;
    }
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->img_ptr, 0, 0);
}