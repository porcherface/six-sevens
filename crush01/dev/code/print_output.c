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

void 	ft_putchar(char c)
{
	write (1, &c, 1);
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
			write (1, " ", 1);
			cont++;
			if (cont == size || cont % size == 0)
				write (1, "\n", 1);
		}
	}

	if (token < 0)
		write (1, "Error\n", 6);
	if (token > 0)
		write (1, "Error\n", 6);

/*   else if (token == 1)
		write (1, "Problem is well posed but alghoritm failed/no solution.", 55);
	else if (token == -1)
		write (1, "Parse error, wrong argument number.", 35);
	else if (token == -2)
		write (1, "1 or more arguments are NaN.", 28);
	else if (token == -3)
		write (1, "Parse error, wrong constraints.", 31);
	else if (token == -4)
		write (1, "Memory allocation error.", 24); */ 

	return (token);
}
