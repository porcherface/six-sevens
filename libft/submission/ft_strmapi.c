/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 13:21:14 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:21:19 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	idx;

	out = ft_strdup(s);
	if (!out)
		return (0x0);
	idx = 0;
	while (s[idx])
	{
		out[idx] = f(idx, s[idx]);
		idx++;
	}
	return (out);
}
