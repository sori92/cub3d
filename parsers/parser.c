/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:10:38 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/06/05 16:23:15 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_closed_walls(char **matrix, size_t y, size_t x, t_cub *game)
{
	if (!matrix)
	{
		free_all(game);
		exit (print_error("Error in malloc doing ft_arraydup\n"));
	}
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x])
		{
			if (matrix[y][x] == '0')
			{
				if (!flood_fill(matrix, y, x, ft_arraylen(matrix)))
				{
					free_array(matrix, ft_arraylen(matrix));
					free_all(game);
					exit (print_error("Unclosed map\n"));
				}
			}
			x++;
		}
		y++;
	}
	free_array(matrix, ft_arraylen(matrix));
}

void	check_rgb_range(t_cub *game, t_clr colors)
{
	int	error;

	error = 0;
	if (colors.floor.r < 0 || colors.floor.g < 0 || colors.floor.b < 0
		|| colors.ceiling.r < 0 || colors.ceiling.g < 0 || colors.ceiling.b < 0)
		error = 1;
	if (colors.floor.r > 255 || colors.floor.g > 255 || colors.floor.b > 255
		|| colors.ceiling.r > 255 || colors.ceiling.g > 255
		|| colors.ceiling.b > 255)
		error = 1;
	if (error)
	{
		free_all(game);
		exit(print_error("Wrong range of rgb colors. Expected: [0 - 255]\n"));
	}
}

void	parser(t_cub *game)
{
	clean_paths_and_colors(game);
	check_texture_routes_and_colors(game);
	check_rgb_range(game, game->map.color);
	check_chars_and_empty_lines(game);
	clean_matrix(game);
	check_for_player(game);
	check_closed_walls(ft_arraydup(game->map.matrix), 0, 0, game);
	init_player(game);
}
