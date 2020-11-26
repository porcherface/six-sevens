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

void ft_putchar(char c);
void ft_print_alphabet(void);
void ft_print_reverse_alphabet(void);
void ft_print_numbers(void);
void ft_is_negative(int n);
void ft_print_comb(void);
void ft_print_comb2(void);
void ft_putnbr(int nb);
void ft_print_combn(int n);

int main(void)
{ 
	//ft_putchar('c');
	//ft_print_alphabet( );
	//ft_print_reverse_alphabet( );
	//ft_print_numbers( );
	//ft_is_negative(0);
	//ft_is_negative(65535);
	//ft_is_negative(-1);
	//ft_print_comb( );
	//ft_print_comb2( );
    //ft_putnbr( 0 );
	//ft_putnbr( 65535 );
	//ft_putnbr( 1 );
	//ft_putnbr( 2 );
	//ft_putnbr( -1 );
	//ft_putnbr( 42 );
	//ft_putnbr( 0 );
	//ft_putnbr( -65535 / 2 );
	ft_print_combn(3);

	return 0;
}

void ft_putchar(char c)
{
	write(1, &c, 1);
	return;
}

/* a superuber pedantic implementation */
void ft_print_alphabet(void)
{
	int counter;
	char c;

	counter = 26;
	while ( counter )
	{
		c = 'z' - counter + 1;
		write(1, &c, 1);	
		counter--;
	}
	return;	
}

void ft_print_reverse_alphabet(void)
{
	int counter;
	char c;

	counter = 26;
	while ( counter )
	{
		c = 'a' + counter - 1;
		write(1, &c, 1);	
		counter--;
	}
	return;	
}

void ft_print_numbers(void)
{
	char c;

	c = '0';
	while ( c <= '9')
	{
		write(1, &c, 1);
		c++;	
	}
	return;
}

void ft_is_negative(int n)
{
	char c;

	if (n < 0)
	{
		c = 'N';
	}
	else
	{
		c = 'P';		
	}
	write(1, &c, 1);
	return;
}

void ft_print_comb(void)
{
	char first;
	char second;
	char third;
	
	first = '0';
	second = '1';
	third = '2';
	while (first < '7')
	{
		second = first + 1;
		while (second < '9')
		{
			third = second + 1;
			while (third < '9' + 1)
			{
				write(1, &first, 1);
				write(1, &second, 1);
				write(1, &third, 1);
				write(1, ", ", 2);
				third++;
			}
			second++;
		}
		first++;
	}
	write(1, ", 789", 5);
	return;
}

void ft_putnbr(int nb)
{
	char digits[5];
	int iterator;

	iterator = 0;
	write(1, "-", 1 * (nb < 0));
	nb = nb * (nb < 0) * -1 + nb * (nb >= 0);
	while ( nb * nb > 0 || iterator == 0)
	{
		digits[iterator++] = nb % 10 + '0';
 		nb = ( ( nb - ( nb % 10 ) ) / 10 ) * (nb > 0) + 0;
	}
	if ( !nb )
	{
		iterator--;
	}	
	while ( iterator + 1)
	{
		if( digits[iterator] || iterator == 0)
		{
			write(1, &digits[iterator], 1);
		}
		iterator--;
	}
	return;
}

void ft_print_combn(int n)
{
	int digits[10];
	int iterator = 0;

	write(1, digits, n);
}









