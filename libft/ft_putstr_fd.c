/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 08:42:49 by jrubio-m          #+#    #+#             */
/*   Updated: 2023/10/27 08:42:52 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		if (write(fd, &s[i], 1) == -1)
			return (-1);
		i++;
		len++;
	}
	return (len);
}
