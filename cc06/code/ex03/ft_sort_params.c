/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:34:38 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/08 12:36:43 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int it;

	it = 0;
	while (s1[it] != '\0' && s2[it] != '\0')
	{
		if (s1[it] == s2[it])
			it++;
		else
		{
			if (s1[it] > s2[it])
				return (1);
			else
				return (-1);
		}
	}
	if (s1[it] > s2[it])
		return (1);
	if (s1[it] < s2[it])
		return (-1);
	return (0);
}

void	ft_sort_char_tab(char **tab, int start, int size)
{
	int i;
	int j;
	char *val;

	i = start;
	while (i < size)
	{
		val = tab[i];
		j = i - 1;
		while (j >= start && ft_strcmp(tab[j], val) > 0)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = val;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int it;
	int jt;


	ft_sort_char_tab(argv, 1, argc);
	jt = 1;
	while (jt < argc)
	{
		it = 0;
		while (argv[jt][it])
		{
			write(1, &argv[jt][it], 1);
			it++;
		}
		write(1, "\n", 1);
		jt++;
	}
}