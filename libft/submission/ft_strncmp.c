/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:49:53 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/03 12:50:02 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	it;

	it = 0;
	while (s1[it] && s2[it] && !((t_byte)s1[it] - (t_byte)s2[it]) && it < n)
		it++;
	if (it == n)
		return (0);
	return ((t_byte)s1[it] - (t_byte)s2[it]);
}
