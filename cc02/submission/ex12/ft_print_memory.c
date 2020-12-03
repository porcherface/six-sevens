/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:47:53 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/02 18:01:37 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	print_hex(unsigned char *digits, int print_zeros, int size)
{
	int		it;
	unsigned char	c;

	if (size == 0)
	{
		return (1);
	}
	it = 0;
	while (it < size)
	{
		if (digits[it] != 'z')
		{
			if (digits[it] < '9' + 1)
				write(1, &digits[it], 1);
			else
			{
				c = digits[it] - '9' + 'a' - 1;
				write(1, &c, 1);
			}
		}
		else if (print_zeros)
			write(1, "0", 1);
		it++;
	}
	return (0);
}

void	print_addr(void *addr)
{
	unsigned long int	addrint;
	unsigned char		digits[16];
	unsigned int		it;

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
}

void	print_content(void *addr)
{
	int		it[2];
	unsigned char	digits[2];
	unsigned int	num;

	it[0] = 0;
	it[1] = 0;
	while (it[0] < 16)
	{
		num = (*(unsigned long int *)(addr + it[0]));
		digits[0] = ((num / 16) % 16) + '0';
		digits[1] = (num % 16) + '0';
		it[1] += print_hex(digits, 1, 2*((digits[0] != '0') || (digits[1] != '0')));
		if (it[1] % 2 == 1)
			write(1, " ", 1);
		it[0]++;
	}
	write(1, "                ", 2 * it[1]);
	it[0] = 0;
	while (it[0] < 16)
	{
		digits[0] = *(unsigned char*)(addr + it[0]);
		if (digits[0] >= 0x20 && digits[0] < 0x7f)
			write(1, digits, 1);
		else
			write(1, ".", 1*(digits[0]) != 0);
		it[0]++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int it;

	it = 0;
	while (it < size * 16)
	{
		print_addr(addr + it);
		write(1, ": ", 2);
		print_content(addr + it);
		it += 16;
		write(1, "\n", 1);
	}
	return (addr);
}
