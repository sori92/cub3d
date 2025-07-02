/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:47:09 by dsoriano          #+#    #+#             */
/*   Updated: 2025/07/02 12:57:01 by dsoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	key_press(int key, t_cub *game)
{
	if (key == XK_Escape)
		return (close_window(game));
	else if (key == XK_a)
		game->keys.a = 1;
	else if (key == XK_d)
		game->keys.d = 1;
	else if (key == XK_w)
		game->keys.w = 1;
	else if (key == XK_s)
		game->keys.s = 1;
	else if (key == XK_Left)
		game->keys.l = 1;
	else if (key == XK_Right)
		game->keys.r = 1;
	else if (key == XK_space)
		game->keys.open = 1;
	return (1);
}

int	key_released(int key, t_cub *game)
{
	if (key == XK_a)
		game->keys.a = 0;
	else if (key == XK_d)
		game->keys.d = 0;
	else if (key == XK_w)
		game->keys.w = 0;
	else if (key == XK_s)
		game->keys.s = 0;
	else if (key == XK_Left)
		game->keys.l = 0;
	else if (key == XK_Right)
		game->keys.r = 0;
	else if (key == XK_space)
		game->keys.open = 0;
	return (1);
}

static void	launch_rot(int delta_x, t_cub *game)
{
	if (delta_x > 2)
	{
		key_press(XK_Right, game);
		key_released(XK_Left, game);
	}
	else if (delta_x < -2)
	{
		key_press(XK_Left, game);
		key_released(XK_Right, game);
	}
}

int	mouse_rot(int x, int y, t_cub *game)
{
	static int	prev_x;
	int			delta_x;
	int			min_l;
	int			min_r;

	(void)y;
	min_l = WIDTH * 0.3;
	min_r = WIDTH * 0.7;
	if (prev_x == 0)
		prev_x = x;
	delta_x = x - prev_x;
	if (x >= min_l && x <= min_r)
	{
		key_released(XK_Left, game);
		key_released(XK_Right, game);
		return (0);
	}
	launch_rot(delta_x, game);
	return (1);
}

int	mouse_leave(void *event, t_cub *game)
{
	(void)event;
	key_released(XK_Left, game);
	key_released(XK_Right, game);
	return (0);
}
