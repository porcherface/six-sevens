/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:50:09 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/03 12:50:13 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int it1;
	unsigned int it2;

	it1 = 0;
	it2 = 0;
	while (dest[it1] != '\0')
		it1++;
	while (src[it2] != '\0')
	{
		dest[it1 + it2] = src[it2];
		it2++;
	}
	dest[it1 + it2] = '\0';
	return (dest);
}
