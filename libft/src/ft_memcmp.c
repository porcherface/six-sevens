/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:09:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/01 12:24:19 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	it;
	t_byte	*bs1;
	t_byte	*bs2;

	if (n == 0)
		return (0);
	it = 0;
	bs1 = (t_byte *)s1;
	bs2 = (t_byte *)s2;
	while (((t_byte)bs1[it] - (t_byte)bs2[it]) == 0 && it < n - 1)
		it++;
	return ((t_byte)bs1[it] - (t_byte)bs2[it]);
}
