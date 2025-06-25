/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 23:25:15 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/06/25 17:15:47 by dsoriano         ###   ########.fr       */
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

void	draw_win(t_cub *game)
{
	draw_floor_and_ceilling(game);
	render(game);
	draw_map(game);
	draw_plyr(game);
	mlx_put_image_to_window(game->mlx.ptr, game->mlx.win, game->mlx.img, 0, 0);
}
