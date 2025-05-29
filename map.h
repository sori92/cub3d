/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:31:50 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/29 17:56:47 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "cub3d.h"

/*
 * MIRAR MEJOR FORMA DE GUARDAR ESTO!!	
 */

typedef struct s_paths
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_paths;

typedef struct s_rgb
{
	char	*f;
	int		fr;
	int		fg;
	int		fb;
	char	*c;
	int		cr;
	int		cg;
	int		cb;
}	t_rgb;

typedef struct s_map
{
	t_paths	paths;
	t_rgb	color;
	char	**matrix;
	char	**file_array;
}	t_map;

#endif