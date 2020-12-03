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
		return (2);
	if (c == '+' || c == '-')
		return (1);
	if (c == ' ' || c == '\n')
		return (1);
	if (c == '\t' || c == '\v')
		return (1);	 
	if (c == '\f' || c == '\r')
		return (1);

	return (0);
}
 
int digits_to_number(int digits[], unsigned int num, int sign)
{
	unsigned int nb;
	unsigned int it;
	int multi;

	if (num == 0)
		return (0);
	it = num - 1;
	nb = 0;
	multi = 1;
	while(it + 1)
	{
		nb += digits[it] * multi;
		multi *= 10;
		it--;
	}
	return nb * sign;
}

int ft_atoi(char *str)
{
	unsigned int	it;
	unsigned int	it2;
	int		multi;
	int		digits[256];
 
	it = 0;
	it2 = 0;
	multi = 1;
	while(str[it] != '\0' && check_num3(str[it]))
	{
		if(str[it] == '-')
		{
			multi *= -1;
		}
		if (check_num3(str[it]) == 2)
		{
			digits[it2] = str[it] - '0';
			it2++;
		}
		it++;
	}
	 
	return (digits_to_number(digits, it2, multi));
}
