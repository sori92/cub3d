#ifndef PLAYER_H
# define PLAYER_H
# include <stdlib.h>

typedef struct s_plyr
{
	size_t	x;
	size_t	y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_plyr;

#endif
