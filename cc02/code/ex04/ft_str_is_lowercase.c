/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:28:33 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/01 12:28:53 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int check_alphal(char c)
{
	if (c >= 'a' && c <= 'z')
	   return 1;
	return 0;	
}

int ft_str_is_lowercase(char *str)
{
	int it;
	
	while(str[it] != '\0')	
	{
		if ( !check_alphal(str[it]))
		{
			return (0);
		}
	}
	return (1);
}
