/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:13:16 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/30 23:24:35 by jrubio-m         ###   ########.fr       */
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

void	init_display(t_cub *game)
{
	game->mlx.ptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.ptr, WIDTH, HEIGHT, "GAME");
	game->mlx.img = mlx_new_image(game->mlx.ptr, WIDTH, HEIGHT);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bpp,
			&game->mlx.line_length, &game->mlx.endian);
	draw_win(game);
}
