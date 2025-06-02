/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:30:09 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/06/02 22:35:32 by jrubio-m         ###   ########.fr       */
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

int	key_press(int key, t_cub *game)
{
	if (key == XK_a)
		game->keys.a = 1;
	if (key == XK_d)
		game->keys.d = 1;
	if (key == XK_w)
		game->keys.w = 1;
	if (key == XK_s)
		game->keys.s = 1;
	if (key == XK_Left)
		game->keys.l = 1;
	if (key == XK_Right)
		game->keys.r = 1;
	return (1);
}

int	key_released(int key, t_cub *game)
{
	if (key == XK_a)
		game->keys.a = 0;
	if (key == XK_d)
		game->keys.d = 0;
	if (key == XK_w)
		game->keys.w = 0;
	if (key == XK_s)
		game->keys.s = 0;
	if (key == XK_Left)
		game->keys.l = 0;
	if (key == XK_Right)
		game->keys.r = 0;
	return (1);
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
	mlx_hook(game.mlx.win, KeyPress, KeyPressMask, key_press, &game);
	mlx_hook(game.mlx.win, KeyRelease, KeyReleaseMask, key_released, &game);
	mlx_loop_hook(game.mlx.ptr, handle_keys, &game);
	mlx_hook(game.mlx.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx.ptr);
	free_all(&game);
	return (0);
}
