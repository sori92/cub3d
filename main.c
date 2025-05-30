/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:30:09 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/30 23:18:50 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	error_in_args(int argc, char **argv)
{
	char	*map_file;

	if (argc != 2)
		return (print_error("Invalid number of args\n"
				"Expected: ./cub3D example.cub\n"));
	map_file = ft_strdup(argv[1]);
	if (!map_file)
		return (1);
	if (!extension_check(map_file, ".cub"))
	{
		free(map_file);
		return (print_error("Wrong map extension\n"));
	}
	free(map_file);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub	game;

	if (error_in_args(argc, argv))
		return (1);
	init_null(&game);
	init(&game, ft_strdup(argv[1]));
	parser(&game);
	init_display(&game);
	mlx_hook(game.mlx.win, KeyPress, KeyPressMask, handle, &game);
	mlx_hook(game.mlx.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx.ptr);
	free_all(&game);
	return (0);
}
