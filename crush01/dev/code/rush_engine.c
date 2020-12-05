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
	it = 0;
	while (it < size * 4)
	{
		if (rules[it] == size)
		{
			
		}

	}

	return (placed);
}
/*
int check_v
*/
int check_rules(int rules[], int size, int board[], int hero)
{
	int hero_row; 
	int hero_col;
	int it;
	int rulvalues[4];
	int counter = 0;
	int max = 0;
	int flag = 0;

	rulvalues[0] = rules[hero % size + size * 0];
	rulvalues[1] = rules[hero % size + size * 1];
	rulvalues[2] = rules[hero / size + size * 0];
	rulvalues[3] = rules[hero / size + size * 1];
	hero_col = hero % size;
	hero_row = hero / size;
	it = 0;  
	while (it < size)
	{
		if ((board[hero_col + size * it] == board[hero]) && ((hero_col + size * it)!= hero) )
		{
			return (0);
		}
		if ((board[it + size * hero_row] == board[hero]) && ((it + size * hero_row)!= hero))
		{
			return (0);
 		}
		it++;
	}
 	

	it = 0;
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
	int token;

	placed = 0; 
	token = 0;
	placed += heuristic_start(rules, size, board);
	token = tree_search(rules, size, board, board, placed);
	return !token;
}
