/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:13:16 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/06/12 19:28:04 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pixel_put(size_t x, size_t y, int color, t_cub *game)
{
	char	*dst;

	dst = game->mlx.addr
		+ (y * game->mlx.line_length + x * (game->mlx.bpp / 8));
	*(unsigned int *)dst = color;
}

void	init_tex(t_cub *game)
{
	game->tex.north.img = mlx_xpm_file_to_image(game->mlx.ptr, game->map.paths.no,
		&game->tex.north.width, &game->tex.north.height);
	game->tex.north.addr = mlx_get_data_addr(game->tex.north.img, &game->tex.north.bpp,
		&game->tex.north.line_length, &game->tex.north.endian);
	game->tex.south.img = mlx_xpm_file_to_image(game->mlx.ptr, game->map.paths.so,
		&game->tex.south.width, &game->tex.south.height);
	game->tex.south.addr = mlx_get_data_addr(game->tex.south.img, &game->tex.south.bpp,
		&game->tex.south.line_length, &game->tex.south.endian);
	game->tex.west.img = mlx_xpm_file_to_image(game->mlx.ptr, game->map.paths.we,
		&game->tex.west.width, &game->tex.west.height);
	game->tex.west.addr = mlx_get_data_addr(game->tex.west.img, &game->tex.west.bpp,
		&game->tex.west.line_length, &game->tex.west.endian);
	game->tex.east.img = mlx_xpm_file_to_image(game->mlx.ptr, game->map.paths.ea,
		&game->tex.east.width, &game->tex.east.height);
	game->tex.east.addr = mlx_get_data_addr(game->tex.east.img, &game->tex.east.bpp,
		&game->tex.east.line_length, &game->tex.east.endian);
}

void	init_display(t_cub *game)
{
	game->mlx.ptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.ptr, WIDTH, HEIGHT, "GAME");
	game->mlx.img = mlx_new_image(game->mlx.ptr, WIDTH, HEIGHT);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bpp,
			&game->mlx.line_length, &game->mlx.endian);
	init_tex(game);
	draw_win(game);
}
