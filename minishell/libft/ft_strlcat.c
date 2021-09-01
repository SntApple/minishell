/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:10:04 by flurk             #+#    #+#             */
/*   Updated: 2020/11/20 11:17:47 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*d;
	char	*s;
	size_t	ans;
	int		i;
	int		size;

	d = dst;
	i = 0;
	s = (char*)src;
	ans = ft_strlen(dst);
	if (ans > dstsize)
		return (ft_strlen(src) + dstsize);
	while (*d)
		d++;
	size = dstsize - ans - 1;
	while ((i++ < size) && *s)
		*d++ = *s++;
	*d = '\0';
	ans += ft_strlen(src);
	return (ans);
}
