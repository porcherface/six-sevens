/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:20:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	t_byte *bsrc;
	t_byte *bdst;

	bsrc = (t_byte *)src;
	bdst = (t_byte *)dst;
	if ((bsrc == 0x0) && (bdst == 0x0))
	{
		return (0x0);
	}
	if ((bsrc < bdst) && (bdst < bsrc + n))
	{
		bdst += n;
		bsrc += n;
		while (n--)
		{
			*--bdst = *--bsrc;
		}
	}
	else
	{
		while (n--)
			*bdst++ = *bsrc++;
	}
	return (dst);
}
