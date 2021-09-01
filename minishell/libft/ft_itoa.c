/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 10:57:30 by flurk             #+#    #+#             */
/*   Updated: 2020/11/22 13:40:56 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int c)
{
	if (c < 0)
		c *= -1;
	return (c);
}

static char	*get_str(char *str, int n, int i)
{
	if (n == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		if (!str)
			return (0);
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		str = (char*)malloc(sizeof(char) * (i + 1));
		if (!str)
			return (0);
	}
	str[i--] = '\0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		str[i--] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	size_t	i;
	int		nn;
	char	*str;

	str = 0;
	i = 0;
	nn = n;
	while (nn)
	{
		i++;
		nn /= 10;
	}
	if (n < 0)
		i++;
	if (n == 0)
		i = 1;
	str = get_str(str, n, i);
	return (str);
}
