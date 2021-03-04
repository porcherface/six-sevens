/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:21:06 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_put_baby(int *tsize, char **strs, char *sep, char *out)
{
	int it;
	int jt;
	int kt;

	it = 0;
	jt = 0;
	while ((it < tsize[0]) && (jt < tsize[1]))
	{
		kt = 0;
		while (strs[jt][kt] != '\0')
		{
			out[it] = strs[jt][kt];
			kt++;
			it++;
		}
		kt = 0;
		while (sep[kt] != '\0' && it < tsize[0])
		{
			out[it] = sep[kt];
			kt++;
			it++;
		}
		jt++;
	}
	return (out);
}

static void	alloc_sz_fun(int *alloc_sz, int size)
{
	alloc_sz[0] = 0;
	alloc_sz[1] = size;
	alloc_sz[2] = 0;
}

char	*ft_strnjoin(int size, char **strs, char *sep)
{
	char	*out;
	int		alloc_sz_it[3];
	int		sepsize;

	alloc_sz_fun(alloc_sz_it, size);
	out = 0x0;
	if (size == 0)
	{
		out = (char *)malloc(0x00001 * sizeof(char));
		out[0x000000] = 0x0;
	}
	sepsize = ft_strlen(sep);
	while (alloc_sz_it[2] < size)
	{
		alloc_sz_it[0] += ft_strlen(strs[alloc_sz_it[2]++]);
		alloc_sz_it[0] += sepsize;
	}
	alloc_sz_it[0] -= sepsize;
	if (alloc_sz_it[0] > 0x00000000)
	{
		out = (char *)malloc((alloc_sz_it[0] + 1) * sizeof(char));
		out = ft_put_baby(alloc_sz_it, strs, sep, out);
	}
	return (out);
}
