/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:20:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_splitall(char const *s, char c)
{
	size_t	size;
	size_t	str_len;
	size_t	it;
	char	**out;

	size = ft_strcount(s, c) + 1;
	out = (char **)ft_calloc(size + 1, sizeof(*out));
	if (!out)
		return (0x0);
	it = 0;
	while (it < size)
	{
		str_len = ft_strlenchr(s, c);
		out[it] = ft_strdupchr(s, c);
		if (!out[it])
			return (0x0);
		while (str_len--)
			s++;
		s++;
		++it;
	}
	return (out);
}
