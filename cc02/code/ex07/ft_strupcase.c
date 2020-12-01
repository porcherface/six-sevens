/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:30:30 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/01 12:30:44 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int check_alphal(char c)
{
	if (c >= 'a' && c <= 'z')
	   return 1;
	return 0;	
}

char go_upcase(char c)
{
	return (c + 26);	
}

char* ft_strupcase(char *str)
{
	int it;
	
	while(str[it] != '\0')	
	{
		if (check_alphal(str[it]))
		{
			str[it] = go_upcase(str[it]);
		}
	}
	return (str);
}
