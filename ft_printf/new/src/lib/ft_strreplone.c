/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:20:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  
** finds the first instance of old into str
** and substitutes it with new
*/

#include "libft.h"
char			*ft_strreplone(char *str, char *old, char *new)
{
	size_t	len[3];
	size_t	it[2];
	char	*out;
	char	*dart;

	len[0] = ft_strlen(str);
	len[1] = ft_strlen(old);
	len[2]= ft_strlen(new);
	dart = ft_strnstr(str, old, len[0]);
	it[0] = 0;
	it[1] = 0;

	if (!dart)
		out =  ft_strdup(str);
	else
	{
		out = ft_strnew(len[0] - len[1] + len[2]);
		while(str + it[0] < dart)	
		{
			out[it[0]] = str[it[0]];
			it[0]++;
		}
		while(it[1] < len[2])
		{
			out[it[0] + it[1]] = new[it[1]];
			it[1]++;
		}
		while(str[it[0] + len[1]])
		{
			out[it[0] + it[1]] = str[len[1] + it[0]];
			it[0]++;
		}
	}
	return (out);
}