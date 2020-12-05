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
	/* if one of us finds a rule for a exact placement we 
	can hard-code it here  */

	/* two examples*/
	/* rule of 1 */
	/* if there is a 1 on rules, we can place a N close to it */

	/* rule of N */
	/* a rule of N fully places the row/column ascendingly*/
	
}

int check_rules(int rules[], int size, int board[])
{
	/* all the rules to exclude a placement go here */ 
}

int choose_hero(int board[])
{
	int hero;

	/* we search a spot with a 0 in the board */

	/* the more uniform is the search, the better it converges */

	/* we might use some sort of torus map to find an algho 
	   kinda uniform*/
}

int tree_search(int rules[], int size, int *board, int copy[], int placed)
{
	int hero;
	int it;
	int result;

	/* if we placed NxN boxes we won! */
	it = 0;
	result = 0;
	if (placed == size*size)
	{
		while(it < size*size)
		{
			board[it] = copy[it];
			return (1);
		}
	}

	/* we see the board and choose the hero*/
	hero = choose_hero(copy);

	/* for each possibility of our hero, we go deeper*/
	while (it < size)
	{
		copy[hero] = it + 1;
		if (check_rules(rules, size, copy))
		{
			result = tree_search(rules, size, board, board, placed + 1);
		}
	}
	/* if we found something the algorithm converged!*/
	return (result);
}

int rush_engine(int rules[], int size, int *board)
{
	int placed;
	int result;

	placed = 0;

	/* first we try to fill what we can
	   with some heuristics */
	placed += heuristic_start(rules[], size, *board);
	
	/* then we launch the search*/
	result = tree_search(rules, size, board, board, placed);

	/* hope for the best */
	return result;
}
