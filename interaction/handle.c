/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:23:46 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/07/05 10:11:46 by jrubio-m         ###   ########.fr       */
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
	There is a little delay of 200 ms to avoid open-close loops.
*/
static void	open_door(t_cub *game)
{
	int		new_x;
	int		new_y;
	long	curr_time;

	curr_time = get_time_ms();
	if (curr_time - game->keys.last_input_time < 200)
		return ;
	game->keys.last_input_time = curr_time;
	new_x = game->plyr.pos_x + game->plyr.dir_x;
	new_y = game->plyr.pos_y + game->plyr.dir_y;
	if (game->map.matrix[new_y][new_x] == '2' && game->can_open)
	{
		game->map.matrix[new_y][new_x] = '3';
		game->can_open = 0;
		return ;
	}
	if (game->map.matrix[new_y][new_x] == '3')
	{
		game->can_open = 1;
		game->map.matrix[new_y][new_x] = '2';
		return ;
	}
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
		{
			open_door(game);
			draw_win(game);
		}
		update_planes(game);
		game->input_cnt = 0;
	}
	return (0);
}
