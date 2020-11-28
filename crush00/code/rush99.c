/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush99.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 01:43:33 by amazzei           #+#    #+#             */
/*   Updated: 2020/11/28 01:44:27 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void ft_putstring(int row, int key, int x, int level)
{
	char c;

	c = 'k' + key;
	ft_putchar(c);
	if (level < x - 1)
	{
		ft_putstring(row, key, x, level + 1);	
	}
	if (!level)
	{
		ft_putchar('\n');
	}
	return ;
}	


void rush99(int x, int y)
{
	int row;
	int key;

	key = 0;
	row = 0;
	while(row < y)
	{
		ft_putstring(row, key, x, 0);
		row++;	
	}
	return ;
}
