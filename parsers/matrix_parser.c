/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:18:43 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/30 00:19:36 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_char(char c, t_cub *game)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == ' ')
		return ;
	free_all(game);
	exit(print_error("Wrong character found in map matrix\n"));
}

void	check_chars_and_empty_lines(t_cub *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (game->map.matrix[y])
	{
		x = 0;
		if (game->map.matrix[y][x] == '\n')
		{
			free_all(game);
			exit(print_error("Empty line in the map matrix\n"));
		}
		while (game->map.matrix[y][x] && game->map.matrix[y][x] != '\n')
		{
			check_char(game->map.matrix[y][x], game);
			x++;
		}
		y++;
	}
}

void	check_for_player(t_cub *game)
{
	int		n;
	size_t	y;
	size_t	x;
	char	**matrix;

	matrix = game->map.matrix;
	n = 0;
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] == 'N' || matrix[y][x] == 'S'
				|| matrix[y][x] == 'E' || matrix[y][x] == 'W')
				n++;
			x++;
		}
		y++;
	}
	if (n != 1)
	{
		free_all(game);
		exit(print_error("Map must contain at least and only one player\n"));
	}
}
