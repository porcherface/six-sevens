/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:18:41 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/03 17:18:44 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_num3(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int digits_to_number(unsigned int digits[], unsigned int numdigits)
{

	return 0;
}
int ft_atoi(char *str)
{
	unsigned int 	it;
	unsigned int 	it2;
	int 			multi;
	unsigned int 	digits[32];

	it = 0;
	it2 = 0;
	multi = 1;
	while(str[it] != '\0')
	{
		if(str[it] == '-')
		{
			multi *= -1;
		}
		if (check_num3(str[it]))
		{
			digits[it2] = str[it] - '0';
			it2++;
		}
		it++;
	}	
	return (digits_to_number(digits, it2));
}
