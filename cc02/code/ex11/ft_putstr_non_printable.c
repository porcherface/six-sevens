/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:32:48 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/02 17:58:34 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_print11(char c)
{
	if (c >= 0x20 && c <= 0x7f)
		return (1);
	return (0);
}

int		go_nonprint11(char c)
{
	return (int)c;
}

void	put_specials(int nonprinto)
{
	char c;
	char d;

	if (nonprinto > 16)
	{
		d = nonprinto / 16;
		if (d < 10)
			c = d + '0';
		else
			c = d - 10 + 'a';
		write(1, &c, 1);
	}
	nonprinto = nonprinto % 16;
	if (nonprinto < 10)
		c = nonprinto + '0';
	else
		c = nonprinto - 10 + 'a';
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		it;
	int		nonprinto;

	it = 0;
	while (str[it] != '\0')
	{
		if (!check_print11(str[it]))
		{
			nonprinto = go_nonprint11(str[it]);
			str[it] = '\\';
			write(1, &str[it], 1);
			put_specials(nonprinto);
		}
		else
		{
			write(1, &str[it], 1);
		}
		it++;
	}
}
