/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:20:54 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/02 17:54:19 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_alpha9(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int		check_num9(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	go_upcase9(char c)
{
	return (c - 0x20);
}

char	*ft_strcapitalize(char *str)
{
	int it;
	int is_first;

	it = 0;
	is_first = 1;
	while (str[it] != '\0')
	{
		if ((check_alpha9(str[it]) || check_num9(str[it])) && is_first)
		{
			is_first = 0;
			if (check_alpha9(str[it]))
			{
				str[it] = go_upcase9(str[it]);
			}
		}
		if (str[it] == ' ' || str[it] == '.' || str[it] == '\n')
		{
			is_first = 1;
		}
		it++;
	}
	return (str);
}
