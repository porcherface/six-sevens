/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:59:05 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/07 16:59:06 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int a;
	
	if ((index < 47) && index > 1)
		a = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	if (index >= 47)
		return (0xbadf00d);
	if (index < 0)
		return (-1);
	return (a);
}
