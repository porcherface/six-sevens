/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:58:37 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/07 16:58:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int res;

	if (nb > 13)
		return (0xbadf00d);
	res = 0;
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	res = ft_recursive_factorial(nb - 1);
	return (nb * res);
}
