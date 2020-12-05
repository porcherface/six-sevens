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
	/* if one of us finds a rule for a exact placement we 
	can hard-code it here  */

	/* two examples*/
	/* rule of 1 */
	/* if there is a 1 on rules, we can place a N close to it */

	/* rule of N */
	/* a rule of N fully places the row/column ascendingly*/
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
			/* rule is on row */
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
				write(1, "placed\n", 7);
			}
		}
		it++;
	}
	return (placed);
}

int check_rules(/*int rules[], */int size, int board[], int hero)
{
	/* all the rules to exclude a placement go here */ 
	/* we might wanna know who is our hero to speed up */
	int hero_row; 
	int hero_col;
	int it;

	hero_col = hero % size;
	hero_row = hero / size;

	char c = hero_row + '0'; 
	write(1, "row:",4); write(1, &c, 1);  write(1, "\n", 1);
	c = hero_col + '0';
	write(1, "col:",4); write(1, &c, 1);  write(1, "\n", 1);

	it = 0;
  	while (it < 9)
	{
		c = board[it] + '0';
		write(1, &c, 1);
			
		if (it % 3 == 2)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		it++;
	}

	/* check on board */
	it = 0;  
 
	while (it < size)
	{
		if ((board[hero_col + size * it] == board[hero]) && ((hero_col + size * it)!= hero) )
		{
			write(1, "notplaceC\n", 10);
			return (0);
		}
		if ((board[it + size * hero_row] == board[hero]) && ((it + size * hero_row)!= hero))
		{
			write(1, "notplaceR\n", 10);
			return (0);
 		}
		it++;
	}

	/* check on rules */

	write(1, "canplace\n", 9);

	return (1);
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

int tree_search(int rules[], int size, int *board, int copy[], int placed )
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
	/* we see the board and choose the hero*/
	hero = choose_hero(copy, size);
 	while (it < 9)
	{
		c = copy[it] + '0';
		write(1, &c, 1);
		if (it % 3 == 2)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		it++;
	}
	it =0;
	/* for each possibility of our hero, we go deeper*/
	while (it < size)
	{
		copy[hero] = it + 1;
		write(1, "heroval:" ,8);
		c = copy[hero] +'0';
		write(1, &c, 1);
	    write(1, "\n", 1);

		if (check_rules(/*rules,*/ size, copy, hero))
		{	
			result = tree_search(rules, size, board, copy, placed + 1 );
			if(result == 1)
			{
				return (1);
			}
		}
		it++;
	}
 


	/* if we found something the algorithm converged!*/
	return (0);
}

int rush_engine(int rules[], int size, int *board)
{
	int placed;
	int result;

	placed = 0; 
	result = 0;
	/* first we try to fill what we can
	   with some heuristics */
	placed += heuristic_start(rules, size, board);
	
	/* then we launch the search*/
	result = tree_search(rules, size, board, board, placed);
 
	/* hope for the best */
	return result;
}
