/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printarray.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 15:14:32 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/30 13:30:38 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_printarray(char **array, char *name)
{
	size_t	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		printf("%s[%ld] --> %s[%ld]\n", name, i, array[i], ft_strlen(array[i]));
		i++;
	}
}
