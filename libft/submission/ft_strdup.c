/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:20:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		size;
	char	*out;
	int		it;

	size = ft_strlen(src);
	it = 0;
	out = NULL;
	if ((size + 1) > 0)
		out = (char *)malloc((size + 1) * sizeof(char));
	if (out == NULL)
		return (0x0);
	while (it < size)
	{
		out[it] = src[it];
		it++;
	}
	out[size] = src[size];
	return (out);
}
