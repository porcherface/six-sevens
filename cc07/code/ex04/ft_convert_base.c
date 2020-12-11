/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 13:21:14 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/11 13:21:19 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi_base_yee(char *str, char *base);

int		count_base(char *b)
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

char	*ft_itoa_base64(int nb, char *base, int *num_bytes)
{
	int	dig[64];
	int	base_num;
	int	it;
	char static_array_yeee[64];

	base_num = count_base(base);
	if (base_num < 2)
		return 0x0;
	if (nb == 0)
	{
		static_array_yeee[0] = base[0];
		num_bytes = 1;
		return (static_array_yeee);
	}
	it = 0;
	while (nb != 0)
	{
		dig[it] = nb % base_num;
		nb = (nb - dig[it]) / base_num;
		dig[it] = dig[it] * (dig[it] < 0) * -1 + dig[it] * (dig[it] >= 0)
		static_array_yeee = base[dig[it]];
		it++;
	}
	num_bytes = it + 1;
	return (static_array_yeee);
}


char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int number;
	int num_bytes;
	char static_array_yeee[64];
	char *out;
	int it;

	it = 0;
	out = NULL;
	num_bytes = 0;
	number = ft_atoi_base_yee(nbr, base_from, &num_bytes);
	if (num_bytes)
		return (NULL);
	num_bytes = 0;
	static_array_yeee = ft_itoa_base64(number, base_to, &num_bytes);
	if (num_bytes && static_array_yeee)
	{
		out = (char *)malloc(num_bytes * sizeof(char));
		out[it] = static_array_yeee[it];
		it++;
	}
	return (out);
}
