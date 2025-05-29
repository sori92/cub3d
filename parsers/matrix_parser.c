#include "../cub3d.h"

static void	check_char(char c, t_cub *game)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == ' ')
		return ;
	free_all(game);
	exit(print_error("Wrong character found in map matrix\n"));
}

void	check_chars_and_empty_lines(t_cub *game)
{
	size_t	y;
	size_t	x;

	y = 0;
	while(game->map.matrix[y])
	{
		x = 0;
		if (game->map.matrix[y][x] == '\n')
		{
			free_all(game);
			exit(print_error("Empty line in the map matrix\n"));
		}
		while (game->map.matrix[y][x] && game->map.matrix[y][x] != '\n')
		{
			check_char(game->map.matrix[y][x], game);
			x++;
		}
		y++;
	}
}