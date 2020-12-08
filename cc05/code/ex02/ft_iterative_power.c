/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:58:48 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/07 16:58:51 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int it;
	int val;

	if (power == 0)
		return (1);
	if (nb == 0)
		return (0);
	if (nb == 1)
		return (1);
	if (power < 0)
		return (0);
	it = 0;
	val = 1;
	while (it < power)
	{
		val *= nb;
		it++;
	}
	return (val);
}
