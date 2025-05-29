/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:08:48 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/29 18:31:20 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map_struct(t_cub *game)
{
	size_t	l;

	l = cpy_paths_and_colors(game);
	if (!game->map.paths.no || !game->map.paths.so || !game->map.paths.we
		|| !game->map.paths.ea || !game->map.color.f || !game->map.color.c)
	{
		free_all(game);
		exit (print_error("Wrong map file structure\n"));
	}
	make_map_matrix(l, game);
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

void	init_null(t_cub *game)
{
	game->map.file_array = NULL;
	game->map.paths.no = NULL;
	game->map.paths.so = NULL;
	game->map.paths.ea = NULL;
	game->map.paths.we = NULL;
	game->map.color.f = NULL;
	game->map.color.c = NULL;
	game->map.matrix = NULL;
	game->mlx.ptr = NULL;
	game->mlx.win = NULL;
}
