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

int	tree_search(int rules[], int size, int *board, int placed);

int	rule_of_1(int rules[], int s, int *board, int placed)
{
	int it;
	int rc[2];

	it = 0;
	while (it++ < s * 4)
	{
		if (rules[it] == 1)
		{
			if (it < s * 2)
			{
				rc[0] = it % s;
				rc[1] = (it < s) * 0 + (it >= s) * (s - 1);
			}
			else
			{
				rc[0] = (it < (3 * s)) * 0 + (it >= (s * 3)) * (s - 1);
				rc[1] = it % s;
			}
			if (!board[rc[0] + s * rc[1]])
				placed++;
			board[rc[0] + s * rc[1]] = s;
		}
	}
	return (placed);
}

int	rule_of_n(int placed)
{
	return (placed);
}

int	deterministic_start(int rules[], int size, int *board)
{
	int placed;

	placed = 0;
	placed += rule_of_1(rules, size, board, placed);
	palced += rule_of_n(placed);
	return (placed);
}

int	rush_engine(int rules[], int size, int *board)
{
	int placed;
	int result;

	placed = 0;
	result = 0;
	placed += deterministic_start(rules, size, board);
	result = tree_search(rules, size, board, placed);
	return (!result);
}
