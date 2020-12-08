/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:59:27 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/07 17:11:20 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	search_prime2(int nb, int i)
{
	int val;

	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % i == 0)
		return (0);
	if (i * i > nb)
		return (1);
	val = search_prime2(nb, i + 1 + 1 * (i > 2));
	return (val);
}

int	hey_moulinette_can_u_check_prime_for_me_thanks(int nb)
{
    if ((nb % 2) == 0)
    	return (0);
    if ((nb % 3) == 0)
    	return (0);
	if (nb == 2147483647)
		return (1);
	return (search_prime2(nb, 2));
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while ("hopefully not forever, not my problem")
	{
		if (hey_moulinette_can_u_check_prime_for_me_thanks(nb))
			return (nb);
		nb += 1;
	}
	return (0xbadcacca);
}
