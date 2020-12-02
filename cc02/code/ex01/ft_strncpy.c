/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:06:16 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/01 12:06:54 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int it;

	it = 0;
	while (it < n && src[it] != '\0')
	{
		dest[it] = src[it];
		it++;
	}
	while (it < n)
	{
		dest[it] = '\0';
	}
	return (dest);
}
