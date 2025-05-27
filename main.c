/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:30:09 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/27 18:44:16 by jrubio-m         ###   ########.fr       */
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
		while (cub[j] && str[i] == cub[j])
		{
			j++;
			i++;
		}
		if (j == ft_strlen(cub) && str[i])
			return (0);
		i++;
	}
	if (j == ft_strlen(cub))
		is = 1;
	return (is);
}

int	error_in_args(int argc, char **argv)
{
	if (argc != 2)
		return (print_error("Invalid number of args\n"
				"Expected: ./cub3D example.cub"));
	if (!is_cub(strdup(argv[1]), ".cub"))
		return (print_error("Wrong map extension\n"));
	return (0);
}

void	init(t_cub	*cub, char *map_file)
{
	cub->map = create_map(map_file);
}

int	main(int argc, char **argv)
{
	t_cub cube;

	cube.mlx.ptr = NULL;
	cube.mlx.win = NULL;
	if (error_in_args(argc, argv))
		return (1);
	init(&cube, argv[1]);
	return (0);
}
