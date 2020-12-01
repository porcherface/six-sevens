/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercasecase.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:29:12 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/01 12:29:14 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_alphau5(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_str_is_uppercase(char *str)
{
	int it;

	it = 0;
	while (str[it] != '\0')
	{
		if (!check_alphau5(str[it]))
		{
			return (0);
		}
		it++;
	}
	return (1);
}
