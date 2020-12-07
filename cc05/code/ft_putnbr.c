/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:16:44 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/03 17:16:46 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	set_base_re(char *b)
{
	int 	it;

	it = 0;
	while (it < 10)
	{
		b[it] = '0' + it;
		it++;
	}
	return (10);
}

void	print_it_base_re(int d[], int s, char *base)
{
	char c;

	s -= 1;
	while(s >= 0)
	{	
		c = base[d[s] * (d[s] < 0) * -1 + d[s] * (d[s] >= 0)];
		write(1, &c, 1);
		s--;
	}
}

void	ft_putnbr(int nb)
{
	int	digits[20];
	int	base_num;
	int 	it;
	char	base[11];

	if(nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	base_num = set_base_re(base);
	if(base_num < 2)
	{
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
	print_it_base_re(digits, it, base);
}
