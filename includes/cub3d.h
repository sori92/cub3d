/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:29:56 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/06/17 19:57:12 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stddef.h>
# include <math.h>
# include "map.h"
# include "player.h"
# include "minilbx.h"

# define SPEED 0.05
# define PL_RAD 0.3
# define WIDTH  1920
# define HEIGHT 1080
# define PI 3.14159265358979323846
# define INPUT_DELAY 0.1

typedef struct s_keys
{
	int	w;
	int	s;
	int	a;
	int	d;
	int	r;
	int	l;
}	t_keys;

typedef struct s_tx
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bpp;
	int		line_length;
	int		endian;
}	t_tx;

typedef struct s_imges
{
	t_tx	north;
	t_tx	south;
	t_tx	east;
	t_tx	west;
}	t_imges;

typedef struct s_draw
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
}	t_draw;

typedef struct s_rend
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_x;
	double	delta_y;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;	
	int		step_y;
	int		side;
	double	perp_dist;
	t_draw	draw;
}	t_rend;

typedef struct s_cub
{
	t_rend	rend;
	t_imges	tex;
	t_keys	keys;
	t_plyr	plyr;
	t_mlx	mlx;
	t_map	map;
	double	input_cnt;
}	t_cub;

// UTILS
int		str_is_digit(char *str);
char	**split_by_space(char *str);
size_t	ft_arraylen(char **array);
void	ft_printarray(char **array, char *name);
char	**ft_arraydup(char **array);
//

// ERRORS
int		print_error(char *str);
//

// FREE
void	free_mlx(t_cub *game);
void	free_array(char **array, size_t len);
void	free_all(t_cub *game);
//

// MAP
char	**create_map_file_array(char *map_file);
char	*fill_path(char **line, char *cardinal, t_cub *game);
size_t	cpy_paths_and_colors(t_cub *game);
void	asign_paths(t_cub *game, char **line);

void	make_map_matrix(size_t l, t_cub *game);
//

// PLAYER
void	init_player(t_cub *game);
int		move_fward(t_cub *game, int dir);
int		move_side(t_cub *game, int dir);
int		rotation(t_cub *game, int dir);
void	update_planes(t_cub *game);
//

// DISPLAY
void	render(t_cub *game);
void	dda(t_cub *game, t_rend *rend, int map_x, int map_y);
void	calc_texture_size(t_rend *rend);
t_tx	*texture_orientation(t_cub *game, t_rend *rend);
void	calc_texture_collision_point(t_tx *tex, t_cub *game, t_rend *rend);
void	draw_floor_and_ceilling(t_cub *game);
void	draw_cell(t_cub *game, size_t y, size_t x, int color);
void	draw_back(t_cub *game, size_t y, size_t x, int color);
void	draw_map(t_cub *game);
void	draw_win(t_cub *game);
void	pixel_put(size_t x, size_t y, int color, t_cub *game);
//

// PARSERS
void	clean_matrix(t_cub *game);
void	clean_paths_and_colors(t_cub *game);
char	*errase_newline(char *str);
int		flood_fill(char **map, int y, int x, int lnes);
void	check_for_player(t_cub *game);
void	check_texture_routes_and_colors(t_cub *game);
void	check_chars_and_empty_lines(t_cub *game);
int		extension_check(char *str, char *ext);
void	parser(t_cub *game);
//

// INIT
void	init(t_cub	*game, char *map_file);
void	init_null(t_cub *game);
//

// MLX
void	init_display(t_cub *game);
int		close_window(t_cub *game);
int		handle(int key, t_cub *game);
int		handle_keys(t_cub *game);
//

#endif