/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:03:56 by flurk             #+#    #+#             */
/*   Updated: 2020/11/16 13:02:49 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*d;

	p = (unsigned char*)s1;
	d = (unsigned char*)s2;
	while (n--)
	{
		if (*p != *d)
			return ((int)*p - (int)*d);
		p++;
		d++;
	}
	return (0);
}
