/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:18:41 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/05 14:36:31 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	check_num3(char c)
{
	if (c >= '0' && c <= '9')
		return (2);
	if (c == ' ')
		return (1);
	return (0);
}
 
int	digits_to_number(int digits[], unsigned int num, int sign)
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

int	ft_atoi2(char *str, int shift)
{
	unsigned int	it;
	unsigned int	it2;
	int		multi;
	int		digits[256];
 
	it = 0;
	it2 = 0;
	multi = 1;
	while(str[it + shift] != '\0' && check_num3(str[it + shift]))
	{
		if(str[it + shift] == '-')
		{
			multi *= -1;
		}
		if (check_num3(str[it + shift]) == 2)
		{
			digits[it2] = str[it + shift] - '0';
			it2++;
		}
		it++;
	}
	 
	return (digits_to_number(digits, it2, multi));
}

int	parse_input(int argc, char **argv, int *rules, int *board)
{
	int it;
	int size = 0;
	int thisrule = 0;
	char c;

	it = 0;
	while (argv[1][it] != '\0')
	{
		if ((argv[1][it]) == " ")
		{
			thisrule = ft_atoi2(argv[1]);
			c = thisrule + '0';
			write(1, &c, 1);
		}
		it++;
	}

}