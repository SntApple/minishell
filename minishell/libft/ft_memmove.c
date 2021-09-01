/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 08:58:38 by flurk             #+#    #+#             */
/*   Updated: 2020/11/18 14:48:00 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	char		*dd;
	const char	*ss;

	if (!dst && !src)
		return (0);
	d = dst;
	s = src;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		ss = s + (len - 1);
		dd = d + (len - 1);
		while (len--)
			*dd-- = *ss--;
	}
	return (dst);
}
