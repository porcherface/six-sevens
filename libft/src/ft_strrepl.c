/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:20:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*  
** finds every instance of old into str
** and substitutes it with new
** 
** achieved by calling replone several times
*/

char	*ft_strrepl(char *str, char *old, char *new)
{
	char	*out;

	while ("forever and ever")
	{
		out = ft_strreplone(str, old, new);
		if (ft_strcmp(out, str) == 0)
		{
			return (out);
		}
	}
}