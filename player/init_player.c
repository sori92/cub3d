/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:39:33 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/30 15:21:35 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	find_player(char **matrix, t_cub *game, size_t y, size_t x)
{
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x] && matrix[y][x] != 'N' && matrix[y][x] != 'S'
				&& matrix[y][x] != 'W' && matrix[y][x] != 'E')
			x++;
		if (matrix[y][x])
		{
			game->plyr.y = y;
			game->plyr.x = x;
			return (matrix[y][x]);
		}
		y++;
	}
	return ('\0');
}

void	asign_direction(char dir, t_cub *game)
{
	if (dir == 'N')
	{
		game->plyr.dir_x = 0;
		game->plyr.dir_y = -1;
	}
	if (dir == 'S')
	{
		game->plyr.dir_x = 0;
		game->plyr.dir_y = 1;
	}
	if (dir == 'E')
	{
		game->plyr.dir_x = 1;
		game->plyr.dir_y = 0;
	}
	if (dir == 'W')
	{
		game->plyr.dir_x = -1;
		game->plyr.dir_y = 0;
	}
}

void	init_player(t_cub *game)
{
	char	dir;

	dir = find_player(game->map.matrix, game, 0, 0);
	game->plyr.pos_x = game->plyr.x + 0.5;
	game->plyr.pos_y = game->plyr.y + 0.5;
	asign_direction(dir, game);
}
