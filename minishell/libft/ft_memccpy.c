/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 08:55:45 by flurk             #+#    #+#             */
/*   Updated: 2020/11/18 13:58:18 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		ch;

	d = (unsigned char*)dst;
	s = (const unsigned char*)src;
	ch = (unsigned char)c;
	while (n)
	{
		*d++ = *s;
		if (*s++ == ch)
			break ;
		n--;
	}
	if (!n)
		return (0);
	return (d);
}
