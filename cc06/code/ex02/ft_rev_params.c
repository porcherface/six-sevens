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

int	main(int argc, char **argv)
{
	int it;
	int jt;

	jt = argc - 1;
	while (jt > 0)
	{
		it = 0;
		while (argv[jt][it])
		{
			write(1, &argv[jt][it], 1);
			it++;
		}
		write(1, "\n", 1);
		jt--;
	}
}