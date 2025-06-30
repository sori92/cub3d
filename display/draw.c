/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:25:15 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/06/30 15:41:57 by dsoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_plyr_dir(t_cub *game, size_t cell)
{
	int	i;

	i = 1;
	while (i < 31)
	{
		pixel_put(
			game->plyr.pos_x * 10 + game->offsets[0]
			+ game->plyr.dir_x * cell * (1 + i / 10.0),
			game->plyr.pos_y * 10 + game->offsets[1]
			+ game->plyr.dir_y * cell * (1 + i / 10.0),
			0x00BFFF, game);
		i++;
	}
}

static void	draw_plyr(t_cub *game)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < PLYR_CELL / 2)
	{
		i = 0;
		while (i < PLYR_CELL / 2)
		{
			pixel_put(game->plyr.pos_x * 10 + i + game->offsets[0],
				game->plyr.pos_y * 10 + j + game->offsets[1], 0x00BFFF, game);
			pixel_put(game->plyr.pos_x * 10 - i + game->offsets[0],
				game->plyr.pos_y * 10 + j + game->offsets[1], 0x00BFFF, game);
			pixel_put(game->plyr.pos_x * 10 + i + game->offsets[0],
				game->plyr.pos_y * 10 - j + game->offsets[1], 0x00BFFF, game);
			pixel_put(game->plyr.pos_x * 10 - i + game->offsets[0],
				game->plyr.pos_y * 10 - j + game->offsets[1], 0x00BFFF, game);
			i++;
		}
		j++;
	}
	draw_plyr_dir(game, PLYR_CELL / 2 - 1);
}

void	draw_floor_and_ceilling(t_cub *game)
{
	size_t	x;
	size_t	y;
	size_t	f_color;
	size_t	c_color;

	f_color = (game->map.color.floor.r << 16)
		| (game->map.color.floor.g << 8)
		| game->map.color.floor.b;
	c_color = (game->map.color.ceiling.r << 16)
		| (game->map.color.ceiling.g << 8)
		| game->map.color.ceiling.b;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				pixel_put(x, y, c_color, game);
			else
				pixel_put(x, y, f_color, game);
			x++;
		}
		y++;
	}
}

void	draw_win(t_cub *game)
{
	draw_floor_and_ceilling(game);
	render(game);
	draw_map(game);
	draw_plyr(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img, 0, 0);
	draw_weapon(game);
}
