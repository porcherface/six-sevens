/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:47:53 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/01 16:47:54 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_thisaddr(void *addr)
{
}

void *ft_print_memory(void *addr, unsigned int size)
{
	unsigned int it;

	it = 0;
	while(it < size)
	{
		print_thisaddr( addr+it);
		//write(1, addr+it, 16);
		it++;
	}
	return (addr);
}
