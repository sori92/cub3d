/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 00:24:07 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/30 13:30:28 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**ft_arraydup(char **array)
{
	size_t	i;
	char	**new_array;

	i = 0;
	new_array = malloc(sizeof(char *) * (ft_arraylen(array) + 1));
	if (!new_array)
		return (NULL);
	while (array[i])
	{
		new_array[i] = ft_strdup(array[i]);
		if (!new_array[i])
		{
			free_array(new_array, i);
			return (NULL);
		}
		i++;
	}
	new_array[i] = NULL;
	return (new_array);
}
