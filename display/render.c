#include "../includes/cub3d.h"

static void	draw_floor_and_ceilling(t_cub *game)
{
	size_t	x;
	size_t	y;
	size_t	f_color;
	size_t	c_color;

	f_color = (game->map.color.floor.r << 16)
		| (game->map.color.floor.g << 8)
		| game->map.color.floor.b;
	c_color = (game->map.color.ceiling.r << 16)
		| (game->map.color.ceiling.g << 8)
		| game->map.color.ceiling.b;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				pixel_put(x, y, c_color, game);
			else
				pixel_put(x, y, f_color, game);
			x++;
		}
		y++;
	}
}

void	render_3d(t_cub *game)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	t_tx	*tex;
	int		color;

	x = 0;
	while (x < WIDTH)
	{
		camera_x = 2.0 * x / (double)WIDTH - 1.0;
		ray_dir_x = game->plyr.dir_x + game->plyr.plane_x * camera_x;
		ray_dir_y = game->plyr.dir_y + game->plyr.plane_y * camera_x;
		map_x = (int)game->plyr.pos_x;
		map_y = (int)game->plyr.pos_y;
		if (ray_dir_x != 0)
			delta_dist_x = fabs(1 / ray_dir_x);
		else
			delta_dist_x = 1e30;

		if (ray_dir_y != 0)
			delta_dist_y = fabs(1 / ray_dir_y);
		else
			delta_dist_y = 1e30;

		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (game->plyr.pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - game->plyr.pos_x) * delta_dist_x;
		}

		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (game->plyr.pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - game->plyr.pos_y) * delta_dist_y;
		}

		hit = 0;
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (game->map.matrix[map_y][map_x] == '1')
				hit = 1;
		}

		if (side == 0)
			perp_wall_dist = (map_x - game->plyr.pos_x + (1.0 - step_x) / 2.0) / ray_dir_x;
		else
			perp_wall_dist = (map_y - game->plyr.pos_y + (1.0 - step_y) / 2.0) / ray_dir_y;

		line_height = (int)(HEIGHT / perp_wall_dist);

		draw_start = -line_height / 2 + HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;

		draw_end = line_height / 2 + HEIGHT / 2;
		if (draw_end >= HEIGHT)
			draw_end = HEIGHT - 1;

		// Selecciona textura
		if (side == 0)
		{
			if (step_x > 0)
				tex = &game->tex.east;
			else
				tex = &game->tex.west;
		}
		else
		{
			if (step_y > 0)
				tex = &game->tex.south;
			else
				tex = &game->tex.north;
		}

		// Punto exacto de impacto en la pared
		if (side == 0)
			wall_x = game->plyr.pos_y + perp_wall_dist * ray_dir_y;
		else
			wall_x = game->plyr.pos_x + perp_wall_dist * ray_dir_x;

		wall_x -= floor(wall_x);

		tex_x = (int)(wall_x * tex->width);
		if (tex_x < 0)
			tex_x = 0;
		if (tex_x >= tex->width)
			tex_x = tex->width - 1;

		if ((side == 0 && ray_dir_x > 0) || (side == 1 && ray_dir_y < 0))
			tex_x = tex->width - tex_x - 1;

		// Cálculo incremento en textura
		step = (double)tex->height / line_height;
		tex_pos = (draw_start - HEIGHT / 2 + line_height / 2) * step;

		int y = draw_start;
		while (y < draw_end)
		{
			tex_y = (int)tex_pos;
			if (tex_y < 0)
				tex_y = 0;
			if (tex_y >= tex->height)
				tex_y = tex->height - 1;

			tex_pos += step;

			color = *(unsigned int *)(tex->addr + tex_y * tex->line_length + tex_x * (tex->bpp / 8));

			if (side == 1)
				color = (color >> 1) & 0x7F7F7F;

			pixel_put(x, y, color, game);
			y++;
		}
		x++;
	}
}
//HACERLO BIENN!!!

void	render(t_cub *game)
{
	draw_floor_and_ceilling(game);
	render_3d(game);
}
