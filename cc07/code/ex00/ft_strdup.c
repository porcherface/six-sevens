/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/09 14:17:22 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
int cc07_strlen(char *src)
{
	int it;

	it = 0;
	while( src[it] != '\0')
		it++;
	return (it);
}

char *ft_strdup(char *src)
{
	int size;
	char *out;
	int it;

	size = cc07_strlen(src);
	it = 0;
	out = NULL;
	if (size > 0)
		out = (char *)malloc((size + 1) * sizeof(char));
	if( out == NULL)
		return (NULL);
	while(it < size)
	{
		out[it] = src[it];
		it++;
	}
	out[size] = src[size];
	return (out);
}