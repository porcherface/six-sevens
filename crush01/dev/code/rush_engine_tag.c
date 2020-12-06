/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 14:02:03 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/05 14:04:28 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check_view(int rules[], int size, int board[], int hero)
{
	int counter = 0;
	int max = 0;
	int it = 0;
	int flag = 0;	
	int rulvalues[4];
	int hero_row; 
	int hero_col;
 
	hero_col = hero % size;
	hero_row = hero / size;

	rulvalues[0] = rules[hero % size + size * 0];
	rulvalues[1] = rules[hero % size + size * 1];
	rulvalues[2] = rules[hero / size + size * 2];
	rulvalues[3] = rules[hero / size + size * 3];
	while (it < size)
	{
		if (board[hero_col + size * it] > max)
		{
			max = board[hero_col + size * it];
			counter++;
		}
		if (!board[hero_col + size * it])
			flag = (1);
		it++;
	}
	if(counter != rulvalues[0] && !flag)
	{
		write(1, "notplace0\n", 10);
		return (0);
	}
	counter = 0;
	max = 0;
	it = size - 1;
	flag = 0;
	while (it >= 0)
	{
		if (board[hero_col + size * it] > max)
		{
			max = board[hero_col + size * it];
			counter++;
		}
		if (!board[hero_col + size * it])
			flag = (1);
		
		it--;
	}
	if(counter != rulvalues[1] && !flag)
	{
		write(1, "notplace1\n", 10);
		return (0);
	}
	counter = 0;
	max = 0;
	it = 0;
	flag = 0;
	while (it < size)
	{
		if (board[it + size * hero_row] > max)
		{
			max = board[it + size * hero_row];
			counter++;
		}

		if (!board[it + size * hero_row])
			flag=  (1);
		
		it++;
	}
	if(counter != rulvalues[2] && !flag)
	{
		write(1, "notplace2\n", 10);
		return (0);
	}
	counter = 0;
	max = 0;
	it = size - 1;
	flag = 0;
	while (it >= 0)
	{
		if (board[it + size * hero_row] > max)
		{
			max = board[it + size * hero_row];
			counter++;
		}
 
		if (!board[it + size * hero_row])
			flag=  (1);
		it--;
	}
	if(counter != rulvalues[3] && !flag)
	{
		write(1, "notplace3\n", 10);
		return (0);
	}

	return (1);

}

int check_view_pro(int rulvalue, int size, int board[], int hero, int flag)
{
	int hero_col;
	int hero_row;
	int checked;
	int it;
	int limit;
	int max;
	int counter; 
	int failed = 0;

	counter = 0;
	limit = ((flag % 2) == 0) * (size) + ((flag % 2)==1) * (-1);
	it =    ((flag % 2) == 0) * 0      + ((flag % 2)==1) * (size - 1);

	hero_col = hero % size;
	hero_row = hero / size;

	char c;
	/*c = it + '0';
	write(1, &c, 1);
	c = limit + '0';
	write(1, &c, 1);
	*/
	max = 0;
	while ( it != limit)
	{
		checked = (hero_col + size * it) * (flag < 2);
		checked += (it + size * hero_row) * (flag > 1);  
		c = it + '0';
		//write(1, &c, 1);
		if (board[checked] > max)
		{
			max = board[checked];
			counter++;
		}
		if (!board[checked])
			failed = (1);
		it = (it + 1)*((flag % 2) == 0) + (it - 1)*((flag % 2) == 1);
	}
	if(counter != rulvalue && !failed)
		return (0);
	return(1);
}


int check_boxes(int rules[], int size, int board[], int hero)
{
	/* all the rules to exclude a placement go here */ 
	/* we might wanna know who is our hero to speed up */
	int hero_row; 
	int hero_col;
	int it;
	int is_valid;

	is_valid = 0;
	hero_col = hero % size;
	hero_row = hero / size;
	it = 0;  
	while (it < size)
	{
		if ((board[hero_col + size * it] == board[hero]) && ((hero_col + size * it)!= hero))
			return (0);
		if ((board[it + size * hero_row] == board[hero]) && ((it + size * hero_row)!= hero))
			return (0);
		it++;
	}
	is_valid = check_view_pro(rules[hero % size + size * 0], size, board, hero, 0);
	is_valid *= check_view_pro(rules[hero % size + size * 1], size, board, hero, 1);
	is_valid *= check_view_pro(rules[hero / size + size * 2], size, board, hero, 2);	
	is_valid *= check_view_pro(rules[hero / size + size * 3], size, board, hero, 3);
	//is_valid = check_view(rules, size, board, hero);
	return (is_valid);
}

int choose_hero(int board[], int size)
{
	int hero;
	int it;

	/* we search a spot with a 0 in the board */
	it = 0;
	while (board[it] != 0 && it < size * size)
		it++;

	hero = it;
	/* the more uniform is the search, the better it converges */
	char c = hero + '0';
	write(1, "heropos:", 8);
	write(1, &c, 1);
	write(1, "\n", 1);
	return (hero);
	/* we might use some sort of torus map to find an algho 
	   kinda uniform*/
}

int tree_search(int rules[], int size, int *board, int placed )
{
	int hero;
	int it;
	int result;
	char c;
	/* if we placed NxN boxes we won! */
	it = 0;
	//result = placed;
	if (placed == size*size)
	{	write(1, "WIN\n", 4);
		return (1);
	}
	
	while (it < size*size)
	{
		c = board[it] + '0';
		write(1, &c, 1);
			
		if (it % size == size - 1)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		it++;
	}
	/* we see the board and choose the hero*/
	hero = choose_hero(board, size);
	it =0;
	/* for each possibility of our hero, we go deeper*/
	while (it < size)
	{
		board[hero] = it + 1;
		if (check_boxes(rules, size, board, hero))
		{	
			result = tree_search(rules, size, board, placed + 1 );
			if(result == 1)
				return (1);
		}
 		board[hero] = 0;
		it++;
	}
	return (0);
}
