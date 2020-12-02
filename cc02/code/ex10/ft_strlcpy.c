/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:16:49 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/01 16:16:51 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int it;

	it = 0;
	while (it < (size - 1) && src[it] != '\0')
	{
		dest[it] = src[it];
		it++;
	}
	if (src[it] == '\0' && it < (size - 1))
		dest[it] = src[it];
	if (it == size - 1)
		dest[it] = '\0';
	return (it);
}
