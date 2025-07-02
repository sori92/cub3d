/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_anims.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:40:39 by dsoriano          #+#    #+#             */
/*   Updated: 2025/07/02 14:56:05 by dsoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	Advances the counter of the anim until reaching 'fr_delay',
	then it changes the current frame. So it controls the anim speed.
*/
void	frame_iteration(t_cub *game)
{
	game->weapon.counter++;
	if (game->weapon.counter >= game->weapon.fr_delay)
	{
		game->weapon.fr_current = (game->weapon.fr_current + 1)
			% game->weapon.fr_count;
		game->weapon.counter = 0;
	}
}

/*
	Here we paint an upper layer to show the hand of the player.
	The trick to do it without PNG supporting is: painting transparency
	in an unused color, and not trigger 'pixel_put' for the pixels of that color.
	Before painting, we calc the correct positioning of the images in the screen.
*/
void	weapon_painting(t_cub *game, int bpp, int sl, char *data)
{
	int	draw_x;
	int	draw_y;
	int	color;
	int	x;
	int	y;

	draw_x = ((WIDTH - game->weapon.size_w) / 2) + 150;
	draw_y = HEIGHT - game->weapon.size_h;
	y = 0;
	while (y < game->weapon.size_h)
	{
		x = 0;
		while (x < game->weapon.size_w)
		{
			color = *(int *)(data + (y * sl + x * (bpp / 8)));
			if ((color & 0x00FFFFFF) != 0x00FF00FF)
				pixel_put(draw_x + x, draw_y + y, color, game);
			x++;
		}
		y++;
	}
}

void	draw_weapon(t_cub *game)
{
	void	*frame;
	char	*data;
	int		bpp;
	int		sl;

	frame_iteration(game);
	frame = game->weapon.frames[game->weapon.fr_current];
	data = mlx_get_data_addr(frame, &bpp, &sl, &(int){0});
	if (!data)
		return ;
	weapon_painting(game, bpp, sl, data);
}
