/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:29:56 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/27 21:00:13 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stddef.h>
# include "map.h"

typedef struct s_mlx
{
	void	*win;
	void	*ptr;
}	t_mlx;

typedef struct s_cub
{
	t_mlx	mlx;
	t_map	map;
}	t_cub;

char	**create_map(char *map_file);
int		print_error(char *str);
void	free_array(char **array, size_t len);
void	free_all(t_cub *game);
size_t	ft_arraylen(char **array);
void	ft_printarray(char **array, char *name);
#endif