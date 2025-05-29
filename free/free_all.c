/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:22:59 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/29 14:35:34 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	if (game->map.color.f)
		free(game->map.color.f);
	if (game->map.color.c)
		free(game->map.color.c);
	if (game->map.matrix)
		free_array(game->map.matrix, ft_arraylen(game->map.matrix));
}
