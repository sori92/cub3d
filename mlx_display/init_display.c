/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:13:16 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/30 13:28:14 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_display(t_cub *game)
{
	game->mlx.ptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.ptr, WIN_WIDTH, WIN_HEIGHT, "GAME");
	game->mlx.img = mlx_new_image(game->mlx.ptr, WIN_WIDTH, WIN_HEIGHT);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bpp, &game->mlx.line_length, &game->mlx.endian);
}
