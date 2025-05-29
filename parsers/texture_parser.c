#include "../cub3d.h"

int	wrong_texture_file(char *texture, char *type)
{
	int	fd;

	fd = open(texture, O_RDONLY);
	if (fd < 0)
	{
		print_error(type);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("Can't open the file: ", 2);
		ft_putendl_fd(texture, 2);
		return (1);
	}
	close(fd);
	return (0);
}

int wrong_rgb_range(char *field, char **rgb)
{
	size_t	i;

	i = 0;
	while (rgb[i])
	{
		if (!str_is_digit(rgb[i]) || ft_arraylen(rgb) != 3)
		{
			free_array(rgb, ft_arraylen(rgb));
			print_error(field);
			ft_putendl_fd(" must contain three numeric parameters", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_and_asign_colors(t_cub *game)
{
	char	**rgb;
	int		ret;

	ret = 1;
	rgb = ft_split(game->map.color.f, ',');
	if (wrong_rgb_range("Floor", rgb))
		ret = 0;
	else
	{
		game->map.color.fr = ft_atoi(rgb[0]);
		game->map.color.fg = ft_atoi(rgb[1]);
		game->map.color.fb = ft_atoi(rgb[2]);
		free_array(rgb, ft_arraylen(rgb));
	}
	rgb = ft_split(game->map.color.c, ',');
	if (wrong_rgb_range("Celine", rgb))
		ret = 0;
	else
	{
		game->map.color.cr = ft_atoi(rgb[0]);
		game->map.color.cg = ft_atoi(rgb[1]);
		game->map.color.cb = ft_atoi(rgb[2]);
		free_array(rgb, ft_arraylen(rgb));
	}
	return (ret);
}

void	check_texture_routes_and_colors(t_cub *game)
{
	int	error;

	error = 0;
	if (wrong_texture_file(game->map.paths.no, "NO"))
		error = 1;
	if (wrong_texture_file(game->map.paths.so, "SO"))
		error = 1;
	if (wrong_texture_file(game->map.paths.we, "WE"))
		error = 1;
	if (wrong_texture_file(game->map.paths.ea, "EA"))
		error = 1;
	if (!check_and_asign_colors(game))
		error = 1;
	if (error == 0)
		return ;
	free_all(game);
	exit (1);
}
