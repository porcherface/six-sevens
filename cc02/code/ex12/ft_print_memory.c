/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:47:53 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/01 16:47:54 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex(char *digits, int print_zeros, int size)
{
	int		it;
	char	c;

	it = 0;
	while (it < size)
	{
		if (digits[it] != 'z')
		{
			if (digits[it] < '9' + 1)
				write(1, &digits[it], 1);
			else
			{
				c = digits[it] - '9' + 'a';
				write(1, &c, 1);
			}
		}
		else if (print_zeros)
			write(1, "0", 1);
		it++;
	}
}

void	print_addr(void *addr)
{
	unsigned long int	addrint;
	char				digits[16];
	int					it;

	addrint = (unsigned long int)addr;
	it = 0;
	while (it < 16)
		digits[it++] = 'z';
	it = 15;
	while (addrint > 0)
	{
		digits[it--] = (addrint % 16) + '0';
		addrint /= 16;
	}
	print_hex(digits, 1, 16);
	write(1, " ", 1);
}

void	print_content(void *addr)
{
	int		it;
	char	digits[2];
	int		num;

	it = 0;
	while (it < 16)
	{
		num = (*(unsigned long int *)(addr + it));
		digits[0] = ((num / 16) % 16) + '0';
		digits[1] = (num % 16) + '0';
		print_hex(digits, 0, 2);
		if (it % 2 == 1)
			write(1, " ", 1);
		it++;
	}
	it = 0;
	while (it < 16)
	{
		digits[0] = *(unsigned char*)(addr + it);
		if (digits[0] >= 0x20 && digits[0] < 0x7f)
			write(1, digits, 1);
		else
			write(1, ".", 1);
		it++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int it;

	it = 0;
	while (it < size * 16)
	{
		print_addr(addr + it);
		print_content(addr + it);
		it += 16;
		write(1, "\n", 1);
	}
	return (addr);
}
