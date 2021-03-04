/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:20:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdupchr(const char *src, int c)
{
	int		size;
	char	*out;
	int		it;

	size = ft_strlenchr(src, c);
	it = 0;
	out = NULL;
	if (size > 0)
		out = (char *)malloc((size + 1) * sizeof(char));
	if (out == NULL)
		return (0x0);
	while (it < size)
	{
		out[it] = src[it];
		it++;
	}
	out[size] = 0;
	return (out);
}
