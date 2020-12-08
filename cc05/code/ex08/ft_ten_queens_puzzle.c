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

void	print_them(int *arr)
{
	int it;
	char c;

	it = 0;
	while (it++ < 10)
	{
		c = arr[it - 1] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

int		is_valid_placement(int *pos, int size)
{
	int	it;
	int	jt;

	it = 0;
	while (it < size + 1)
	{	
		jt = it + 1;
		while (jt < size + 1)
		{
			if ((pos[it] - jt + it) == pos[jt])
				return (0);
			if ((pos[it] + jt - it) == pos[jt])
				return (0);
			jt++;
		}
		it++;
	}
	print_them(pos);
	return (1);
}

void	wash_dirt(int *arr,int i,int j, int flag)
{
	int tmp;

	if (flag)
	{
		tmp = arr[j];
		while (j > i)
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = tmp;
	}
	else
	{
		tmp = arr[i];
		while (i < j)
		{
			arr[i] = arr[i + 1];
			i++;
		}
		arr[i] = tmp;
	}
}

void	ok_moulinette_solve_thanks(int *arr, int start, int n, int *total)
{
	int jt;

	if (start == n)
		(*total) += is_valid_placement(arr, n);
	else
	{
		jt=start;
		while (jt < n)
		{
			wash_dirt(arr, start, jt, 1);
			ok_moulinette_solve_thanks(arr, start+1, n, total);
			wash_dirt(arr, start, jt, 0);
			jt++;
		}
	}
}	

int		ft_ten_queens_puzzle(void)
{
	int cookies[10];
	int sols;

	sols = 0;
	while (sols++ < 10)
		cookies[sols - 1] = sols - 1;
	sols = 0;
	ok_moulinette_solve_thanks(cookies, 0, 10, &sols);
	return (sols);
}
