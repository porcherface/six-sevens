/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 16:59:12 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/07 16:59:15 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
int ft_sqrt(int nb)
{
	int it;

	it = 0;
	if (nb <= 0)
		return (0);
	while ((it * it < nb) && (it <= 50000))
		it++;
	if ((it * it)== nb)
		return (it);
	return (0);
}