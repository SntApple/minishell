/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 06:01:48 by flurk             #+#    #+#             */
/*   Updated: 2020/11/18 08:43:07 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *p;

	if (lst)
	{
		while (*lst)
		{
			p = *lst;
			*lst = (*lst)->next;
			(*del)(p->content);
			free(p);
		}
	}
	lst = 0;
}
