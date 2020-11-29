/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 01:43:33 by amazzei           #+#    #+#             */
/*   Updated: 2020/11/28 01:44:27 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void rush(int x, int y);

int main(void)
{
	int iterator;
        write(1,"$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n",30);
        write(1,"$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n",30);
        write(1,"$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n",30);
        write(1,"$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n",30);
        write(1,"$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n",30);
        write(1,"$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n",30);
	iterator = 0;
	write(1,"    print rect 6 3...\n",23);
	rush(6,3);
	write(1,"    print lines 1to5...\n",24);
	while (iterator < 5)
	{
		rush(iterator,1);
		rush(1,iterator);
		iterator++;
		write(1,"$$$$$$$$$$\n",12);
	}
	write(1,"    print doubles...\n",22);
	iterator = 1;
	while (iterator++ < 5)
	{
		rush(iterator,2);
		rush(2,iterator);
		write(1,"$$$$$$$$$$:\n",12);
	}	
	write(1,"    print nothing...\n",21);
	while (iterator--)
	{
		rush(iterator,0);
		rush(0,iterator);
		rush(-iterator,42);
		rush(42,-iterator);
		rush(-42,-42);
	}
	return (0);
}
