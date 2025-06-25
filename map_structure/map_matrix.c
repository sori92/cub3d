/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:34:40 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/06/25 17:14:02 by dsoriano         ###   ########.fr       */
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

size_t	get_map_cols(char **matrix)
{
	size_t	max;
	size_t	len;
	size_t	i;

	max = 0;
	i = 0;
	while (matrix[i])
	{
		len = 0;
		while (matrix[i][len] && matrix[i][len] != '\n')
			len++;
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

void	make_map_matrix(size_t l, t_cub *game)
{
	size_t	y;

	y = 0;
	check_if_map_exists(&l, game);
	game->map.rows = count_matrix_lines(l, game);
	game->map.matrix = malloc(sizeof(char *) * (game->map.rows + 1));
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
	game->map.cols = get_map_cols(game->map.matrix);
}
