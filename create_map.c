#include "cub3d.h"

size_t	count_lines(char *map_file)
{
	int		fd;
	size_t	nlines;
	char	*line;

	nlines = 0;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		print_error("Can't open map file\n");
		return (0);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n')
			nlines++;
		free(line);
		line = get_next_line(fd);
	}
	if (nlines < 1)
		print_error("Empty map file\n");
	return (nlines);
}

char	**create_map(char *map_file)
{
	size_t	lnes;

	lnes = count_lines(map_file); // Cuento las lineas para posterior malloc
	if (lnes == 0)
		return (NULL);
	// Crear array aquí

	return (NULL); // Devuelvo NULL de momento para pruebas
}