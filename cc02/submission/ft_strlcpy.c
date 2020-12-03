/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:16:49 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/02 18:00:07 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int it;

	it = 0;
	if (size == 0)
	{
		return (0);
	}
	while (it < (size - 1) && src[it] != '\0')
	{
		dest[it] = src[it];
		it++;
	}
	if (src[it] == '\0')
	{
		dest[it] = src[it];
		return (it);
	}
	if (it == size - 2)
		dest[it + 1] = '\0';
	return (it);
}
