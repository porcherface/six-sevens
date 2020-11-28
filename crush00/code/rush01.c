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

void ft_putchar_key(c)
{
	if(c == 'a' || c == 'e')
		c = '/';
	if(c == 'b' || c == 'd')
		c = '\\';
	if(c == 'c' || c == 'g')
		c = '*';
	ft_putchar(c); 
}


void ft_setchar(char *c, int *row, int *col)
{
	*c = ' ';
	if(row[0] == 0)
	{
		if(col[0] == 0)
			*c = 'a';
		else if(col[0] == col[1] - 1)
			*c = 'b';
		else
			*c = 'c';
	}
	else if(row[0] == row[1] - 1)
	{
		if(col[0] == 0)
			*c = 'd';
		else if(col[0] == col[1] - 1)
			*c = 'e';
		else
			*c = 'c';	
 	}
	else
	{
		if(col[0] == 0 || col[0] == col[1] - 1)
			*c = 'g';
		
	}
}

void ft_putstring(int key, int *row, int *col)
{
	char c;

	ft_setchar(&c, row, col);
	col[0]++;
	ft_putchar_key(c);
	if (col[0] < col[1])
	{
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
	int key;

	key = 0;
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
