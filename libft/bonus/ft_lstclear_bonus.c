/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:58:06 by jrubio-m          #+#    #+#             */
/*   Updated: 2025/05/28 15:29:09 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lsttmp;

	if (del || lst || (*lst))
	{
		while (lst && *lst)
		{
			lsttmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = lsttmp;
		}
	}
}
