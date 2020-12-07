/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:22:10 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/03 17:22:11 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		check_num5(char c, char *base, int flag)
{
	int it;

	it = 0;
	while (base[it] != '\0')
	{
		if (c == base[it])
			return (it);
		it++;
	}
	if ((c == '+' || c == '-') && flag)
		return (-3);
	if ((c == ' ' || c == '\n') && flag)
		return (-2);
	if ((c == '\t' || c == '\v') && flag)
		return (-2);
	if ((c == '\f' || c == '\r') && flag)
		return (-2);
	return (-1);
}

int		digits_to_number5(int digits[], unsigned int num, int sign, int cbase)
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
		multi *= cbase;
		it--;
	}
	return (nb * sign);
}

int		count_base5(char *b)
{
	int	it;
	int	jt;

	jt = 0;
	it = 0;
	while (b[it] != '\0')
	{
		if (b[it] == '+' || b[it] == '-')
			return (0);
		if (b[it] >= 0x7f || b[it] < 0x20)
			return (0);
		jt = it + 1;
		while (b[jt] != '\0')
		{
			if (b[it] == b[jt])
				return (0);
			jt++;
		}
		it++;
	}
	return (it * (it > 1));
}

void	init_iterator_gne_gne(unsigned int *it)
{
	it[0] = 0;
	it[1] = 0;
}

int		ft_atoi_base(char *str, char *base)
{
	unsigned int	it[2];
	int				multi;
	int				digits[256];
	int				cbase;
	int				flag;

	cbase = count_base5(base);
	if (cbase < 2)
		return (0);
	init_iterator_gne_gne(it);
	multi = 1;
	flag = 1;
	while ((str[it[0]] != '\0') && (check_num5(str[it[0]], base, flag) != -1))
	{
		if (check_num5(str[it[0]], base, flag) >= 0)
			flag = 0;
		if (str[it[0]] == '-')
			multi *= -1;
		if (check_num5(str[it[0]], base, flag) >= 0)
			digits[it[1]++] = check_num5(str[it[0]], base, flag);
		it[0]++;
	}
	return (digits_to_number5(digits, it[1], multi, cbase));
}
