/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:29:54 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 15:29:56 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int					ft_strlen_c8(char *str)
{
	int it;

	it = 0;
	while (str[it] != '\0')
	{
		it++;
	}
	return (it);
}

void				ft_strvcpy(char *dest, char *src)
{
	int it;

	it = 0;
	while (src[it] != '\0')
	{
		dest[it] = src[it];
		it++;
	}
	if (src[it] == '\0')
		dest[it] = src[it];
	return ;
}

char				*ft_strdup(char *src)
{
	int		size;
	char	*out;
	int		it;

	size = ft_strlen_c8(src);
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
	out[size] = src[size];
	return (out);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*out;
	int				it;

	it = 0;
	if (ac)
		out = (t_stock_str *)malloc((ac + 1) * sizeof(t_stock_str));
	if (!out)
		return (0x0);
	while (it < ac)
	{
		out[it].size = ft_strlen_c8(av[it]);
		out[it].str = av[it];
		if (out[it].size)
			out[it].copy = ft_strdup(av[it]);
		if (!out[it].copy)
			return (0x0);
		it++;
	}
	out[it].str = NULL;
	return (out);
}
