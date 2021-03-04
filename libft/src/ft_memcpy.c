/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:20:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	t_byte *bsrc;
	t_byte *bdst;

	if (!dst)
		return (0x0);
	bdst = (t_byte *)dst;
	if (!src)
	{
		*bdst = 0;
		return (dst);
	}
	bsrc = (t_byte *)src;
	while (n--)
	{
		*bdst = *bsrc;
		bdst++;
		bsrc++;
	}
	return (dst);
}
