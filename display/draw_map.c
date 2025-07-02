/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:38:00 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/07/02 18:50:22 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_cell(t_cub *game, size_t y, size_t x, int color)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < CELL_SIZE)
	{
		i = 0;
		while (i < CELL_SIZE)
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

/*
	1 is for walls, 2 is for closed doors and 3 is for opened doors.
*/
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
			else if (game->map.matrix[y][x] == ' ')
				draw_cell(game, y, x, 0x1E1E1E);
			else if (game->map.matrix[y][x] == '2')
				draw_cell(game, y, x, 0x777766);
			else if (game->map.matrix[y][x] == '3')
				draw_cell(game, y, x, 0xBBBB99);
			else
				draw_cell(game, y, x, 0xAAAAAA);
			x++;
		}
		y++;
	}
}
