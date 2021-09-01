/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:07:18 by flurk             #+#    #+#             */
/*   Updated: 2020/11/20 11:14:18 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check(const char c, const char *set)
{
	char	*s;

	s = (char*)set;
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

static size_t	get_size(char const *s1, char const *set)
{
	size_t	size;
	char	*p;

	p = (char*)s1;
	size = ft_strlen(s1);
	while (check(*p, set) && *p)
	{
		p++;
		size--;
	}
	while (*p)
		p++;
	--p;
	if (size)
	{
		while (check(*p--, set))
		{
			size--;
		}
	}
	return (size);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*ps;
	int		size;
	char	*p;

	if (!s1 || !set)
		return (0);
	size = get_size(s1, set);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	ft_bzero(str, (size + 1));
	p = (char*)s1;
	ps = str;
	while (check(*p, set))
		p++;
	while (size--)
		*ps++ = *p++;
	return (str);
}
