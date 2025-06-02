/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 22:45:03 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/06/02 22:50:59 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	can_move(t_cub *game, double new_x, double new_y)
{
	if (game->map.matrix[(int)(new_y - PL_RAD)][(int)(new_x - PL_RAD)] == '1' ||
		game->map.matrix[(int)(new_y - PL_RAD)][(int)(new_x + PL_RAD)] == '1' ||
		game->map.matrix[(int)(new_y + PL_RAD)][(int)(new_x - PL_RAD)] == '1' ||
		game->map.matrix[(int)(new_y + PL_RAD)][(int)(new_x + PL_RAD)] == '1' ||
		game->map.matrix[(int)(new_y)][(int)(new_x)] == '1')
		return (0);
	return (1);
}

int	move_side(t_cub *game, int dir)
{
	double	new_x;
	double	new_y;

	new_x = game->plyr.pos_x + game->plyr.dir_y * dir * SPEED;
	new_y = game->plyr.pos_y - game->plyr.dir_x * dir * SPEED;
	if (can_move(game, new_x, game->plyr.pos_y))
		game->plyr.pos_x = new_x;
	if (can_move(game, game->plyr.pos_x, new_y))
		game->plyr.pos_y = new_y;
	draw_win(game);
	return (1);
}

int	move_fward(t_cub *game, int dir)
{
	double	new_x;
	double	new_y;

	new_x = game->plyr.pos_x + game->plyr.dir_x * dir * SPEED;
	new_y = game->plyr.pos_y + game->plyr.dir_y * dir * SPEED;
	if (can_move(game, new_x, game->plyr.pos_y))
		game->plyr.pos_x = new_x;
	if (can_move(game, game->plyr.pos_x, new_y))
		game->plyr.pos_y = new_y;
	draw_win(game);
	return (1);
}

int	rotation(t_cub *game, int dir)
{
	double	rads;
	double	x;
	double	y;

	rads = (2.0 * dir) * (PI / 180.0);
	y = game->plyr.dir_y * cos(rads) - game->plyr.dir_x * sin(rads);
	x = game->plyr.dir_y * sin(rads) + game->plyr.dir_x * cos(rads);
	game->plyr.dir_y = y;
	game->plyr.dir_x = x;
	draw_win(game);
	return (1);
}
