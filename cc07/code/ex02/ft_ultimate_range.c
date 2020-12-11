/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/09 14:17:22 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int it;

	if (min >= max)
		return (-1);
	size = max - min;
	if(size)
	{
		*range = (int *)malloc(size * sizeof(int));
		it = 0;
		while(it < size)
		{
			out[it] = min + it;
			it++;
		}	
	}
	if (!out)
		//free out ?? 
		return (-1);
	return (size);
}
