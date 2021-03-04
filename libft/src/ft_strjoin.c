/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:20:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	len;
	size_t	it;
	size_t	jt;

	len = ft_strlen(s1) + ft_strlen(s2);
	out = (char *)ft_calloc(sizeof(*s1), (len + 1));
	if (!out)
		return (0x0);
	jt = 0;
	it = 0;
	while (s1[it])
	{
		out[it] = s1[it];
		it++;
	}
	while (s2[jt])
	{
		out[it + jt] = s2[jt];
		jt++;
	}
	out[it + jt] = 0;
	return (out);
}
