/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:31:50 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/07/03 13:12:02 by dsoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "cub3d.h"

typedef struct s_paths
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*door;
	char	*opened;
}	t_paths;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_clr
{
	char	*f;
	t_rgb	floor;
	char	*c;
	t_rgb	ceiling;
}	t_clr;

typedef struct s_map
{
	t_paths	paths;
	t_clr	color;
	size_t	rows;
	size_t	cols;
	char	**matrix;
	char	**file_array;
}	t_map;

#endif