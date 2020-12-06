/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbiris <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 19:00:07 by sbiris            #+#    #+#             */
/*   Updated: 2020/12/05 20:03:29 by sbiris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putnbr(int nb)
{
	char		digit[5];
	int			iterator;

	iterator = 0;
	write(1, "-", 1 * (nb < 0));
	nb = nb * (nb < 0) * -1 + nb * (nb >= 0);
	while (nb * nb > 0 || iterator == 0)
	{
		digit[iterator++] = nb % 10 + '0';
		nb = ((nb - (nb % 10)) / 10) * (nb > 0) + 0;
	}
	if (!nb)
	{
		iterator--;
	}
	while (iterator + 1)
	{
		if (digit[iterator] || iterator == 0)
		{
			write(1, &digit[iterator], 1);
		}
		iterator--;
	}
	return (0);
}

int		print_output(int token, int board[], int size)
{
	int cont;

	cont = 0;
	if (token == 0)
	{
		while (cont != size * size)
		{
			ft_putnbr(board[cont]);
			write(1, " ", 1);
			cont++;
			if (cont == size || cont % size == 0)
				write(1, "\n", 1);
		}
	}
	if (token < 0)
		write(1, "Error\n", 6);
	if (token > 0)
		write(1, "Error\n", 6);
	return (token);
}
