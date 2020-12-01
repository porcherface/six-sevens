/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:32:47 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/01 12:32:50 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_alphau(char c)
{
	if (c >= 'A' && c <= 'Z')
	   return 1;
	return 0;	
}

char go_lowcase(char c)
{
	return (c - 26);	
}

char* ft_strlowcase(char *str)
{
	int it;
	
	while(str[it] != '\0')	
	{
		if (check_alphau(str[it]))
		{
			str[it] = go_lowcase(str[it]);
		}
	}
	return (str);
}
