/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 12:24:01 by amazzei           #+#    #+#             */
/*   Updated: 2020/11/28 12:24:01 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void ft_setkey(char *key)
{
	int k;

	k = 0;
	key[0] = 'o' * (k == 0) + '/' * (k == 1) + 'A' * (k == 2);
	key[0] += 'A' * (k == 3) + 'A' * (k == 4);
	key[1] = 'o' * (k == 0) + '\\' * (k == 1) + 'C' * (k == 2);
	key[1] += 'A' * (k == 3) + 'C' * (k == 4);
	key[2] = 'o' * (k == 0) + '\\' * (k == 1) + 'A' * (k == 2);
	key[2] += 'C' * (k == 3) + 'C' * (k == 4);	
	key[3] = 'o' * (k == 0) + '/' * (k == 1) + 'C' * (k == 2);
	key[3] += 'C' * (k == 3) + 'A' * (k == 4);	
	key[4] = '|' * (k == 0) + '*' * (k == 1) + 'B' * (k == 2);
	key[4] += 'B' * (k == 3) + 'B' * (k == 4);	
	key[5] = '-' * (k == 0) + '*' * (k == 1) + 'B' * (k == 2);
	key[5] += 'B' * (k == 3) + 'B' * (k == 4);	
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
