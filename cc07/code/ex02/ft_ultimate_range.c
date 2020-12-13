/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:20:59 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int it;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	size = max - min;
	if (size)
	{
		*range = (int *)malloc(size * sizeof(int));
		it = 0;
		while (it < size)
		{
			range[it] = min + it;
			it++;
		}
	}
	if (!range)
		return (-1);
	return (size);
}
