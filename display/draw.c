/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:25:15 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/06/03 19:43:29 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_cell(t_cub *game, size_t y, size_t x, int color)
{
	size_t	i;
	size_t	j;
	size_t	cell;

	cell = 30;
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

static void	draw_back(t_cub *game, size_t y, size_t x, int color)
{
	size_t	i;
	size_t	j;
	size_t	cell;

	cell = 30;
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

static void	draw_map(t_cub *game)
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

static void	draw_plyr_dir(t_cub *game, size_t cell)
{
	int	i;

	i = 1;
	while (i < 31)
	{
		pixel_put(
			game->plyr.pos_x * 30 + game->plyr.dir_x * cell * (1 + i / 10.0),
			game->plyr.pos_y * 30 + game->plyr.dir_y * cell * (1 + i / 10.0),
			0x000D9000, game);
		i++;
	}
}

static void	draw_plyr(t_cub *game)
{
	size_t	i;
	size_t	j;
	size_t	cell;

	cell = 10;
	j = 0;
	while (j < cell / 2)
	{
		i = 0;
		while (i < cell / 2)
		{
			pixel_put(game->plyr.pos_x * 30 + i, game->plyr.pos_y * 30 + j,
				0x000D9000, game);
			pixel_put(game->plyr.pos_x * 30 - i, game->plyr.pos_y * 30 + j,
				0x000D9000, game);
			pixel_put(game->plyr.pos_x * 30 + i, game->plyr.pos_y * 30 - j,
				0x000D9000, game);
			pixel_put(game->plyr.pos_x * 30 - i, game->plyr.pos_y * 30 - j,
				0x000D9000, game);
			i++;
		}
		j++;
	}
	draw_plyr_dir(game, cell / 2 - 1);
}

void	draw_win(t_cub *game)
{
	render(game);
	draw_map(game);
	draw_plyr(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img, 0, 0);
}
