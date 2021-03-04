/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:49:04 by amazzei           #+#    #+#             */
/*   Updated: 2021/01/23 16:49:33 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check_atoi(char c)
{
	if (c >= '0' && c <= '9')
		return (2);
	if ((c == '+') || (c == '-'))
		return (-1);
	if ((c == ' ') || (c == '\n'))
		return (1);
	if ((c == '\t') || (c == '\v'))
		return (1);
	if ((c == '\f') || (c == '\r'))
		return (1);
	return (0);
}

static int	digits_to_number(int digits[], unsigned int num, int sign)
{
	unsigned int	nb;
	unsigned int	it;
	int				multi;

	if (num == 0)
		return (0);
	it = num - 1;
	nb = 0;
	multi = 1;
	while (it + 1)
	{
		nb += digits[it] * multi;
		multi *= 10;
		it--;
	}
	return (nb * sign);
}

int			ft_atoi(const char *str)
{
	unsigned int	it;
	unsigned int	it2;
	int				sign;
	int				digits[256];

	it = 0;
	it2 = 0;
	sign = 1;
	while (check_atoi(str[it]) == 1)
		it++;
	if (check_atoi(str[it]) == -1)
	{
		if (str[it] == '-')
			sign = -1;
		it++;
	}
	while (check_atoi(str[it2 + it]) == 2)
	{
		digits[it2] = str[it2 + it] - '0';
		it2++;
	}
	return (digits_to_number(digits, it2, sign));
}
