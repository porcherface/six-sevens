/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:58:14 by amazzei           #+#    #+#             */
/*   Updated: 2020/11/26 15:58:16 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_print_comb2(void)
{
	int cnt;
	int cnt2;
	char first_digit_d; 

	cnt = 0;
	while (cnt < 98)
	{
		cnt2 = cnt++ + 1;
		while (cnt2 < 100)
		{
			first_digit_d = (cnt - 1 - ( ( cnt - 1 ) % 10 + '0' ) + '0') / 10  + '0';
			write(1, &first_digit_d, 1);
			first_digit_d = ( (cnt - 1) % 10 + '0' );
			write(1, &first_digit_d, 1);
			write(1, " ", 1);
 			first_digit_d = (cnt2 - ( cnt2 % 10 + '0' ) + '0') / 10  + '0';
			write(1, &first_digit_d, 1);
			first_digit_d = ( cnt2 % 10 + '0' );
			write(1, &first_digit_d, 1);
			write(1, ", ", 2);
			cnt2++;
		}
	}
	write(1, "98 99", 5);
	return;
} 