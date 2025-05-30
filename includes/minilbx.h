/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilbx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 14:50:49 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/30 14:50:51 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILBX_H
# define MINILBX_H

typedef struct s_mlx
{
	void	*win;
	void	*ptr;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_mlx;

#endif
