/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:58:14 by amazzei           #+#    #+#             */
/*   Updated: 2020/11/26 15:58:16 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	ft_print_comb(void)
{
	char digits[3];
	
	digits[0] = '0';
	digits[1] = '1';
	digits[2] = '2';
	while (digits[0] < '7')
	{
		digits[1] = digits[0] + 1;
		while (digits[1] < '9')
		{
			digits[2]= digits[1] + 1;
			while (digits[2] < '9' + 1)
			{
				write(1, &digits[0], 1);
				write(1, &digits[1], 1);
				write(1, &digits[2], 1);
				write(1, ", ", 2);
				digits[2]++;
			}
			digits[1]++;
		}
		digits[0]++;
	}
	write(1, "789", 5);
	return ;
}
