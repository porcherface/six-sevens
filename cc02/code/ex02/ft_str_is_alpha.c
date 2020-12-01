/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:09:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/01 12:24:19 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_alpha(char c)
{
	if (c >= 'a' && c <= 'z' || c>='A' && c<= 'Z')
	   return 1;
	return 0;
}

int ft_str_is_alpha(char *str)
{
	int it;
	
	while(str[it] != '\0')	
	{
		if ( !check_alpha(str[it]))
		{
			return (0);
		}
	}
	return (1);
}
