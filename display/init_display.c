/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:13:16 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/06/30 13:25:11 by dsoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pixel_put(size_t x, size_t y, int color, t_cub *game)
{
	char	*dst;

	dst = game->mlx.addr
		+ (y * game->mlx.line_length + x * (game->mlx.bpp / 8));
	*(unsigned int *)dst = color;
}

void	init_tex(t_cub *game)
{
	game->tex.north.img
		= mlx_xpm_file_to_image(game->mlx.ptr, game->map.paths.no,
			&game->tex.north.width, &game->tex.north.height);
	game->tex.north.addr
		= mlx_get_data_addr(game->tex.north.img, &game->tex.north.bpp,
			&game->tex.north.line_length, &game->tex.north.endian);
	game->tex.south.img
		= mlx_xpm_file_to_image(game->mlx.ptr, game->map.paths.so,
			&game->tex.south.width, &game->tex.south.height);
	game->tex.south.addr
		= mlx_get_data_addr(game->tex.south.img, &game->tex.south.bpp,
			&game->tex.south.line_length, &game->tex.south.endian);
	game->tex.west.img
		= mlx_xpm_file_to_image(game->mlx.ptr, game->map.paths.we,
			&game->tex.west.width, &game->tex.west.height);
	game->tex.west.addr
		= mlx_get_data_addr(game->tex.west.img, &game->tex.west.bpp,
			&game->tex.west.line_length, &game->tex.west.endian);
	game->tex.east.img
		= mlx_xpm_file_to_image(game->mlx.ptr, game->map.paths.ea,
			&game->tex.east.width, &game->tex.east.height);
	game->tex.east.addr
		= mlx_get_data_addr(game->tex.east.img, &game->tex.east.bpp,
			&game->tex.east.line_length, &game->tex.east.endian);
}

void	init_weapon(t_cub *game)
{
	int		i;
	char	*path;
	char 	*final_path;
	char	*nb;

	game->weapon.fr_count = 4;
	game->weapon.frames = malloc(sizeof(void *) * game->weapon.fr_count);
	game->weapon.fr_current = 0;
	game->weapon.fr_delay = 5;
	game->weapon.counter = 0;
	game->weapon.size_w = 0;
	game->weapon.size_h = 0;

	i = 0;
	while (i < game->weapon.fr_count)
	{
		nb = ft_itoa(i);
		path = ft_strjoin("textures/weapon/Torch_0", nb);
		free(nb);
		final_path = ft_strjoin(path, ".xpm");
		free(path);
		game->weapon.frames[i] = mlx_xpm_file_to_image(game->mlx.ptr, final_path, &game->weapon.size_w, &game->weapon.size_h);
		if (!game->weapon.frames[i])
		{
			free_all(game);
			exit (print_error("loading the weapon frames\n"));
		}
		free(final_path);
		i++;
	}
}

void	init_display(t_cub *game)
{
	game->mlx.ptr = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.ptr, WIDTH, HEIGHT, "GAME");
	game->mlx.img = mlx_new_image(game->mlx.ptr, WIDTH, HEIGHT);
	game->mlx.addr = mlx_get_data_addr(game->mlx.img, &game->mlx.bpp,
			&game->mlx.line_length, &game->mlx.endian);
	init_weapon(game);
	init_tex(game);
	draw_win(game);
}
