/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:30:09 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/27 21:00:19 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_cub(char *str, char *cub)
{
	size_t	i;
	size_t	j;
	int		is;

	is = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (cub[j] && str[i] && str[i] == cub[j])
		{
			j++;
			i++;
		}
		if (j == ft_strlen(cub) && str[i])
			return (0);
		if (str[i])
			i++;
	}
	if (j == ft_strlen(cub))
		is = 1;
	return (is);
}

int	error_in_args(int argc, char **argv)
{
	char	*map_file;
	
	if (argc != 2)
		return (print_error("Invalid number of args\n"
			"Expected: ./cub3D example.cub"));
	map_file = ft_strdup(argv[1]);
	if (!map_file)
		return (1);
	if (!is_cub(map_file, ".cub"))
	{
		free(map_file);
		return (print_error("Wrong map extension\n"));
	}
	free(map_file);
	return (0);
}

void	init(t_cub	*cube, char *map_file)
{
	char	*file;

	file = ft_strdup(map_file);
	if (!file)
	{
		free(map_file);
		print_error("Error of ft_strdup in init\n");
		exit(1);
	}
	cube->map.file_array = create_map(file);
	free(file);
	if (!cube->map.file_array)
	{
		free_all(cube);
		exit (1);
	}
	ft_printarray(cube->map.file_array, "map");
}

int	main(int argc, char **argv)
{
	t_cub	cube;

	cube.mlx.ptr = NULL;
	cube.mlx.win = NULL;
	if (error_in_args(argc, argv))
		return (1);
	init(&cube, argv[1]);
	free_all(&cube);
	return (0);
}
