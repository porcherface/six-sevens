/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 12:49:53 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/03 12:50:02 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int it;

	it = 0;
	while ((s1[it] != '\0') && (s2[it] != '\0') && (it < n))
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
	if (it == n)
	{
		return (0);
	}
	else
	{
		if (s1[it] > s2[it])
			return (1);
		if (s1[it] < s2[it])
			return (-1);
	}
	return (0);
}	
