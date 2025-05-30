/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:14:52 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/30 13:30:02 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	flood_fill(char **map, int y, int x, int lnes)
{
	// Fuera por arriba
	if (y < 0 || y >= lnes)
		return (0);
	// fuera por el ancho de esa línea
	if (x < 0 || x >= (int)strlen(map[y]))
		return (0);
	// fuera del mapa (espacio)
	if (map[y][x] == ' ')
		return (0);
	// si es muro o ya visitado continua la ejecución
	if (map[y][x] == '1' || map[y][x] == 'F')
		return (1);
	// marco como visitado
	map[y][x] = 'F';
	// en cuanto una llamada devuelve 0, devuelvo 0 como error
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
