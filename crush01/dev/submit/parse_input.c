/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboldini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:15:34 by rboldini          #+#    #+#             */
/*   Updated: 2020/12/06 17:53:15 by rboldini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		my_atoi(const char *input, int i)
{
	int accumulator;
	int curr_val;

	curr_val = 0;
	accumulator = 0;
	while (input[i] != ' ' && input[i] != '\0')
	{
		curr_val = (int)(input[i] - '0');
		if (input[i + 1] >= '0' && input[i + 1] <= '9')
		{
			accumulator = accumulator * 10 + curr_val;
		}
		else if (input[i + 1] == ' ' || input[i + 1] == '\0')
		{
			accumulator = accumulator * 10 + curr_val;
		}
		i++;
	}
	return (accumulator);
}

void	pop_rules(char *input, int *rules, int i)
{
	int i2;

	i2 = 0;
	if (input[i] == ' ')
		i++;
	while (input[i] != '\0')
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			rules[i2] = my_atoi(input, i);
			i2++;
			if (input[i + 1] != ' ')
				i++;
		}
		i++;
	}
}

int		check_rules(int *rules, int size)
{
	int i;
	int maxv;

	i = 0;
	maxv = 0;
	while (i < size)
	{
		if (rules[i] == 0)
			return (-2);
		if (rules[i] > maxv)
			maxv = rules[i];
		i++;
	}
	if (maxv != size)
		return (-2);
	else
		return (0);
}

int		ft_str_is_numeric(char *str)
{
	char		*p_str;
	int			a;

	p_str = str;
	while (*p_str != '\0')
	{
		if ((*p_str < '0' || *p_str > '9') && *p_str != ' ')
			return (-2);
		p_str++;
	}
	a = 0;
	if (str[a] == ' ')
		return (-2);
	while (str[a] != '\0')
	{
		if (str[a] == ' ')
		{
			if (str[a + 1] == ' ')
				return (-2);
		}
		a++;
	}
	if (str[a - 1] == ' ')
		return (-2);
	return (1);
}

int		parse_input(int size, char *argv, int *rules)
{
	int		i;
	int		k;
	char	*str;

	i = 0;
	str = argv;
	if (ft_str_is_numeric(str) != 1)
		return (ft_str_is_numeric(str));
	if (size > 0)
	{
		i = 0;
		pop_rules(str, rules, i);
		k = 0;
	}
	else
		return (-4);
	return (1);
}
