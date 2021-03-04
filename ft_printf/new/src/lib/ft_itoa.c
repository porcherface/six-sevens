/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 13:21:14 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:21:19 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*digits_to_ascii(int *dig, size_t size, int sign)
{
	char	*out;

	if (sign)
		size++;
	if (size > 0)
		out = (char *)ft_calloc(size + 1, sizeof(*out));
	else
		return (0x0);
	if (!out)
		return (out);
	if (sign)
		out[0] = '-';
	while (size > (size_t)sign)
	{
		out[size - 1] = '0' + (char)*dig;
		dig++;
		size--;
	}
	return (out);
}

char				*ft_itoa(int nb)
{
	int		dig[64];
	size_t	it;
	char	*out;
	int		sign;

	sign = 0;
	if (nb < 0)
		sign = 1;
	if (nb == 0)
	{
		dig[0] = 0;
		it = 1;
	}
	else
		it = 0;
	while (nb != 0)
	{
		dig[it] = nb % 10;
		nb = (nb - dig[it]) / 10;
		dig[it] = dig[it] * (dig[it] < 0) * -1 + dig[it] * (dig[it] >= 0);
		it++;
	}
	out = digits_to_ascii(dig, it, sign);
	return (out);
}
