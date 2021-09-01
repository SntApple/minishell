/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:07:44 by flurk             #+#    #+#             */
/*   Updated: 2020/11/18 14:29:17 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*d;
	char	*s;
	size_t	i;

	s = (char*)src;
	d = dst;
	if (!src)
		return (0);
	if (dstsize)
	{
		i = 0;
		while (i++ < dstsize - 1 && *s)
			*d++ = *s++;
		*d = '\0';
	}
	return (ft_strlen(src));
}
