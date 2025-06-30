/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:25:15 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/06/30 13:22:22 by dsoriano         ###   ########.fr       */
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

/*
	Here we paint an upper layer to show the hand of the player.
	The trick to do it without PNHG supporting is: painting transparency
	in an unused color, and not trigger 'pixel_put' for the pixels of that color.
*/
void	draw_weapon(t_cub *game)
{
	void		*frame;
	char		*data;
	int			bpp, sl, endian;
	int			color;
	int			x, y;
	int			draw_x, draw_y;

	game->weapon.counter++;
	if (game->weapon.counter >= game->weapon.fr_delay)
	{
		game->weapon.fr_current = (game->weapon.fr_current + 1) % game->weapon.fr_count;
		game->weapon.counter = 0;
	}
	frame = game->weapon.frames[game->weapon.fr_current];
	data = mlx_get_data_addr(frame, &bpp, &sl, &endian);
	if (!data)
		return;
	draw_x = (WIDTH - game->weapon.size_w) / 2;
	draw_y = HEIGHT - game->weapon.size_h;
	for (y = 0; y < game->weapon.size_h; y++)
	{
		for (x = 0; x < game->weapon.size_w; x++)
		{
			int i = y * sl + x * (bpp / 8);
			color = *(int *)(data + i);
			if ((color & 0x00FFFFFF) != 0x00FF00FF)
			{
				pixel_put(draw_x + x, draw_y + y, color, game);
			}
		}
	}
}
	
	/* mlx_put_image_to_window(game->mlx.ptr, game->mlx.win,
		frame, (WIDTH - game->weapon.size_w) / 2, HEIGHT - game->weapon.size_h);
} */

void	draw_win(t_cub *game)
{
	draw_floor_and_ceilling(game);
	render(game);
	draw_map(game);
	draw_plyr(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img, 0, 0);
	draw_weapon(game); 
}
