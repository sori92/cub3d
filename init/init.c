/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:08:48 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/07/01 16:41:19 by dsoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	calc_map_offsets(t_cub *game)
{
	game->offsets[0] = 30; //(WIDTH - (game->map.cols * CELL_SIZE)) / 2;
	game->offsets[1] = HEIGHT - (game->map.rows * CELL_SIZE) - 30; 
}

static void	init_map_struct(t_cub *game)
{
	size_t	l;

	l = cpy_paths_and_colors(game);
	if (!game->map.paths.no || !game->map.paths.so || !game->map.paths.we
		|| !game->map.paths.ea || !game->map.paths.door || !game->map.color.f || !game->map.color.c)
	{
		free_all(game);
		exit (print_error("Wrong map file structure\n"));
	}
	make_map_matrix(l, game);
	calc_map_offsets(game);
}


void	init(t_cub	*game, char *map_file)
{
	if (!map_file)
	{
		print_error("Error of ft_strdup in init\n");
		exit(1);
	}
	game->map.file_array = create_map_file_array(map_file);
	free(map_file);
	if (!game->map.file_array)
		exit (1);
	init_map_struct(game);
}
