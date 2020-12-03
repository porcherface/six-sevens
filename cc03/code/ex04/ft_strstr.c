/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:50:27 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/03 12:50:29 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int it;
	unsigned int jt;

	it = 0;
	jt = 0;
	while (str[it] != '\0')
	{
		while (str[it + jt] == to_find[jt])
		{
			jt++;
			if (to_find[jt] == '\0')
			{
				return (str + it);
			}
		}
		jt = 0;
		it++;
	}
	return ((char *)0x0000);
}
