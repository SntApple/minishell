/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:27:05 by flurk             #+#    #+#             */
/*   Updated: 2020/11/20 10:50:53 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_ans(const char *s, int *ans)
{
	int bul;

	bul = 0;
	while (*s)
	{
		if (*s == '-' || *s == '+' || (ft_isdigit(*s)))
		{
			if (*s == '-')
				bul = 1;
			else if (ft_isdigit(*s))
			{
				*ans *= 10;
				if (bul)
					*ans -= *s - '0';
				else
					*ans += *s - '0';
			}
			s++;
			if (!ft_isdigit(*s))
				break ;
		}
		else
			break ;
	}
}

int			ft_atoi(const char *str)
{
	char	*s;
	int		ans;

	ans = 0;
	s = (char*)str;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	get_ans(s, &ans);
	return (ans);
}
