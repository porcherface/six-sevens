/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_anybase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 13:21:14 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:21:19 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_base(char *b)
{
	int	it;
	int	jt;

	jt = 0;
	it = 0;
	while (b[it] != '\0')
	{
		if (b[it] == '+' || b[it] == '-')
			return (0);
		if (b[it] >= 0x7f || b[it] < 0x20)
			return (0);
		jt = it + 1;
		while (b[jt] != '\0')
		{
			if (b[it] == b[jt])
				return (0);
			jt++;
		}
		it++;
	}
	return (it * (it > 1));
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

char		*ft_itoa_anybase(int nb, char *base)
{
	int		dig[64];
	int		base_num;
	int		it;
	char	*out;
	int		sign;

	out = 0x0;
	sign = (nb < 0);
	base_num = count_base(base);
	if (base_num < 2)
		return 0x0;
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
