/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:07:15 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/07/03 18:22:02 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	Calculamos, según el vector del rayo, cuanto tiene que recorrer,
	ese rayo, para recorrer un grid entero (primero en x y luego en y).
*/
static void	calc_delta_distances(t_rend *rend)
{
	if (rend->ray_dir_x != 0)
		rend->delta_x = fabs(1 / rend->ray_dir_x);
	else
		rend->delta_x = 1e30;
	if (rend->ray_dir_y != 0)
		rend->delta_y = fabs(1 / rend->ray_dir_y);
	else
		rend->delta_y = 1e30;
}

/*
	Sabiendo cuanto tarda el rayo en recorrer cada grid,
	calculamos cuanto necesita para llegar al borde más cercano,
	desde la posición del jugador.
*/
static void	calc_side_distances(t_cub *game, t_rend *rend, int map_x, int map_y)
{
	if (rend->ray_dir_x < 0)
	{
		rend->step_x = -1;
		rend->side_dist_x = (game->plyr.pos_x - map_x) * rend->delta_x;
	}
	else
	{
		rend->step_x = 1;
		rend->side_dist_x = (map_x + 1.0 - game->plyr.pos_x) * rend->delta_x;
	}
	if (rend->ray_dir_y < 0)
	{
		rend->step_y = -1;
		rend->side_dist_y = (game->plyr.pos_y - map_y) * rend->delta_y;
	}
	else
	{
		rend->step_y = 1;
		rend->side_dist_y = (map_y + 1.0 - game->plyr.pos_y) * rend->delta_y;
	}
}

/*
	Changing the color according to the darkness modif.
*/
int	color_darkness(int color, double darkness)
{
	int	r;
	int	g;
	int	b;

	
	r = ((color >> 16) & 0xFF) * darkness;
	g = ((color >> 8) & 0xFF) * darkness;
	b = (color & 0xFF) * darkness;
	return ((r << 16) | (g << 8) | b);
}

static void	draw_loop(int x, t_tx *tex, t_cub *game, t_rend *rend)
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
void	render(t_cub *game)
{
	int		x;
	t_rend	rend;
	t_tx	*tex;

	rend.is_opened = 0;
	rend.first_loop = 1;
	x = 0;
	while (x < WIDTH)
	{
		rend.camera_x = 2.0 * x / (double)WIDTH - 1.0;
		rend.ray_dir_x = game->plyr.dir_x + game->plyr.plane_x * rend.camera_x;
		rend.ray_dir_y = game->plyr.dir_y + game->plyr.plane_y * rend.camera_x;
		calc_delta_distances(&rend);
		calc_side_distances(game, &rend, game->plyr.pos_x, game->plyr.pos_y);
		dda(game, &rend, game->plyr.pos_x, game->plyr.pos_y);
		calc_texture_size(&rend);
		tex = texture_orientation(game, &rend);
		calc_texture_collision_point(tex, game, &rend);
		rend.draw.step = (double)tex->height / rend.draw.line_height;
		rend.draw.tex_pos = (rend.draw.draw_start - HEIGHT / 2
				+ rend.draw.line_height / 2) * rend.draw.step;
		draw_loop(x, tex, game, &rend);
		x++;
	}
	if (rend.is_opened)
	{
		rend.first_loop = 0;
		x = 0;
		while (x < WIDTH)
		{
			rend.camera_x = 2.0 * x / (double)WIDTH - 1.0;
			rend.ray_dir_x = game->plyr.dir_x + game->plyr.plane_x * rend.camera_x;
			rend.ray_dir_y = game->plyr.dir_y + game->plyr.plane_y * rend.camera_x;
			calc_delta_distances(&rend);
			calc_side_distances(game, &rend, game->plyr.pos_x, game->plyr.pos_y);
			dda(game, &rend, game->plyr.pos_x, game->plyr.pos_y);
			calc_texture_size(&rend);
			tex = texture_orientation(game, &rend);
			calc_texture_collision_point(tex, game, &rend);
			rend.draw.step = (double)tex->height / rend.draw.line_height;
			rend.draw.tex_pos = (rend.draw.draw_start - HEIGHT / 2
					+ rend.draw.line_height / 2) * rend.draw.step;
			draw_loop(x, tex, game, &rend);
			x++;
		}
	}
}
