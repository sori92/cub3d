/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 18:30:31 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/28 15:17:11 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	newstat(char *stat)
{
	while (stat[0] && stat[0] != '\n')
		ft_strlcpy(stat, stat + 1, ft_strlen(stat));
	if (stat[0] == '\n')
		ft_strlcpy(stat, stat + 1, ft_strlen(stat));
}
