/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:32:48 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/01 16:32:51 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check_print11(char c)
{
	if (c >= 0x20 && c <= 0x7f)
		return 1;
	return 0;
}

int go_nonprint11(char c)
{
	return (int)c;
}

void ft_putstr_non_printable(char *str)
{
	int it;
	int it2;
	int nonprinto;


	it = 0;
	while (str[it] != '\0')
	{
		if(!check_print11(str[it]))
		{
			str[it] = '\\';
			nonprinto = go_nonprint11(str[it]);
			/* nonprinto e'un int a due digits (from 0x00 to 0x19) */ 
			/* putto nonprinto in str it+1 e (se necessario) str it+2 */
			
		}
		it++;
	}
	it2 = 0;
	while (it2 < it)
	{
		write(1,&str[it2],1);
		it2++;
	}
}
