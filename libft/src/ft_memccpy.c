/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:20:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t it;
	t_byte *bdst;
	t_byte *bsrc;

	if (!src || !dst)
		return (0x0);
	bsrc = (t_byte*)src;
	bdst = (t_byte*)dst;
	it = 0;
	while (it < n)
	{
		bdst[it] = bsrc[it];
		if (bsrc[it] == (t_byte)c)
		{
			return (bdst + it + 1);
		}
		it++;
	}
	return (0x0);
}
