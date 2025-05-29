/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 19:29:56 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/29 14:18:09 by jrubio-m         ###   ########.fr       */
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


// UTILS
char	**split_by_space(char *str);
size_t	ft_arraylen(char **array);
void	ft_printarray(char **array, char *name);
//

// ERRORS
int		print_error(char *str);
//

// FREE
void	free_array(char **array, size_t len);
void	free_all(t_cub *game);
//

// MAP
char	**create_map_file_array(char *map_file);
void	init_map_struct(t_cub *game);

char	*fill_path(char **line, char *cardinal, t_cub *game);
size_t	cpy_paths_and_colors(t_cub *game);
void	asign_paths(t_cub *game, char **line);

void	make_map_matrix(size_t l, t_cub *game);
//

// INIT
void	init(t_cub	*game, char *map_file);
void	init_null(t_cub *game);
//
#endif