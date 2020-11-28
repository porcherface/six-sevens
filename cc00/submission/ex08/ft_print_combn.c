/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 14:48:08 by amazzei           #+#    #+#             */
/*   Updated: 2020/11/27 14:48:16 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_init_array(int *arr, int n)
{
	int	iterator;

	iterator = 0;
	while (iterator < n)
	{
		arr[iterator] = iterator;
		iterator++;
	}
	return ;
}

void	ft_update_array(int *arr, int n, int level)
{
	int	last_value;

	last_value = n - 1;
	if (arr[last_value] != 9 - level)
	{
		arr[n - 1]++;
	}
	else
	{
		if (n - 1 > 0)
		{
			ft_update_array(arr, n - 1, level + 1);
			arr[last_value] = arr[last_value - 1] + 1;
		}
		else
		{
			arr[n - 1] = 0;
		}
	}
	return ;
}

int		ft_terminate_it(int *arr, int n)
{
	int	iterator;
	int	terminate;

	terminate = 1;
	iterator = 0;
	while (iterator < n)
	{
		if (arr[iterator] != 9 + iterator - n + 1)
		{
			terminate = 0;
		}
		iterator++;
	}
	return (terminate);
}

void	ft_write_ntoc(int *arr, int n)
{
	char	c;
	int		iterator;

	iterator = 0;
	while (iterator < n)
	{
		c = arr[iterator] + '0';
		write(1, &c, 1);
		iterator++;
	}
	return ;
}

void	ft_print_combn(int n)
{
	int	arr[10];
	int	*arrp;

	arrp = arr;
	if (n <= 10 && n >= 1)
	{
		ft_init_array(arrp, n);
		ft_write_ntoc(arr, n);
		while (!ft_terminate_it(arr, n))
		{
			write(1, ", ", 2);
			ft_update_array(arrp, n, 0);
			ft_write_ntoc(arr, n);
		}
	}
	return ;
}
