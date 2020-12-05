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


int heuristic_start(int rules[], int size, int *board)
{
	int it;
	int row;
	int col;
	int placed;

	placed = 0;
	it = 0;
	while (it < size * 4)
	{
		if (rules[it] == 1)
		{
			if( it < size * 2)
			{
				row = it % size;
				col = (it < size) * 0 + (it >= size)*(size -1);
			}
			else
			{
				row = (it < (3 * size)) * 0 + (it >= (size * 3))*(size -1);
				col = it % size;
			}
			if (!board[row + size * col])
			{
				board[row + size * col] = size;
				placed++;
 			}
		}
		it++;
	}
	return (placed);
}

int check_rules(int rules[], int size, int board[], int hero)
{
	int hero_row; 
	int hero_col;
	int it;

	hero_col = hero % size;
	hero_row = hero / size;

	//int sumcol = 0;
	//int sumrow = 0;

	it = 0;
	while (it < size)
	{
		if ((board[hero_col + size * it] == board[hero]) && ((hero_col + size * it)!= hero))
 			return (0);
		if ((board[it + size * hero_row] == board[hero]) && ((it + size * hero_row)!= hero))
			return (0);
		it++;
	}
	
	int r1 = hero % size + size * 0;
	it = 0;
	int count = 0;
	int max = 0;
	while (it < size)
	{
		if (board[hero_col + size * it] > max)
		{
			max = board[hero_col + size * it];
			count++;
		} 
		it++;
	}
	if(count > rules[r1])
	{
		return (0);
	}
	int r2 = hero % size + size * 1;
	it = size-1;
	count = 0;
	while (it >=0)
	{
		if (board[hero_col + size * it] > max)
		{
			max = board[hero_col + size * it];
			count++;
		} 
		it--;
	}
	if(count > rules[r2])
	{
		return (0);
	}	

	int r3 = hero % size + size * 2;
	it = 0;
	count = 0;
	while (it < size)
	{
		if (board[it + size * hero_row] > max)
		{
			max = board[it + size * hero_row];
			count++;
		} 
		it++;
	}
	if(count > rules[r3])
	{
		return (0);
	}
	int r4 = hero % size + size * 3;
	it = size-1;
	count = 0;
	while (it >=0)
	{
		if (board[it + size * hero_row] > max)
		{
			max = board[it + size * hero_row];
			count++;
		} 
		it--;
	}
	if(count > rules[r4])
	{
		return (0);
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
	{
		return (1);
	}
	hero = choose_hero(copy, size);
	it =0;
	while (it < size)
	{
		copy[hero] = it + 1;
		if (check_rules(rules, size, copy, hero))
		{	
			result = tree_search(rules, size, board, copy, placed + 1 );
			if(result == 1)
			{
				return (1);
			}
		}
		it++;
	}
	return (0);
}

int rush_engine(int rules[], int size, int *board)
{
	int placed;
	int result;

	placed = 0; 
	result = 0;
	placed += heuristic_start(rules, size, board);
	result = tree_search(rules, size, board, board, placed);
	return result;
}
