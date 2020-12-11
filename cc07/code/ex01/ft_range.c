/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:20:52 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *out;
	int it;

	if (min >= max)
		return (0x0);
	size = max - min;
	if (size)
	{
		out = (int *)malloc(size * sizeof(int));
		it = 0;
		while (it < size)
		{
			out[it] = min + it;
			it++;
		}
	}
	if (!out)
		return (0x0);
	return (out);
}
