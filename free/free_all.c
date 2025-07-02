/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:22:59 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/07/01 16:38:31 by dsoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_mlx(t_cub *game)
{
	if (game->mlx.ptr)
	{
		if (game->mlx.win)
		{
			if (game->mlx.img)
				mlx_destroy_image(game->mlx.ptr, game->mlx.img);
			mlx_clear_window(game->mlx.ptr, game->mlx.win);
			mlx_destroy_window(game->mlx.ptr, game->mlx.win);
		}
		mlx_destroy_display(game->mlx.ptr);
		free(game->mlx.ptr);
	}
}

void	free_all(t_cub *game)
{
	if (game->map.file_array)
		free_array(game->map.file_array, ft_arraylen(game->map.file_array));
	if (game->map.paths.no)
		free(game->map.paths.no);
	if (game->map.paths.so)
		free(game->map.paths.so);
	if (game->map.paths.we)
		free(game->map.paths.we);
	if (game->map.paths.ea)
		free(game->map.paths.ea);
	if (game->map.paths.door)
		free(game->map.paths.door);
	if (game->map.color.f)
		free(game->map.color.f);
	if (game->map.color.c)
		free(game->map.color.c);
	if (game->map.matrix)
		free_array(game->map.matrix, ft_arraylen(game->map.matrix));
	free_mlx(game);
}
