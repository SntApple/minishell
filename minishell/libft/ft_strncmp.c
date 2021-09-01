/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:20:24 by flurk             #+#    #+#             */
/*   Updated: 2020/11/18 14:01:32 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*p;
	unsigned char	*d;

	p = (unsigned char*)s1;
	d = (unsigned char*)s2;
	while (n--)
	{
		if (*p != *d)
			return ((int)*p - (int)*d);
		else if (!*p)
			return (0);
		p++;
		d++;
	}
	return (0);
}
