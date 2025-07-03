/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:26:51 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/07/03 16:13:54 by dsoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calc_perp_dist(t_cub *game, t_rend *rend, int map_x, int map_y)
{
	if (rend->side == 0)
		rend->perp_dist = (map_x - game->plyr.pos_x
				+ (1.0 - rend->step_x) / 2.0) / rend->ray_dir_x;
	else
		rend->perp_dist = (map_y - game->plyr.pos_y
				+ (1.0 - rend->step_y) / 2.0) / rend->ray_dir_y;
}

/*
	If it's a wall or a closed door return 'hit'.
	If it's a door set 'is_door'. If it's an opened one set 'is_opened'.
*/
int	hit_detection(char elem, t_rend *rend)
{
	int	hit;

	hit = 0;
	if (elem == '1' || elem == '2' || (elem == '3' && rend->first_loop))
		hit = 1;
	rend->is_door = (elem == '2') || (elem == '3');
	if (elem == '3')
		rend->is_opened = 1;
	return (hit);
}

/*
	If it's a wall or a door return 'hit'.
	If it's a door set 'is_door'. If it's an opened one set 'is_opened'.

int	hit_detection(char elem, t_rend *rend)
{
	int	hit;

	hit = 0;
	if (elem == '1' || elem == '2' || elem == '3')
	{
		hit = 1;
		rend->is_door = (elem == '2') || (elem == '3');
		if (rend->is_door)
			rend->is_opened = elem == '3';
	}
	return (hit);
}*/

/*
	Loop until hit:
	- Find if the closer border is in the 'x' axis or in the 'y' axis.
	- Update 'side_dist' to find a further grid on the next iteration.
	- Update 'map_x' to save the posible hit cell.
	- Determine the side orientation of the posible hit.
	- Check for actual hit.
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
		hit = hit_detection(game->map.matrix[map_y][map_x], rend);
	}
	calc_perp_dist(game, rend, map_x, map_y);
}
