/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:52:04 by flurk             #+#    #+#             */
/*   Updated: 2020/11/18 11:10:38 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;
	char	*p;
	char	*d;

	i = ft_strlen(s1);
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	p = (char*)s1;
	d = str;
	while (*p)
		*d++ = *p++;
	*d = '\0';
	return (str);
}
