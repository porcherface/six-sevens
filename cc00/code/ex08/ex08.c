/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:58:14 by amazzei           #+#    #+#             */
/*   Updated: 2020/11/26 15:58:16 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_number_to_digits(long n, int digits[])
{
	digits[0] = n / 1 % 10;
	digits[1] = n / 10 % 10;
	digits[2] = n / 100 % 10;
	digits[3] = n / 1000 % 10;
	digits[4] = n / 10000 % 10;
	digits[5] = n / 100000 % 10;
	digits[6] = n / 1000000 % 10;
	digits[7] = n / 10000000 % 10;
	digits[8] = n / 100000000 % 10;
	digits[9] = n / 1000000000 % 10; 
}

int ft_go_next( int digits[10], int n)
{
	int iterator = 1;
	int go;

	go = 1;
	while ( iterator < n )
	{
		if( digits[iterator] <= digits[iterator - 1] )
		{
			go = 0;
		}
		iterator++;
	}
}

long ft_pow(int base, int exponent)
{
	int iterator;
	int out;

	iterator = 0;
	out = 1;
	while ( iterator < exponent )
	{
		out *= base;
	}
	return out;
}

void ft_print_combn(int n)
{
	int digits[10];
	int token;
	long number;

	number = 0;
	while (number < ft_pow(10, n) )
	{	
		ft_number_to_digits(number, digits);
		token = ft_go_next(digits, n);
		if (token)
		{
			write(1, digits, n);
		}

	}
	write(1, digits, n);
}