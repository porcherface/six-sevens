/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:20:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t		ft_strlenchr2(const char *str, int c)
{
	size_t it;

	it = 0;
	while (str[it] && (str[it] != (char)c))
		it++;
	return (it);
}

static char			*ft_strdupchr2(const char *src, int c)
{
	int		size;
	char	*out;
	int		it;

	size = ft_strlenchr2(src, c);
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

static int			count_words(char const *s, char c)
{
	size_t	iters[2];
	int		flags[2];

	flags[1] = 0;
	flags[0] = 0;
	iters[1] = 0;
	iters[0] = 0;
	while (s[iters[0]])
	{
		if (c == s[iters[0]])
			flags[0] = 1;
		else
		{
			flags[1] = 1;
			if (flags[0])
			{
				iters[1]++;
				flags[0] = 0;
			}
		}
		iters[0]++;
	}
	if (!flags[1])
		return (-1);
	return (iters[1]);
}

char				**ft_split(char const *s, char c)
{
	size_t	size;
	size_t	it;
	char	**out;

	if (!s)
		return (0x0);
	while (*s == c && c)
		s = ft_strchr(s, c) + 1;
	size = count_words(s, c) + 1;
	out = (char **)ft_calloc(size + 1, sizeof(*out));
	it = 0;
	while ((it < size) && out)
	{
		out[it] = ft_strdupchr2(s, c);
		s = ft_strchr(s, c) + 1;
		if (it != (size - 1))
		{
			while (*s == c)
				s = ft_strchr(s, c) + 1;
		}
		if (!out[it])
			return (0x0);
		it++;
	}
	return (out);
}
