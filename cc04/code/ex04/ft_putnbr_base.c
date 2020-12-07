/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_putnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:21:13 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/03 17:21:16 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		count_base(char *b)
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

void	print_it_base(int d[], int s, char *base)
{
	char	c;

	s -= 1;
	while (s >= 0)
	{
		c = base[d[s] * (d[s] < 0) * -1 + d[s] * (d[s] >= 0)];
		write(1, &c, 1);
		s--;
	}
}

void	ft_putnbr_base(int nb, char *base)
{
	int	digits[64];
	int	base_num;
	int	it;

	base_num = count_base(base);
	if (base_num < 2)
		return ;
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	write(1, "-", 1 * (nb < 0));
	it = 0;
	while (nb != 0)
	{
		digits[it] = nb % base_num;
		nb = (nb - digits[it]) / base_num;
		it++;
	}
	print_it_base(digits, it, base);
}
