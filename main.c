/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:14:03 by Guillaume         #+#    #+#             */
/*   Updated: 2020/10/27 16:01:26 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*gnl(t_gameinf *game, int fd)
{
	int		i;
	char	*line;

	while ((i = get_next_line(fd, &line)) > 0)
	{
		if (line)
		{
			handle_line(line, game);
			line = 0;
			free(line);
		}
	}
	return (line);
}

void	*start_ray(t_gameinf *game)
{
	if (!(game->mlx_ptr = mlx_init()))
		return (0);
	if (!(seek_spawn(game)))
		exit_struct("Error\nSpawn not found into map", game);
	if (!(set_text(game)))
		exit_struct("Error\nError while loading textures", game);
	set_sprites(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->res_x,
		game->res_y, "cub");
	start_algo(game);
	set_loops(game);
	return (0);
}

void	handle_dot_cub(char *argv, t_gameinf *game)
{
	int		fd;
	char	*line;
	char	**tmp;

	line = 0;
	tmp = ft_split(argv, '.');
	if (!(fd = open(argv, O_RDONLY)) || !(tmp[1]) ||
		ft_strncmp("cub", tmp[1], 3) != 0)
		exit_struct("Error\nNot valid file", game);
	line = gnl(game, fd);
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

int		main(int argc, char *argv[])
{
	t_gameinf	*game;

	if (((argc == 3 && ft_strncmp(argv[2], "--save", 7) == 0) || (argc == 2))
		&& argv[0] != 0)
	{
		if (!(game = malloc(sizeof(t_gameinf))))
			return (0);
		init_map(game);
		handle_dot_cub(argv[1], game);
		if (!(start_ray(game)))
			return (0);
		if (argc == 3)
			start_bmp(game);
		else
		free_struct(game);
	}
	else
		exit(write(0, "Error\nWrong input", 17));
	return (0);
}
