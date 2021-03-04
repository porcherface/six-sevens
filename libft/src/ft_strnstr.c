/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:20:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strlen2(char *str)
{
	size_t it;

	it = 0;
	while (str[it] != '\0')
	{
		it++;
	}
	return (it);
}

char			*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;

	if (!*s2)
		return ((char *)s1);
	len = ft_strlen2((char *)s2);
	while (len <= n && *s1)
	{
		if (*s1 == *s2)
		{
			i = 1;
			while (1)
			{
				if (i == len)
					return ((char *)s1);
				if (s1[i] != s2[i])
					break ;
				i++;
			}
		}
		s1++;
		n--;
	}
	return (0x0);
}
