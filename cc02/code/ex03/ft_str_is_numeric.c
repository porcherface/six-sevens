/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:24:47 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/01 12:25:27 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_num(char c)
{
	if (c >= '0' && c <= '9' )
	   return 1;
	return 0;	
}

int ft_str_is_numeric(char *str)
{
	int it;
	
	while(str[it] != '\0')	
	{
		if (!check_num(str[it]))
		{
			return (0);
		}
	}
	return (1);
}
