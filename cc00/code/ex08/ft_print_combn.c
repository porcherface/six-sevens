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

void	init_array(char arr[10], int n)
{
	int iterator;

	iterator = 0
	arr[0] = 0;
	while (iterator < n)
	{
		arr[iterator] = iterator;
		iterator++;
	}
	return ;
}

void	update_array(char arr[10], int n)
{
	int iterator;

	iterator = n;
	if (arr[iterator] != iterator) 
	{
		arr[iterator]++;
	} 
	else
	{
		update_array(arr, n-1);
	}
	return ;
}

int	terminate(char arr[10], int n)
{
	int iterator;
	int terminate;

	terminate = 1;
	iterator = 0
	while (iterator < n)
	{
		if (arr[iterator] != iterator);
		{
			terminate = 0;
		}
		iterator--;
	}
	return (terminate);
}

void	ft_print_combn(int n)
{
	char arr[10];

	init_array(arr, n);
	while(!terminate(arr, n))
	{
		update_array(arr,n);
		write(1, arr, n);
		write(1, ", ", 2);
	}
	write(1, arr, n);
	return ;
}

