/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:40:48 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/07/03 19:43:12 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
	Calculamos, según el vector del rayo, cuanto tiene que recorrer,
	ese rayo, para recorrer un grid entero (primero en x y luego en y).
*/
void	calc_delta_distances(t_rend *rend)
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
void	calc_side_distances(t_cub *game, t_rend *rend, int map_x, int map_y)
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
