/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 13:13:16 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/07/03 13:15:00 by dsoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_tex_aux(t_cub *game)
{
	game->tex.door.img
		= mlx_xpm_file_to_image(game->mlx.ptr, game->map.paths.door,
			&game->tex.door.width, &game->tex.door.height);
	game->tex.door.addr
		= mlx_get_data_addr(game->tex.door.img, &game->tex.door.bpp,
			&game->tex.door.line_length, &game->tex.door.endian);
	game->tex.opened.img
		= mlx_xpm_file_to_image(game->mlx.ptr, game->map.paths.opened,
			&game->tex.opened.width, &game->tex.opened.height);
	game->tex.opened.addr
		= mlx_get_data_addr(game->tex.opened.img, &game->tex.opened.bpp,
			&game->tex.opened.line_length, &game->tex.opened.endian);
}

static void	init_tex(t_cub *game)
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
	init_tex_aux(game);
}

void	weapon_textures_load(t_cub *game)
{
	int		i;
	char	*nb;
	char	*path;
	char	*final_path;

	i = 0;
	while (i < game->weapon.fr_count)
	{
		nb = ft_itoa(i);
		path = ft_strjoin("./textures/weapon/Torch_0", nb);
		free(nb);
		final_path = ft_strjoin(path, ".xpm");
		free(path);
		game->weapon.frames[i] = mlx_xpm_file_to_image(game->mlx.ptr,
				final_path, &game->weapon.size_w, &game->weapon.size_h);
		if (!game->weapon.frames[i])
		{
			free_all(game);
			exit (print_error("loading the weapon frames\n"));
		}
		free(final_path);
		i++;
	}
}

void	init_weapon(t_cub *game)
{
	game->weapon.fr_count = 4;
	game->weapon.frames = malloc(sizeof(void *) * game->weapon.fr_count);
	game->weapon.fr_current = 0;
	game->weapon.fr_delay = 5;
	game->weapon.counter = 0;
	game->weapon.size_w = 0;
	game->weapon.size_h = 0;
	weapon_textures_load(game);
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
