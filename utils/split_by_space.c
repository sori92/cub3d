/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 23:36:49 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/30 13:30:41 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	word_count(char *str)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'
				|| str[i] == '\r'))
			i++;
		if (str[i])
			w++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t'
				&& str[i] != '\r'))
			i++;
	}
	return (w);
}

static char	**ft_make_array(char **array, char *str, int w, int i)
{
	int	j;

	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		j = i;
		while (str[i] && (str[i] != ' ' && str[i] != '\t'))
			i++;
		if (i > j)
		{
			array[w] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			if (!array[w])
			{
				free_array(array, w);
				return (NULL);
			}
			ft_strncpy(array[w], &str[j], i - j);
			w++;
		}
	}
	array[w] = NULL;
	return (array);
}

char	**split_by_space(char *str)
{
	char	**array;
	int		w;

	w = 0;
	if (!str)
		return (NULL);
	array = NULL;
	w = word_count(str);
	array = malloc(sizeof(char *) * (w + 1));
	if (!array)
		return (NULL);
	array = ft_make_array(array, str, 0, 0);
	return (array);
}
