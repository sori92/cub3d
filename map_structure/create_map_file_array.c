#include "../cub3d.h"

size_t	count_lines(char *map_file)
{
	size_t	nlines;
	char	*line;
	int		fd;

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

	lnes = count_lines(map_file); // Cuento las lineas para posterior malloc
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