/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:56:01 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/28 14:51:45 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*a;

	if (n != 0 && (n * size) / n != size)
		return (0);
	a = malloc(n * size);
	if (!a)
		return (NULL);
	ft_bzero(a, n * size);
	return (a);
}
