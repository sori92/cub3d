/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:20:11 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/30 13:29:59 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	extension_check(char *str, char *ext)
{
	size_t	i;
	size_t	j;
	int		is;

	is = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (ext[j] && str[i] && str[i] == ext[j])
		{
			j++;
			i++;
		}
		if (j == ft_strlen(ext) && str[i])
			return (0);
		if (str[i])
			i++;
	}
	if (j == ft_strlen(ext))
		is = 1;
	return (is);
}
