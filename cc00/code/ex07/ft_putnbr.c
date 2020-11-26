/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:58:14 by amazzei           #+#    #+#             */
/*   Updated: 2020/11/26 15:58:16 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

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