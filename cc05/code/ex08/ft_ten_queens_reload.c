/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:59:38 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/07 16:59:39 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int is_valid_placement(int *pos)
{
	int it;
	int girl;

	it = 0;
	girl = 0;
	while(girl < 10)
	{	
		while(it < 10)
		{
			if (((pos[it] - it + girl) == pos[girl]) && (it != girl))
				return (0);
			if (((pos[it] + it - girl) == pos[girl]) && (it != girl))
				return (0);
			it++;
		}
		it = 0;
		girl++;
	}
	return (1);
}
 
void print_them(int *a)
{
	int it;
	char c;
	
	it = 0;
	while(it < 10)
	{
		c = a[it] + '0';
		write(1, &c, 1);
		it++;
	}
	write(1, "\n", 1);
	
}

int permute(int *a, int l, int r, int *total) 
{
	int tmp;
	int it;

	if((*total) == 724)
		return (0);

	if (l == r)
	{	
		if (is_valid_placement(a)) 
		{
			print_them(a);
			(*total)++;
		}
	}
	else
	{ 	
		it = l;
 		while (it <= r) 
		{ 
			tmp = a[r];
			a[r] = a[it];
			a[it] = tmp; 
			permute(a, l, r - 1, total); 
			tmp = a[r];
			a[r] = a[it];
			a[it] = tmp;
			it++;             
		}
	}
	return (0);
}

int ft_ten_queens_puzzle(void)
{
	int moulinette_needs_crunchies[10];
	int sols;

	sols = 0;
	moulinette_needs_crunchies[0] = 0;
	moulinette_needs_crunchies[1] = 1;
	moulinette_needs_crunchies[2] = 2;
	moulinette_needs_crunchies[3] = 3;
	moulinette_needs_crunchies[4] = 4;
	moulinette_needs_crunchies[5] = 5;
	moulinette_needs_crunchies[6] = 6;
	moulinette_needs_crunchies[7] = 7;
	moulinette_needs_crunchies[8] = 8;
	moulinette_needs_crunchies[9] = 9;
	permute(moulinette_needs_crunchies, 0, 9, &sols); 


	return (1);
}
