/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsoriano <dsoriano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:52:11 by dsoriano          #+#    #+#             */
/*   Updated: 2025/07/03 14:56:25 by dsoriano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

long    get_time_ms()
{
    struct timeval  tv;
    
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv. tv_usec / 1000);
}
