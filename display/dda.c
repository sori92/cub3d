/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:26:51 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/07/01 17:29:17 by dsoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	calc_perp_dist(t_cub *game, t_rend *rend, int map_x, int map_y)
{
	if (rend->side == 0)
		rend->perp_dist = (map_x - game->plyr.pos_x
				+ (1.0 - rend->step_x) / 2.0) / rend->ray_dir_x;
	else
		rend->perp_dist = (map_y - game->plyr.pos_y
				+ (1.0 - rend->step_y) / 2.0) / rend->ray_dir_y;
}

/*
	Hasta que choque, hacemos:
	- Si el borde más cercano está por el eje x o por el eje y.
	- Actualizamos side_dist para que
		en la siguiente iteración busque un grid más alejado.
	- Actualizamos map_x para que guarde la celda de impacto
		(o la que acabamos de mirar, impacte o no).
*/
void	dda(t_cub *game, t_rend *rend, int map_x, int map_y)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (rend->side_dist_x < rend->side_dist_y)
		{
			rend->side_dist_x += rend->delta_x;
			map_x += rend->step_x;
			rend->side = 0;
		}
		else
		{
			rend->side_dist_y += rend->delta_y;
			map_y += rend->step_y;
			rend->side = 1;
		}
		if (game->map.matrix[map_y][map_x] == '1'
				|| game->map.matrix[map_y][map_x] == '2')
		{
			hit = 1;
			rend->is_door = (game->map.matrix[map_y][map_x] == '2');
		}
	}
	calc_perp_dist(game, rend, map_x, map_y);
}
