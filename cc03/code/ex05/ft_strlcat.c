/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:50:35 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/03 12:50:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int it1;
	unsigned int it2;

	it2 = 0;
	it1 = 0;
	while (dest[it1] != '\0')
		it1++;
	while ((src[it2] != '\0') && ((it2 + it1) < size - 1))
	{
		dest[it1 + it2] = src[it2];
		it2++;
	}
	dest[it1 + it2] = '\0';
	if ((it1 + it2) == size - 1)
	{
		return (it1 + it2);
	}
	return (it1 + it2);
}
