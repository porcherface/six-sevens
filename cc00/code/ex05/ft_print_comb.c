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
#include <unistd.h>

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