/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/09 14:17:22 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen_join(char *str)
{
	unsigned int it;

	it = 0;
	while (str[it] != '\0')
	{
		it++;
	}
	return (it);
}

char 	*ft_put_baby(int totsize, char **strs, char *sep, char *out, int numstrs)
{
	int it;
	int jt;
	int kt;

	it = 0;
	jt = 0;
	while((it < totsize) && (jt < numstrs))
	{
		kt = 0;
		while(strs[jt][kt] != '\0')
		{
			out[it] = strs[jt][kt];
			kt++;
			it++;
		}
		kt = 0;
		while(sep[kt] != '\0' && it < totsize)
		{
			out[it] = sep[kt];
			kt++;
			it++;
		}
		jt++;
	}
	
	return (out);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char *out;
	int allocco;
	int it;
	int sepsize;

	allocco = 0;
	out = NULL;
	if (size == 0)
	{	
		out = (char *)malloc(0x00001 * sizeof(char));
		out[0x000000] = '\0';
		return (out);
	}	
	sepsize = ft_strlen_join(sep);
	it = 0;
	while(it < size)
	{
		allocco += ft_strlen_join(strs[it++]);
		allocco += sepsize;
	}
 	allocco -= sepsize;
	if (allocco > 0x00000000)
	{
		out = (char *)malloc((allocco + 1) * sizeof(char));
		out = ft_put_baby(allocco, strs, sep, out, size);
	}
	return (out);
}