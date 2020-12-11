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

int		ft_strlen_c8(char *str)
{
	int it;

	it = 0;
	while (str[it] != '\0')
	{
		it++;
	}
	return (it);
}

void	ft_strvcpy(char *dest, char *src)
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


struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*out;
	unsigned int	it;
	
	it = 0;
	if (ac)
		out = (t_stock_str *)malloc(ac * sizeof(t_stock_str));
	while (it < size)
	{
		out[it].size = ft_strlen_c8(av[it]);
		if (out[it].size)
		{
			out[it].str = (char *)malloc((1 + out[it].size) * sizeof(char));
			out[it].copy = (char *)malloc((1 + out[it].size) * sizeof(char));
		}
		if(!out[it].str)
			return (0x0);
		else
			ft_strlcpy(out[it].str, av[it]);
		if(!out[it].copy)
			return (0x0);
		else
			ft_strlcpy(out[it].str, out[it].copy);	
		it++;
	}
	return (out);
}
