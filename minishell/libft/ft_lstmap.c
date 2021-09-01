/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 10:32:05 by flurk             #+#    #+#             */
/*   Updated: 2020/11/18 10:39:58 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*iter;

	begin = 0;
	while (lst)
	{
		iter = ft_lstnew((*f)(lst->content));
		if (!iter)
		{
			while (begin)
			{
				iter = begin->next;
				(*del)(begin->content);
				free(begin);
				begin = iter;
			}
			begin = 0;
			return (0);
		}
		ft_lstadd_back(&begin, iter);
		lst = lst->next;
	}
	return (begin);
}
