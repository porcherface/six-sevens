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

void	print_them(int *a)
{
	int it;
	char c;
	
	it = 0;
	while (it < 10)
	{
		c = a[it] + '0';
		write(1, &c, 1);
		it++;
	}
	write(1, "\n", 1);
}

int		is_valid_placement(int *pos, int size)
{
	int	it;
	int	jt;
	int	distance;


	it = 0;
	jt = 1;
	while (it < size + 1)
	{	
		jt = it + 1;
		while (jt < size + 1)
		{
			distance = jt - it;
			if ((pos[it] - distance) == pos[jt])
				return (0);
			if ((pos[it] + distance) == pos[jt])
				return (0);
			jt++;
		}
		it++;
	}
	print_them(pos);
	return (1);
}


void	change(int *a,int i,int j, int flag)
{
	int tmp;

	if (flag)
	{
		tmp = a[j];
		while(j > i)
		{
			a[j] = a[j - 1];
			j--;
		}
		a[j] = tmp;
	}
	else
	{
		tmp = a[i];
		while (i < j)
		{
			a[i] = a[i + 1];
			i++;
		}
		a[i] = tmp;
	}
}

void swap(int *arr, int i, int j)
{
	int tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp; 
}

void	ok_moulinette_solve_thanks(int *arr, int start, int n, int *total)
{
	int jt;

	if (start - 1 == n)
	{
		(*total) += is_valid_placement(arr, n);
	}
	else
	{
		jt=start;
		while (jt <= n)
		{
			change(arr, start, jt, 1);
			
			//swap(arr, jt, n);
			ok_moulinette_solve_thanks(arr, start+1, n, total);
			//swap(arr, start, jt);


			change(arr, start, jt, 0);
			jt++;
		}
	}
}	

int		ft_ten_queens_puzzle(void)
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
	ok_moulinette_solve_thanks(moulinette_needs_crunchies, 0, 9, &sols);
	return (sols);
}
