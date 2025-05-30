/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:05:12 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/30 13:29:14 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_mlx_null(t_cub *game)
{
	game->mlx.ptr = NULL;
	game->mlx.win = NULL;
	game->mlx.img = NULL;
	game->mlx.addr = NULL;
	game->mlx.bpp = 0;
	game->mlx.line_length = 0;
	game->mlx.endian = 0;
}

static void	init_map_null(t_cub *game)
{
	game->map.file_array = NULL;
	game->map.paths.no = NULL;
	game->map.paths.so = NULL;
	game->map.paths.ea = NULL;
	game->map.paths.we = NULL;
	game->map.color.f = NULL;
	game->map.color.floor.r = 0;
	game->map.color.floor.g = 0;
	game->map.color.floor.b = 0;
	game->map.color.c = NULL;
	game->map.color.ceilling.r = 0;
	game->map.color.ceilling.g = 0;
	game->map.color.ceilling.b = 0;
	game->map.matrix = NULL;
}

void	init_null(t_cub *game)
{
	init_map_null(game);
	game->plyr.y = 0;
	game->plyr.x = 0;
	init_mlx_null(game);
}