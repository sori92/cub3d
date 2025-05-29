#include "../cub3d.h"

int	close_window(t_cub *game)
{
	free_all(game);
	exit(0); // Cierra el programa
	return (0);
}