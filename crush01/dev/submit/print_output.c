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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		print_output(int token, int board[], int size)
{
	int cont;

	cont = 0;
	if (token == 0)
	{
		while (cont != size * size)
		{
			ft_putchar(48 + board[cont]);
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
