/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:30:09 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/29 14:37:27 by jrubio-m         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_cub	game;

	if (error_in_args(argc, argv))
		return (1);
	init_null(&game);
	init(&game, ft_strdup(argv[1]));
	ft_printarray(game.map.matrix, "map");
	free_all(&game);
	return (0);
}
