/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush99.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 01:43:33 by amazzei           #+#    #+#             */
/*   Updated: 2020/11/28 01:44:27 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void ft_setkey(char *key)
{
	key[0] = 'A';
	key[1] = 'C';
	key[2] = 'C';
	key[3] = 'A';
	key[4] = 'B';
	key[5] = 'B';
	key[6] = ' ';
	return ; 
}

void ft_setchar(char *c, int coords[], int sizes[], char key[])
{
	*c = key[6];
	if(coords[0] == 0)
	{
		if(coords[1] == 0)
			*c = key[0];
		else if(coords[1] == sizes[1] - 1)
			*c = key[1];
		else
			*c = key[4];
	}
	else if(coords[0] == sizes[0] - 1)
	{
		if(coords[1] == 0)
			*c = key[2];
		else if(coords[1] == sizes[1] - 1)
			*c = key[3];
		else
			*c = key[4];	
	}
	else
	{
		if((coords[1] == 0) || (coords[1] == sizes[1] - 1))
			*c = key[5];
	}
	ft_putchar(*c);
}
 

void rush(int x, int y)
{
	int coords[2];
	int sizes[2];
	char key[7];
	char c;
	
	sizes[0] = x;
	sizes[1] = y;
	if (sizes[0] > 0 && sizes[1] > 0)
	{
		ft_setkey(key);
		coords[0] = 0;
		coords[1] = 0;
		while(coords[1] < sizes[1])
		{	
			while(coords[0] < sizes[0])
			{
				ft_setchar(&c, coords, sizes, key);
				coords[0]++;
			}
			coords[1]++;
			coords[0] = 0;
			ft_putchar('\n');
		}
	}
	return ;
}
