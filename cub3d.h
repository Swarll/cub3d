/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:16:09 by Guillaume         #+#    #+#             */
/*   Updated: 2020/10/09 15:58:39 by grigaux          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "./libft/libft.h"
# include "./minilibx_opengl/mlx.h"

typedef struct  s_gameinf
{    
    int         res_x;
    int         res_y;
    char        *north_path;
    char        *south_path;
    char        *west_path;
    char        *east_path;
    char        *sprite_path;
    int         floor_color[3];
    int         ceiling_color[3];
    char        **map;
    void        *mlx_ptr;
    void        *win_ptr;
    int         *img_ptr;
    int         *img;
    double      pos_y;
    double      pos_x;
    double      dir_y;
    double      dir_x;
    double      plane_x;
    double      plane_y;
    double      camera_x;
    double      ray_dir_x;
    double      ray_dir_y;
    int         square_x;
    int         square_y;
    double      side_dist_x;
    double      side_dist_y;
    double      delta_dist_x;
    double      delta_dist_y;
    double      perp_wall_dist;
    int         step_x;
    int         step_y;
    int         line_height;
    int         draw_start;
    int         draw_end;
    int         left_arr;
    int         right_arr;
    int         left;
    int         right;
    int         forward;
    int         backward;
    int         *text_n;
    int         *text_s;
    int         *text_w;
    int         *text_e;
}               t_gameinf;



char    *handle_line(char *line, t_gameinf *game);
int     free_struct(t_gameinf *game);
int     is_number(char  *num);
void    initialize_map(t_gameinf *game);
int     map_size(char   **map);
void    free_d_p(char **to_free);
int     boundaries_checker(t_gameinf *game, int y);
int     ft_isspace(char c);
int     line_checker(t_gameinf *game, int y);
int     last_line_checker(t_gameinf *game);
int     empty_line(char *line);
void    *start_ray(t_gameinf *game);
void    exit_struct(char *status, t_gameinf *game);
void    start_game(t_gameinf *game);
int    key_press_hook(int keycode, t_gameinf *game);
int     key_release_hook(int keycode, t_gameinf *game);
int     move_hook(t_gameinf *game);
int    destroy(t_gameinf *game);
int     set_text(t_gameinf *game);

#endif