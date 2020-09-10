/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:16:09 by Guillaume         #+#    #+#             */
/*   Updated: 2020/09/10 16:33:12 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./minilibx_opengl/mlx.h"

typedef struct  s_map 
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
}               t_map;

typedef struct  s_gameinf
{
    void        *mlx_ptr;
    void        *win_ptr;
    int         spawn_y;
    int         spawn_x;
    char        spawn_dir;
}               t_gameinf;



char    *handle_line(char *line, t_map *map);
int     free_map(t_map *map);
int     free_game(t_gameinf *game);
int     is_number(char  *num);
void    initialize_map(t_map *map);
int     map_size(char   **map);
void    free_d_p(char **to_free);
int     boundaries_checker(t_map *map, int y);
int     ft_isspace(char c);
void    exit_map(char *status, t_map *map);
int     line_checker(t_map *map, int y);
int     last_line_checker(t_map *map);
int     empty_line(char *line);
void    *start_ray(t_map *map);
void    exit_all(t_map *map, t_gameinf *game, char *status);

#endif