/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:33:10 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/06/17 19:33:45 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	Altura de la textura (z) para esa posición (x, y).
	Calculamos el inicio de la textura
		(con el pivote en el centro, la mitad de la textura para arriba).
	Si se salee de la pantalla por arriba, pues 0.
	Calculamos el final de la textura
		(con el pivote en el centro, la mitad de la textura para abajo).
	Si se sale de la pantalla por abajo, pues la altura de la pantalla.
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
}

t_tx	*texture_orientation(t_cub *game, t_rend *rend)
{
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
	rend->draw.tex_x = (int)(coll_point * tex->width);
	if (rend->draw.tex_x < 0)
		rend->draw.tex_x = 0;
	if (rend->draw.tex_x >= tex->width)
		rend->draw.tex_x = tex->width - 1;
}
