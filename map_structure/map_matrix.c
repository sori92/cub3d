/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:34:40 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/30 13:28:56 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_if_map_exists(size_t *l, t_cub *game)
{
	while (game->map.file_array[*l] && game->map.file_array[*l][0] == '\n')
		(*l)++;
	if (!game->map.file_array[*l])
	{
		free_all(game);
		exit (print_error("Missing map\n"));
	}
}

size_t	count_matrix_lines(size_t l, t_cub *game)
{
	size_t	lines;

	lines = 0;
	while (game->map.file_array[l])
	{
		lines++;
		l++;
	}
	return (lines);
}

void	make_map_matrix(size_t l, t_cub *game)
{
	size_t	lines;
	size_t	y;

	y = 0;
	check_if_map_exists(&l, game);
	lines = count_matrix_lines(l, game);
	game->map.matrix = malloc(sizeof(char *) * (lines + 1));
	if (!game->map.matrix)
	{
		free_all(game);
		exit(print_error("Error in malloc making map matrix\n"));
	}
	while (game->map.file_array[l])
	{
		game->map.matrix[y] = ft_strdup(game->map.file_array[l]);
		if (!game->map.matrix[y])
		{
			free_array(game->map.matrix, y);
			free_all(game);
			exit(print_error("Error in ft_strdup doing map matrix\n"));
		}
		y++;
		l++;
	}
	game->map.matrix[y] = NULL;
}
