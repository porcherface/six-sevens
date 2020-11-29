/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:18:16 by amazzei           #+#    #+#             */
/*   Updated: 2020/11/29 18:19:00 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int iterator;
	int tmp1;
	int tmp2;

	iterator = 0;
	while (iterator < size / 2)
	{
		tmp1 = tab[iterator];
		tmp2 = tab[size - 1 - iterator];
		tab[iterator] = tmp2;
		tab[size - 1 - iterator] = tmp1;
	}
}
