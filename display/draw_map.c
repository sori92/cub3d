/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:38:00 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/06/25 17:13:17 by dsoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_cell(t_cub *game, size_t y, size_t x, int color)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < CELL_SIZE - 1)
	{
		i = 0;
		while (i < CELL_SIZE - 1)
		{
			pixel_put(x * CELL_SIZE + i + game->offsets[0],
				y * CELL_SIZE + j + game->offsets[1], color, game);
			i++;
		}
		j++;
	}
}

void	draw_background(t_cub *game, int color)
{
 	size_t	y;
	size_t	x;

	y = 0;
	while (y < game->map.rows + 2)
	{
		x = 0;
		while (x < game->map.cols + 2)
		{
			draw_cell(game, y - 1, x - 1, color);
			x++;
		}
		y++;
	}
}

void	draw_map(t_cub *game)
{
 	size_t	y;
	size_t	x;

	draw_background(game, 0x1E1E1E);
 	y = 0;
	while (game->map.matrix[y])
	{
		x = 0;
		while (game->map.matrix[y][x])
		{
			if (game->map.matrix[y][x] == '1')
				draw_cell(game, y, x, 0x555555);
			else
				draw_cell(game, y, x, 0xAAAAAA);
			x++;
		}
		y++;
	}
}
