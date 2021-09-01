/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:54:25 by flurk             #+#    #+#             */
/*   Updated: 2020/11/18 14:50:29 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	i;
	size_t	size;

	if (!s)
		return (0);
	i = 0;
	if (start >= ft_strlen(s))
	{
		ans = (char*)malloc(sizeof(char) * 1);
		if (!ans)
			return (0);
	}
	else
	{
		size = ft_strlen(s) + start;
		len = size < len ? size : len;
		ans = (char*)malloc(sizeof(char) * (len + 1));
		if (!ans)
			return (0);
		while (i < len)
			ans[i++] = s[start++];
	}
	ans[i] = '\0';
	return (ans);
}
