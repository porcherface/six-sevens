/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                           :+:      :+:    :+:   */
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
	key[0] = '/';
	key[1] = '\\';
	key[2] = '\\';
	key[3] = '/';
	key[4] = '*';
	key[5] = '*';
	key[6] = ' ';
	return ; 
}

void ft_setchar(char *c, int *row, int *col, char key[])
{
	*c = key[6];
	if(row[0] == 0)
	{
		if(col[0] == 0)
			*c = key[0];
		else if(col[0] == col[1])
			*c = key[1];
		else
			*c = key[4];
	}
	else if(row[0] == row[1] - 1)
	{
		if(col[0] == 0)
			*c = key[2];
		else if(col[0] == col[1])
			*c = key[3];
		else
			*c = key[4];	
	}
	else
	{
		if(col[0] == 0 || col[0] == col[1] )
			*c = key[5];
	}
	ft_putchar(*c);
}

void ft_putstring(char *key, int *row, int *col)
{
	char c;

	ft_setchar(&c, row, col, key);
	
	if (col[0] < col[1])
	{
 		col[0]++;
 		ft_putstring(key, row, col);
	}
	if (col[0] == col[1])
	{
		ft_putchar('\n');
		col[0] = 0;
	}
	return ;
}	

void rush(int x, int y)
{
	int row[2];
	int col[2];
	char key[7];


	ft_setkey(key);
	row[0] = 0;
	row[1] = y;
	col[0] = 0;
	col[1] = x;
	while(row[0] < row[1])
	{
		ft_putstring(key, row, col);
		row[0]++;
	}
	return ;
}
