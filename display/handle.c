/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:23:46 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/06/02 22:49:06 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	loop_counter(t_cub *game)
{
	if (game->input_cnt++ < INPUT_DELAY)
		game->input_cnt++;
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
		update_planes(game);
		game->input_cnt = 0;
	}
	return (0);
}
