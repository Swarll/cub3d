/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigaux <grigaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:49:43 by grigaux           #+#    #+#             */
/*   Updated: 2020/10/27 15:16:39 by grigaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_dist(t_gameinf *game, t_sprite sprite)
{
	return ((game->pos_x - sprite.x) * (game->pos_x - sprite.x) +
		(game->pos_y - sprite.y) * (game->pos_y - sprite.y));
}

void	sort_sprites(t_gameinf *game, int count)
{
	int			i;
	int			j;
	int			swapped;
	t_sprite	tmp;

	i = 0;
	j = 1;
	swapped = 1;
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
}

void	update_sprites(t_gameinf *game, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		game->sprites[i].dist = get_dist(game, game->sprites[i]);
		i++;
	}
	sort_sprites(game, count);
}

int		count_sprites(t_gameinf *game)
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

void	fill_sprites(t_gameinf *game)
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
				game->sprites[i].x = x + 0.5;
				game->sprites[i].y = y + 0.5;
				game->sprites[i].dist = get_dist(game, game->sprites[i]);
				i++;
			}
			x++;
		}
		y++;
	}
}

void	set_sprites(t_gameinf *game)
{
	int count;

	count = count_sprites(game);
	if (!(game->sprites = malloc(sizeof(t_sprite) * count)))
		exit_struct("Problem during malloc of count_sprites", game);
	fill_sprites(game);
	sort_sprites(game, count);
	// for(int i = 0; i < count; i++)
	// {
	// 	printf("DIST %i : %f\n", i, game->sprites[i].dist);
	// }
}
