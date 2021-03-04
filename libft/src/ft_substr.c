/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:20:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	slen;
	size_t	it;

	it = 0;
	slen = ft_strlen(s);
	if (!s)
		return (0x0);
	if (slen < start)
		len = 0;
	out = (char *)ft_calloc(sizeof(*out), len + 1);
	if (!out)
		return (0x0);
	while (it < len && s[it + start])
	{
		out[it] = s[it + start];
		++it;
	}
	out[it] = 0;
	return (out);
}
