/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2021/03/03 13:20:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strcount(const char *s, const char *c)
{
	size_t out;
	size_t it;
	size_t jt;
	
	out = 0;
	it = 0;
	jt = 0;
	while(s[it])
	{
		jt = 0;
		while (s[it + jt] == c[jt] && c[jt])
		{
			if (!c[jt + 1])
			{
				out++;
				it += jt; 
			}	
			jt++;
		}
		it++;
	}
	return (out);
}
