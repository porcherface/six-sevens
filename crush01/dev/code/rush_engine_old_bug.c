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
		return (0);
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
		return (0);
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
		return (0);
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
		return (0);
	return (1);
}


int check_boxes(int size, int board[], int hero)
{
	/* all the rules to exclude a placement go here */ 
	/* we might wanna know who is our hero to speed up */
	int hero_row; 
	int hero_col;
	int it;

	hero_col = hero % size;
	hero_row = hero / size;
	it = 0;  
	while (it < size)
	{
		if ((board[hero_col + size * it] == board[hero]) && ((hero_col + size * it)!= hero) )
			return (0);
		if ((board[it + size * hero_row] == board[hero]) && ((it + size * hero_row)!= hero))
			return (0);
		it++;
	} 	
	return (1);
}

int choose_hero(int board[], int size)
{
	int hero;
	int it;

	it = 0;
	while (board[it] != 0 && it < size * size)
		it++;
	hero = it;
	return (hero);
}

int tree_search(int rules[], int size, int *board, int copy[], int placed )
{
	int hero;
	int it;
	int result;

	it = 0;
	if (placed == size*size)
		return (1);
	hero = choose_hero(copy, size);
	it =0;
	while (it < size)
	{
		copy[hero] = it + 1;
	        if (check_view(rules, size, board, hero))
	        {
			if (check_boxes(size, copy, hero))
			{	
				result = tree_search(rules, size, board, copy, placed + 1 );
				if(result == 1)
					return (1);
			}
		}
 		copy[hero] = 0;
		it++;
	}
	return (0);
}
