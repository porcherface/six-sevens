/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:20:54 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/01 14:35:05 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int check_alpha9(char c)
{
	if ((c >= 'a' && c <= 'z') || (c>='A' && c<= 'Z'))
	   return 1;
	return 0;
}

int check_num9(char c)
{
	if (c >= '0' && c <= '9' )
	   return 1;
	return 0;
}

char go_upcase9(char c)
{
	return (c + 26);
}

char *ft_strcapitalize(char *str)
{
	int it;
	int is_first;

	it = 0;
	is_first = 1;
	while (str[it] != '\0')
	{
		if( check_alpha9(str[it]) || check_num9(str[it]))
		{
			is_first = 0;
			if( check_alpha9(str[it]))
			{
				str[it] = go_upcase9(str[it]);
			}
		}
		it++;
	}
	return (str);
}