/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:09:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/01 12:24:19 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	t_byte *ptr;

	ptr = (t_byte *)s;
	while (n)
	{
		*ptr = 0x0;
		ptr++;
		n--;
	}
	return ;
}
