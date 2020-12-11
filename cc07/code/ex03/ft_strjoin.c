/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:21:06 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen_join(char *str)
{
	unsigned int it;

	it = 0;
	while (str[it] != '\0')
	{
		it++;
	}
	return (it);
}

char	*ft_put_baby(int *tsize, char **strs, char *sep, char *out)
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

void	alloc_sz_fun(int *alloc_sz, int size)
{
	alloc_sz[0] = 0;
	alloc_sz[1] = size;
	alloc_sz[2] = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*out;
	int		alloc_sz_it[3];
	int		sepsize;

	alloc_sz_fun(alloc_sz_it, size);
	out = NULL;
	if (size == 0)
	{
		out = (char *)malloc(0x00001 * sizeof(char));
		out[0x000000] = '\0';
	}
	sepsize = ft_strlen_join(sep);
	while (alloc_sz_it[2] < size)
	{
		alloc_sz_it[0] += ft_strlen_join(strs[alloc_sz_it[2]++]);
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
