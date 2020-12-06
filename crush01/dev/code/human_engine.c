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

int tree_search(int rules[], int size, int *board, int placed);

int deterministic_start(int rules[], int size, int *board)
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

int rush_engine(int rules[], int size, int *board)
{
	int placed;
	int result;

	placed = 0; 
	result = 0;
	/* first we try to fill what we can
	   with some heuristics */
	placed += deterministic_start(rules, size, board);
	
	/* then we launch the search*/
	result = tree_search(rules, size, board, placed);
 
	/* hope for the best */
	return !result;
}
