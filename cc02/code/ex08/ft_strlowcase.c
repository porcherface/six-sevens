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

int		check_alphau8(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	go_lowcase8(char c)
{
	return (c + 0x20);
}

char	*ft_strlowcase(char *str)
{
	int it;

	it = 0;
	while (str[it] != '\0')
	{
		if (check_alphau8(str[it]))
		{
			str[it] = go_lowcase8(str[it]);
		}
		it++;
	}
	return (str);
}
