/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:30:20 by jrubio-m          #+#    #+#             */
/*   Updated: 2023/12/01 18:30:24 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*line_until_jump(char *line)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = 0;
	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == 0)
		return (line);
	i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	while (i > 0)
	{
		str[j] = line[j];
		j++;
		i--;
	}
	str[j] = '\0';
	return (free (line), str);
}

static int	ft_isjump(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	read_file(int fd, char *stat)
{
	int		i;

	i = read(fd, stat, BUFFER_SIZE);
	if (i < 0)
		return (-1);
	stat[i] = '\0';
	return (i);
}

char	*make_line(char *line, char *stat, int i)
{
	char	*aux;

	if (!line)
	{
		if (i <= 0)
		{
			stat[0] = '\0';
			return (NULL);
		}
		aux = ft_strdup(stat);
	}
	else
	{
		if (i < 0)
		{
			stat[0] = '\0';
			return (free(line), NULL);
		}
		aux = ft_strjoin(line, stat);
		free(line);
	}
	return (aux);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	stat[BUFFER_SIZE + 1];
	int			i;

	i = 1;
	line = NULL;
	if (fd < 0)
		return (NULL);
	if (stat[0])
		line = make_line(line, stat, 1);
	while (i != 0)
	{
		if (!ft_isjump(stat))
			i = read_file(fd, stat);
		line = make_line(line, stat, i);
		if (!line)
			return (NULL);
		if (ft_isjump(line))
			break ;
	}
	line = line_until_jump(line);
	newstat(stat);
	return (line);
}
