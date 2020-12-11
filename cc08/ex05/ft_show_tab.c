/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:33:26 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 15:33:28 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int it;

	it = 0;
	while (str[it] != '\0')
	{
		write(1, &str[it], 1);
		it++;
	}
}

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

void	ft_show_tab(struct s_stock_str *par)
{
	int size;
	int itsize;

	itsize = 0;
	while (par[itsize].str)
	{
		ft_putstr(par[itsize].str);
		ft_putstr("\n");
		ft_putnbr(par[itsize].size);
		ft_putstr("\n");
		ft_putstr(par[itsize].copy);
		ft_putstr("\n");
		itsize++;
	}
}
