/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:20:40 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	set_base_re(char *b)
{
	int	it;

	it = 0;
	while (it < 10)
	{
		b[it] = '0' + it;
		it++;
	}
	return (10);
}

static void	print_it_base_re(int d[], int s, char *base, int fd)
{
	char c;

	s -= 1;
	while (s >= 0)
	{
		c = base[d[s] * (d[s] < 0) * -1 + d[s] * (d[s] >= 0)];
		write(fd, &c, 1);
		s--;
	}
}

void		ft_putnbr_fd(int nb, int fd)
{
	int		digits[20];
	int		base_num;
	int		it;
	char	base[11];

	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	base_num = set_base_re(base);
	if (base_num < 2)
	{
		return ;
	}
	write(fd, "-", 1 * (nb < 0));
	it = 0;
	while (nb != 0)
	{
		digits[it] = nb % base_num;
		nb = (nb - digits[it]) / base_num;
		it++;
	}
	print_it_base_re(digits, it, base, fd);
}
