/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_nl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:18:02 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/07/02 17:35:47 by dsoriano         ###   ########.fr       */
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
