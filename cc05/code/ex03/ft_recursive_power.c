/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:58:57 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/07 16:58:59 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power == 0 && nb == 0)
		return (1);
	if (nb == 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 1)
		return (1);
	nb *= ft_recursive_power(nb, power - 1);
	return (nb);
}
