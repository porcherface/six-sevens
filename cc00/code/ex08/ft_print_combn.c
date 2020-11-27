/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:58:14 by amazzei           #+#    #+#             */
/*   Updated: 2020/11/26 15:58:16 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	init_array(int *arr, int n)
{
	int iterator;

	iterator = 0;
	while (iterator < n)
	{
		arr[iterator] = iterator;
		iterator++;
	}	
	return ;
}

void	update_array(int *arr, int n)
{
	
	if (arr[n - 1] != 10 - n) 
	{
		arr[n - 1]++;
	} 
	else
	{
		if (n -1 > 0)
		{		
			arr[n - 1] = arr[n - 2]+1;
			update_array(arr, n-1);
		}
		else
		{
			arr[n - 1] = 0;
		}	
	}
	return ;
}

int	terminate(int arr[10], int n)
{
	int iterator;
	int terminate;
	int counter;

	terminate = 1;
	iterator = n-1;
	counter = 0;
	while (iterator >= 0)
	{
		if (arr[iterator] != 9 - counter)
		{	
			terminate = 0;
		}
		iterator--;
		counter++;
	}
	return (terminate);
}

void	write_ctoa(int arr[10], int n)
{
	int iterator;
	char c;

	iterator = 0;
	while (iterator<n)
	{
		c = arr[iterator] + '0';
		write(1, &c, 1);
		iterator++;
	}

}

void	ft_print_combn(int n)
{
	int arr[10];
	int *arrp;

	arrp = arr;
	if (n <= 10 && n >= 1)
	{
		init_array(arrp, n);
		while (!terminate(arr, n))
		{
			write_ctoa(arr, n);
			write(1, ", ", 2);
			update_array(arrp,n);

		}
		write(1, arrp, n);
	}
	return ;
}

