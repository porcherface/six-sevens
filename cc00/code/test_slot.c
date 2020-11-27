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
#include	<unistd.h>
#define HARD	0

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
	ft_putchar('c');
	ft_putchar('^');
	ft_print_alphabet( );
	ft_print_reverse_alphabet( );
	ft_print_numbers( );
	ft_is_negative(42);
	ft_is_negative(0);
	ft_is_negative(-1);
	ft_print_comb( );
	ft_print_comb2( );
	ft_putnbr( 0 );
	ft_putnbr( -1 );
	ft_putnbr( 42 );
	ft_print_combn(1);
	ft_print_combn(10);
	ft_print_combn(2);
	ft_print_combn(3);
	ft_print_combn(9);

	if (HARD)
	{
		ft_is_negative(65535);
		ft_putnbr( 65535 );
		ft_putnbr( -65535 / 2 );
	}
	return 0;
}
