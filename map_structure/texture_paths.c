/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:34:42 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/29 15:34:42 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*fill_path(char **line, char *cardinal, t_cub *game)
{
	char	*field;

	field = NULL;
	if (ft_arraylen(line) != 2)
	{
		free_array(line, ft_arraylen(line));
		free_all(game);
		print_error("Texture paths must contain two arguments\n");
		exit(ft_putstr_fd("[NO/SO/WE/EA] [./textures/file]\n", 2));
	}
	if (ft_strcmp(line[0], cardinal) == 0)
	{
		field = ft_strdup(line[1]);
		if (!field)
		{
			free_array(line, ft_arraylen(line));
			free_all(game);
			print_error("Can't create NO texture path array\n");
		}
	}
	return (field);
}

void	asign_paths(t_cub *game, char **line)
{
	if (!game->map.paths.no)
		game->map.paths.no = fill_path(line, "NO", game);
	if (!game->map.paths.so)
		game->map.paths.so = fill_path(line, "SO", game);
	if (!game->map.paths.we)
		game->map.paths.we = fill_path(line, "WE", game);
	if (!game->map.paths.ea)
		game->map.paths.ea = fill_path(line, "EA", game);
	if (!game->map.color.f)
		game->map.color.f = fill_path(line, "F", game);
	if (!game->map.color.c)
		game->map.color.c = fill_path(line, "C", game);
}

size_t	cpy_paths_and_colors(t_cub *game)
{
	size_t	i;
	size_t	l;
	char	**line;

	i = 0;
	l = 0;
	while (game->map.file_array[l] && i < 6)
	{
		line = split_by_space(game->map.file_array[l]);
		if (!line)
		{
			free_all(game);
			exit(print_error("Error in malloc doing split"));
		}
		if (line[0][0] != '\n')
			asign_paths(game, line);
		free_array(line, ft_arraylen(line));
		if (game->map.file_array[l][0] != '\n')
			i++;
		l++;
	}
	return (l);
}
