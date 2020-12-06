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

int rule_of_1(int rules[], int size, int *board, int placed)
{
	int it;
	int rc[2];

	it = 0;
	while (it < size * 4)
	{
		if (rules[it] == 1)
		{
			if( it < size * 2)
			{
				rc[0] = it % size;
				rc[1] = (it < size) * 0 + (it >= size) * (size -1);
			}
			else
			{
				rc[0] = (it < (3 * size)) * 0 + (it >= (size * 3)) * (size -1);
				rc[1] = it % size;
			}
			if (!board[rc[0] + size * rc[1]])
			{
				board[rc[0] + size * rc[1]] = size;
				placed++;
			}
		}
		it++;
	}
	return (placed);
}

int deterministic_start(int rules[], int size, int *board)
{
	int placed;

	placed = 0;
	placed += rule_of_1(rules, size, board, placed);
	return (placed);
}

int rush_engine(int rules[], int size, int *board)
{
	int placed;
	int result;

	placed = 0; 
	result = 0;
	placed += deterministic_start(rules, size, board);
	result = tree_search(rules, size, board, placed);
	return (!result);
}
