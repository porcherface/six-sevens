/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:29:41 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/01 12:30:07 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_print6(char c)
{
	if (c >= 0x20 && c <= 0x7f)
		return (1);
	return (0);
}

int	ft_str_is_printable(char *str)
{
	int it;

	it = 0;
	while (str[it] != '\0')
	{
		if (!check_print6(str[it]))
		{
			return (0);
		}
		it++;
	}
	return (1);
}
