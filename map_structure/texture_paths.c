/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:34:42 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/07/01 17:14:52 by dsoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*fill_path(char **line, char *cardinal, t_cub *game)
{
	char	*field;

	field = NULL;
	if (ft_arraylen(line) != 2)
	{
		free_array(line, ft_arraylen(line));
		free_all(game);
		print_error("Texture paths must contain two arguments\n");
		exit(ft_putstr_fd("[NO/SO/WE/EA/D] [./textures/file]\n", 2));
	}
	if (ft_strcmp(line[0], cardinal) == 0)
	{
		field = ft_strdup(line[1]);
		if (!field)
		{
			free_array(line, ft_arraylen(line));
			free_all(game);
			print_error("Can't create texture path array\n");
		}
	}
	return (field);
}

char	*color_aux_func(char **line, t_cub *game)
{
	char	*field;
	char	*aux0;

	field = NULL;
	if (ft_arraylen(line) == 2)
	{
		field = ft_strdup(line[1]);
		if (!field)
		{
			free_array(line, ft_arraylen(line));
			free_all(game);
			print_error("Can't create texture path array\n");
			return (NULL);
		}
		return (field);
	}
	if (line[2])
		aux0 = ft_strjoin(line[1], line[2]);
	if (line[3])
		field = ft_strjoin(aux0, line[3]);
	else
		return (aux0);
	free(aux0);
	return (field);
}

char	*fill_color(char **line, char *to_fill, t_cub *game)
{
	char	*field;

	field = NULL;
	if (ft_arraylen(line) < 2 || ft_arraylen(line) > 4)
	{
		free_array(line, ft_arraylen(line));
		free_all(game);
		print_error("Floor and Ceiling fields must be in the format :");
		ft_putendl_fd(" [F/C] [255,255,255]", 2);
		exit(1);
	}
	if (ft_strcmp(line[0], to_fill) == 0)
		field = color_aux_func(line, game);
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
	if (!game->map.paths.door)
		game->map.paths.door = fill_path(line, "D", game);
	if (!game->map.color.f)
		game->map.color.f = fill_color(line, "F", game);
	if (!game->map.color.c)
		game->map.color.c = fill_color(line, "C", game);
}

size_t	cpy_paths_and_colors(t_cub *game)
{
	size_t	i;
	size_t	l;
	char	**line;

	i = 0;
	l = 0;
	while (game->map.file_array[l] && i < 7)
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
