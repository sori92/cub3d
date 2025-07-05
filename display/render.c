/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:07:15 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/07/05 20:28:30 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_loop(int x, t_tx *tex, t_cub *game, t_rend *rend)
{
	int	color;
	int	y;

	y = rend->draw.draw_start;
	while (y < rend->draw.draw_end)
	{
		rend->draw.tex_y = (int)rend->draw.tex_pos;
		if (rend->draw.tex_y < 0)
			rend->draw.tex_y = 0;
		if (rend->draw.tex_y >= tex->height)
			rend->draw.tex_y = tex->height - 1;
		rend->draw.tex_pos += rend->draw.step;
		color = *(unsigned int *)(tex->addr + rend->draw.tex_y
				* tex->line_length + rend->draw.tex_x * (tex->bpp / 8));
		if ((color & 0x00FFFFFF) != 0x00FF00FF)
		{
			if (rend->side == 1)
				color = (color >> 1) & 0x7F7F7F;
			color = color_darkness(color, rend->draw.darkness);
		}
		pixel_put(x, y, color, game);
		y++;
	}
}

/*
	For every pixel on screen:
	- Normalizing pixel position to determine if it's on the
		left side, right side or centre of the screen.
	- Calculating direction between that X (normalized) and the player pos.
	- Player pos in ints (used to compare with the grid).
	- Calc texture increment:
		Every few pixels on the screen we advance one in the texture.
	- Where the texture starts (case it's close to the lower of the screen).
*/
void	ray_cast(int x, t_rend *rend, t_cub *game)
{
	t_tx	*tex;

	rend->camera_x = 2.0 * x / (double)WIDTH - 1.0;
	rend->ray_dir_x = game->plyr.dir_x + game->plyr.plane_x
		* rend->camera_x;
	rend->ray_dir_y = game->plyr.dir_y + game->plyr.plane_y
		* rend->camera_x;
	calc_delta_distances(rend);
	calc_side_distances(game, rend, game->plyr.pos_x, game->plyr.pos_y);
	dda(game, rend, game->plyr.pos_x, game->plyr.pos_y);
	calc_texture_size(rend);
	tex = texture_orientation(game, rend);
	calc_texture_collision_point(tex, game, rend);
	rend->draw.step = (double)tex->height / rend->draw.line_height;
	rend->draw.tex_pos = (rend->draw.draw_start - HEIGHT / 2
			+ rend->draw.line_height / 2) * rend->draw.step;
	draw_loop(x, tex, game, rend);
}

void	render(t_cub *game)
{
	int		x;
	t_rend	rend;

	x = 0;
	while (x < WIDTH)
	{
		rend.is_opened = 0;
		rend.first_loop = 1;
		ray_cast(x, &rend, game);
		rend.first_loop = 0;
		if (rend.is_opened)
			ray_cast(x, &rend, game);
		x++;
	}
}
