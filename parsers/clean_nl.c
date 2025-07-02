/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_nl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:18:02 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/07/01 17:17:53 by dsoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	clean_matrix(t_cub *game)
{
	size_t	y;

	y = 0;
	while (game->map.matrix[y])
	{
		game->map.matrix[y] = errase_newline(game->map.matrix[y]);
		y++;
	}
}

char	*errase_newline(char *str)
{
	size_t	len;
	size_t	i;
	char	*clean;

	i = 0;
	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (len == ft_strlen(str))
		return (str);
	clean = malloc(sizeof(char) * (len + 1));
	while (str[i] && str[i] != '\n')
	{
		clean[i] = str[i];
		i++;
	}
	clean[i] = '\0';
	free(str);
	return (clean);
}

void	clean_paths_and_colors(t_cub *game)
{
	game->map.paths.no = errase_newline(game->map.paths.no);
	game->map.paths.so = errase_newline(game->map.paths.so);
	game->map.paths.ea = errase_newline(game->map.paths.ea);
	game->map.paths.we = errase_newline(game->map.paths.we);
	game->map.paths.door = errase_newline(game->map.paths.door);
	game->map.color.f = errase_newline(game->map.color.f);
	game->map.color.c = errase_newline(game->map.color.c);
}
