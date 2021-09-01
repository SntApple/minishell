/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:16:18 by flurk             #+#    #+#             */
/*   Updated: 2020/11/24 15:32:42 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	if (c < -128 || c > 127)
		return (0);
	p = (char*)s;
	while (*p)
		p++;
	if (c == '\0')
		return (p);
	while (p != s)
	{
		if (*p == (char)c)
			return (p);
		p--;
	}
	if (*p == c)
		return (p);
	return (0);
}
