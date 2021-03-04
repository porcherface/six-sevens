/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:50:35 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/03 12:50:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t it;
	size_t jt;
	size_t slen;

	slen = ft_strlen(src);
	it = 0;
	jt = 0;
	while (dst[it] && it < size)
		it++;
	while (src[jt] && (it + jt + 1) < size)
	{
		dst[it + jt] = src[jt];
		jt++;
	}
	if (it < size)
		dst[it + jt] = '\0';
	return (it + slen);
}
