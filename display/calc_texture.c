/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:33:10 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/07/01 18:12:30 by dsoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	Texture height (z) for that position (x, y).
	We calculate the start of the texture
		(with the pivot in the center, halfway up the texture).
	If it goes off the screen at the top, then 0.
	We calculate the end of the texture
		(with the pivot in the center, halfway down the texture).
	If it goes off the screen at the bottom, then the height of the screen.
*/
void	calc_texture_size(t_rend *rend)
{
	rend->draw.line_height = (int)(HEIGHT / rend->perp_dist);
	rend->draw.draw_start = -(rend->draw.line_height) / 2 + HEIGHT / 2;
	if (rend->draw.draw_start < 0)
		rend->draw.draw_start = 0;
	rend->draw.draw_end = rend->draw.line_height / 2 + HEIGHT / 2;
	if (rend->draw.draw_end >= HEIGHT)
		rend->draw.draw_end = HEIGHT - 1;
	rend->draw.darkness = 1 - rend->perp_dist / DARK_TRESHOLD;
	if (rend->draw.darkness < 0)
		rend->draw.darkness = 0;
	if (rend->draw.darkness > 1)
		rend->draw.darkness = 1;
}

t_tx	*texture_orientation(t_cub *game, t_rend *rend)
{
	if (rend->is_door)
		return (&game->tex.door);
	if (rend->side == 0)
	{
		if (rend->step_x > 0)
			return (&game->tex.east);
		else
			return (&game->tex.west);
	}
	else
	{
		if (rend->step_y > 0)
			return (&game->tex.south);
		else
			return (&game->tex.north);
	}
}

/*
	Calculamos el punto exacto de impacto en la pared.
	Le quitamos la parte entera dejando solo los decimales
	(para tener el porcentaje de la textura).
	Ese porcentaje es la posición en la textura que queremos renderizar.
*/
void	calc_texture_collision_point(t_tx *tex, t_cub *game, t_rend *rend)
{
	double	coll_point;

	if (rend->side == 0)
		coll_point = game->plyr.pos_y + rend->perp_dist * rend->ray_dir_y;
	else
		coll_point = game->plyr.pos_x + rend->perp_dist * rend->ray_dir_x;
	coll_point -= floor(coll_point);
	calc_texture_darkness(coll_point, tex, rend);
}

/*
	Calculating the darkness multiplier for the texture.
*/
void	calc_texture_darkness(double coll_point, t_tx *tex, t_rend *rend)
{
	rend->draw.tex_x = (int)(coll_point * tex->width);
	if (rend->draw.tex_x < 0)
		rend->draw.tex_x = 0;
	if (rend->draw.tex_x >= tex->width)
		rend->draw.tex_x = tex->width - 1;
}
