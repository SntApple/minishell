/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:13:51 by flurk             #+#    #+#             */
/*   Updated: 2020/11/22 15:08:59 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		i;
	char	*p;

	p = (char*)s;
	i = 0;
	while (*p && *p == c)
		p++;
	while (*p)
	{
		if (*p == c)
		{
			i++;
			while (*p && *p == c)
			{
				p++;
				if (*p == '\0')
					i--;
			}
		}
		else
			p++;
	}
	return (i + 1);
}

static char	*new_str(const char *s, char c)
{
	size_t	i;
	char	*dest;
	char	*p;
	char	*d;

	d = (char*)s;
	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	dest = (char*)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	p = dest;
	while (*d && *d != c)
		*p++ = *d++;
	*p = '\0';
	return (dest);
}

static char	**mem_free(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	split = 0;
	return (split);
}

char		**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;

	if (!s)
		return (0);
	arr = (char**)ft_calloc(count_words(s, c) + 1, sizeof(char*));
	if (!arr)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			arr[i] = new_str(s, c);
			if (!arr[i++])
				return (mem_free(arr));
		}
		while (*s && *s != c)
			s++;
	}
	return (arr);
}
