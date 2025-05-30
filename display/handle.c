/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:23:46 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/30 23:32:49 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	move_side(t_cub *game, int dir)
{
	game->plyr.pos_x += game->plyr.dir_y * dir / 10;
	game->plyr.pos_y -= game->plyr.dir_x * dir / 10;
	mlx_clear_window(game->mlx.ptr, game->mlx.win);
	draw_win(game);
	return (1);
}

static int	move_fward(t_cub *game, int dir)
{
	game->plyr.pos_x += game->plyr.dir_x * dir / 10;
	game->plyr.pos_y += game->plyr.dir_y * dir / 10;
	mlx_clear_window(game->mlx.ptr, game->mlx.win);
	draw_win(game);
	return (1);
}

static int	rotation(t_cub *game, int dir)
{
	double	rads;
	double	x;
	double	y;

	rads = (2.0 * dir) * (PI / 180.0);
	y = game->plyr.dir_y * cos(rads) - game->plyr.dir_x * sin(rads);
	x = game->plyr.dir_y * sin(rads) + game->plyr.dir_x * cos(rads);
	game->plyr.dir_y = y;
	game->plyr.dir_x = x;
	mlx_clear_window(game->mlx.ptr, game->mlx.win);
	draw_win(game);
	return (1);
}

int	handle(int key, t_cub *game)
{
	if (key == XK_Escape)
		return (close_window(game));
	if (key == XK_a)
		return (move_side(game, 1));
	if (key == XK_d)
		return (move_side(game, -1));
	if (key == XK_w)
		return (move_fward(game, 1));
	if (key == XK_s)
		return (move_fward(game, -1));
	if (key == XK_Left)
		return (rotation(game, 1));
	if (key == XK_Right)
		return (rotation(game, -1));
	return (0);
}
