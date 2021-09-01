/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:45:38 by flurk             #+#    #+#             */
/*   Updated: 2020/11/24 15:27:38 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	unsigned char	ch;

	if (c > 255 || c < 0)
		return (0);
	ch = (unsigned char)c;
	if (ft_isalpha(ch) || ft_isdigit(ch))
		return (1);
	else
		return (0);
}
