/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:22:20 by flurk             #+#    #+#             */
/*   Updated: 2020/11/18 14:02:41 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	size_t	l;

	h = (char*)haystack;
	n = (char*)needle;
	l = len;
	if (!ft_strlen(needle))
		return (h);
	while (*h && len--)
	{
		if (*h == *n)
			if (!ft_strncmp(h, n, ft_strlen(needle)))
			{
				if (l - (h - haystack) + 1 < ft_strlen(needle))
					return (0);
				else
					return (h);
			}
		h++;
	}
	return (0);
}
