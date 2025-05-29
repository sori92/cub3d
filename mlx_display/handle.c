#include "../cub3d.h"

int	handle(int key, t_cub *game)
{
	if (key == XK_Escape)
		return (close_window(game));
	return (0);
}
