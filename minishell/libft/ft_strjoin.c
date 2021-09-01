/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:03:05 by flurk             #+#    #+#             */
/*   Updated: 2020/11/18 14:43:21 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*p;
	char	*d;
	char	*str;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1);
	size += ft_strlen(s2);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	p = (char*)s1;
	d = (char*)str;
	while (*p)
		*d++ = *p++;
	p = (char*)s2;
	while (*p)
		*d++ = *p++;
	*d = '\0';
	return (str);
}
