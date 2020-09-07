/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:16:09 by Guillaume         #+#    #+#             */
/*   Updated: 2020/09/07 10:06:38 by grigaux          ###   ########.fr       */
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


char    *handle_line(char *line, t_map *map);
char    *free_map(t_map *map);
int     is_number(char  *num);
void    initialize_map(t_map *map);
int     map_size(char   **map);
void    free_d_p(char **to_free);
int     boundaries_checker(t_map *map, int y);
int     ft_isspace(char c);
void    exit_map(char *status, t_map *map);
int     line_checker(t_map *map, int y);

#endif