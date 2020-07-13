/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:16:09 by Guillaume         #+#    #+#             */
/*   Updated: 2020/07/01 11:24:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./libft/get_next_line/get_next_line.h"
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
    char        *floor_color;
    char        *ceiling_color;
    char        **map;    
}               t_map;


int     handle_line(char *line, t_map *map);
int     free_map(t_map *map);
#endif