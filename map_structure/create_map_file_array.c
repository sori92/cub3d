/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_file_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:34:37 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/29 18:35:27 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_directory(char *map_file)
{
	int fd;
	
	fd = open(map_file, __O_DIRECTORY);
	if (fd > -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

size_t	count_lines(char *map_file)
{
	size_t	nlines;
	char	*line;
	int		fd;

	if (is_directory(map_file))
	{
		print_error("Map argument is a directory\n");
		return (0);
	}
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		print_error("Can't open map file\n");
		return (0);
	}
	nlines = 0;
	line = get_next_line(fd);
	while (line)
	{
		nlines++;
		free(line);
		line = get_next_line(fd);
	}
	if (nlines < 1)
		print_error("Empty map file\n");
	close(fd);
	return (nlines);
}

char	**create_map_array(int fd, size_t len, size_t i)
{
	char	**map;

	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
	{
		print_error("Error in malloc making map array");
		return (NULL);
	}
	map[i] = get_next_line(fd);
	while (i < len && map[i])
	{
		i++;
		map[i] = get_next_line(fd);
	}
	map[len] = NULL;
	return (map);
}

char	**create_map_file_array(char *map_file)
{
	size_t	lnes;
	char	**map;
	int		fd;

	lnes = count_lines(map_file);
	if (lnes == 0)
		return (NULL);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		print_error("Can't open map file after counting lines\n");
		return (0);
	}
	map = create_map_array(fd, lnes, 0);
	if (!map)
		return (NULL);
	close(fd);
	return (map);
}
