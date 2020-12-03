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

void	init_digits(char *digits)
{
	int it;

	it = 0;
	while (it < 20)
	{
		digits[it] = 'z';
		it++;
	}
}

void	print_it(char *digits)
{
	int it;

	it = 0;
	while (it < 20)
	{
		if (digits[it] != 'z')
		{
			write(1, &digits[it], 1);
		}
		it++;
	}
}

void	ft_putnbr(int nb)
{
	char	digits[20];
	int		it;

	init_digits(digits);
	write(1, "-", 1 * (nb < 0));
	nb = nb * (nb < 0) * -1 + nb * (nb >= 0);
	it = 19;
	if (nb == 0)
	{
		write(1, "0", 1);
	}
	while (nb > 0)
	{
		digits[it] = (nb % 10) + '0';
		nb /= 10;
		it--;
	}
	print_it(digits);
	return ;
}

