/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 08:54:25 by flurk             #+#    #+#             */
/*   Updated: 2020/11/18 13:41:48 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dest == 0 && src == 0)
		return (dest);
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	while (n--)
		*d++ = *s++;
	return (dest);
}
