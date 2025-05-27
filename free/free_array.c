/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:22:53 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/27 20:22:53 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_int_array(int **array, size_t len)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (i < len)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_array(char **array, size_t len)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (i < len)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
