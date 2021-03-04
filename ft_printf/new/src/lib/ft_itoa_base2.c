/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 13:21:14 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:21:19 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*set_base(int nb, int uppercase)
{
	char	*out;
	size_t	count;

	if (nb < 2)
		return (0x0);
	out = (char *)ft_calloc(nb + 1, sizeof(char));
	if (!out)
		return (out);
	count = 0;
	while(count < (size_t)nb)
	{
		out[count] = '0' + count;
		if (count > 9 && uppercase)
			out[count] = 'A' + (count - 10);
		if (count > 9 && !uppercase)
			out[count] = 'a' + (count - 10);
		count++;
	}
	out[count] = 0;
	return (out);
}

static char *digits_to_base(int *dig, size_t size, int sign, char *base)
{
	char	*out;

	out = 0x0;
	if (sign)
		size++;
	if (size > 0)
		out = (char *)ft_calloc(size + 1, sizeof(*out));
	if (!out)
		return (out);
	if (sign)
		out[0] = '-';
	while (size > (size_t)sign)
	{
		out[size - 1] = base[*dig];
		dig++;
		size--;
	}
	return (out);
}	

char		*ft_itoa_base2(int nb, int base_num, int uppercase)
{
	int		dig[64];
	char	*base;
	int		it;
	char 	*out;
	int		sign;

	sign = (nb < 0);
	base = set_base(base_num, uppercase);
	if (!base)
		return (0x0);
	it = 0;
	if (nb == 0)
	{
		it = 1;
		dig[0] = 0;
	}
	while (nb != 0)
	{
		dig[it] = nb % base_num;
		nb = (nb - dig[it]) / base_num;
		dig[it] = dig[it] * (dig[it] < 0) * -1 + dig[it] * (dig[it] >= 0);
		it++;
	}
	out = digits_to_base(dig, it, sign, base);
	return (out);
}
