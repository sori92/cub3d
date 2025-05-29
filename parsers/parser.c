/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:10:38 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/30 00:37:36 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	find_player(char **matrix, t_cub *game, size_t y, size_t x)
{
	while (matrix[y])
	{
		x = 0;
		while (matrix[y][x] && matrix[y][x] != 'N' && matrix[y][x] != 'S'
				&& matrix[y][x] != 'W' && matrix[y][x] != 'E')
			x++;
		if (matrix[y][x])
		{
			game->plyr.y = y;
			game->plyr.x = x;
			return ;
		}
		y++;
	}
}

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

void	check_rgb_range(t_cub *game, t_rgb colors)
{
	int	error;

	error = 0;
	if (colors.fr < 0 || colors.fg < 0 || colors.fb < 0
		|| colors.cr < 0 || colors.cg < 0 || colors.cb < 0)
		error = 1;
	if (colors.fr > 255 || colors.fg > 255 || colors.fb > 255
		|| colors.cr > 255 || colors.cg > 255 || colors.cb > 255)
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
	find_player(game->map.matrix, game, 0, 0);
}
