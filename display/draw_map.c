/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:38:00 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/06/17 19:39:37 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_cell(t_cub *game, size_t y, size_t x, int color)
{
	size_t	i;
	size_t	j;
	size_t	cell;

	cell = 10;
	j = 0;
	while (j < cell - 1)
	{
		i = 0;
		while (i < cell - 1)
		{
			pixel_put(x * cell + i, y * cell + j, color, game);
			i++;
		}
		j++;
	}
}

void	draw_back(t_cub *game, size_t y, size_t x, int color)
{
	size_t	i;
	size_t	j;
	size_t	cell;

	cell = 10;
	j = 0;
	while (j < cell)
	{
		i = 0;
		while (i < cell)
		{
			pixel_put(x * cell + i, y * cell + j, color, game);
			i++;
		}
		j++;
	}
}

void	draw_map(t_cub *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (game->map.matrix[y])
	{
		x = 0;
		while (game->map.matrix[y][x])
		{
			draw_back(game, y, x, 0x00000000);
			if (game->map.matrix[y][x] == '1')
				draw_cell(game, y, x, 0x000000FF);
			else
				draw_cell(game, y, x, 0x00CDDFE2);
			x++;
		}
		y++;
	}
}
