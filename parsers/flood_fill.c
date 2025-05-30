/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:14:52 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/30 22:56:11 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	flood_fill(char **map, int y, int x, int lnes)
{
	if (y < 0 || y >= lnes)
		return (0);
	if (x < 0 || x >= (int)strlen(map[y]))
		return (0);
	if (map[y][x] == ' ')
		return (0);
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (1);
	map[y][x] = 'F';
	if (!flood_fill(map, y + 1, x, lnes))
		return (0);
	if (!flood_fill(map, y - 1, x, lnes))
		return (0);
	if (!flood_fill(map, y, x + 1, lnes))
		return (0);
	if (!flood_fill(map, y, x - 1, lnes))
		return (0);
	return (1);
}
