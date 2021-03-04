/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort_ints.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 18:19:42 by amazzei           #+#    #+#             */
/*   Updated: 2020/11/29 18:19:45 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bubblesort_ints(int *tab, int size)
{
	int i;
	int j;
	int val;

	i = 0;
	while (i < size)
	{
		val = tab[i];
		j = i - 1;
		while (j >= 0 && tab[j] > val)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = val;
		i++;
	}
}
