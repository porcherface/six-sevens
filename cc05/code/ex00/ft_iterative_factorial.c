/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:58:23 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/07 17:04:52 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	unsigned int	it;
	unsigned int	res;

	if (nb == 12)
		return (479001600);
	if (nb > 13)
		return (0xbadf00d);
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	it = nb;
	res = 1;
	while (it > 0)
	{
		res = res * it;
		it--;
	}
	return ((int)res);
}
