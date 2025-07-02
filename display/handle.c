/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:23:46 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/07/02 17:18:39 by dsoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	loop_counter(t_cub *game)
{
	if (game->input_cnt++ < INPUT_DELAY)
		game->input_cnt++;
	return (0);
}

/*
	If the door is in front of the player and inside the dist_door limits,
	the door is changed in the minimap/2d matrix.
*/
static int	open_door(t_cub *game)
{
	double	dist_door;
	int		new_x;
	int		new_y;

	dist_door = 0.9;
	new_x = game->plyr.pos_x + game->plyr.dir_x;
	new_y = game->plyr.pos_y + game->plyr.dir_y;
	if (game->map.matrix[new_y][new_x] == '2')
	{
		game->map.matrix[new_y][new_x] = '3';
		return (1);
	}
	return (0);
}

int	handle_keys(t_cub *game)
{
	loop_counter(game);
	if (game->input_cnt >= INPUT_DELAY)
	{
		if (game->keys.a)
			move_side(game, 1);
		else if (game->keys.d)
			move_side(game, -1);
		else if (game->keys.w)
			move_fward(game, 1);
		else if (game->keys.s)
			move_fward(game, -1);
		else if (game->keys.l)
			rotation(game, 1);
		else if (game->keys.r)
			rotation(game, -1);
		else if (game->keys.open)
			if (open_door(game))
				draw_win(game);
		update_planes(game);
		game->input_cnt = 0;
	}
	return (0);
}
