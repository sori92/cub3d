/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_null.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:05:12 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/07/05 10:04:27 by jrubio-m         ###   ########.fr       */
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
	game->map.paths.door = NULL;
	game->map.paths.opened = NULL;
	game->map.color.f = NULL;
	game->map.color.floor.r = 0;
	game->map.color.floor.g = 0;
	game->map.color.floor.b = 0;
	game->map.color.c = NULL;
	game->map.color.ceiling.r = 0;
	game->map.color.ceiling.g = 0;
	game->map.color.ceiling.b = 0;
	game->map.matrix = NULL;
	game->map.cols = 0;
	game->map.rows = 0;
}

void	init_null(t_cub *game)
{
	init_map_null(game);
	game->plyr.y = 0;
	game->plyr.x = 0;
	init_mlx_null(game);
	game->keys.a = 0;
	game->keys.d = 0;
	game->keys.w = 0;
	game->keys.s = 0;
	game->keys.l = 0;
	game->keys.r = 0;
	game->keys.open = 0;
	game->keys.last_input_time = get_time_ms();
	game->input_cnt = 0;
	game->can_open = 1;
	game->offsets[0] = 0;
	game->offsets[1] = 0;
}
