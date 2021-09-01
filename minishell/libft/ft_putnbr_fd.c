/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 11:25:16 by flurk             #+#    #+#             */
/*   Updated: 2020/11/11 11:48:29 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int c)
{
	if (c < 0)
		c *= -1;
	return (c);
}

void		ft_putnbr_fd(int n, int fd)
{
	char	str[13];
	int		i;

	ft_bzero(str, 13);
	i = 0;
	if (n == 0)
		write(fd, "0", 1);
	else
	{
		if (n < 0)
			write(fd, "-", 1);
		while (n)
		{
			str[i++] = ft_abs(n % 10) + '0';
			n /= 10;
		}
		i--;
		while (i >= 0)
			write(fd, &str[i--], 1);
	}
}
