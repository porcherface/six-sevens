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

int	rule_of_1(int rules[], int s[], int *board, int placed)
{
	int rc[2];

	while (s[1] < s[0] * 4)
	{
		if (rules[s[1]] == 1)
		{
			if (s[1] < (s[0] * 2))
			{
				rc[0] = s[1] % s[0];
				rc[1] = (s[1] < s[0]) * 0 + (s[1] >= s[0]) * (s[0] - 1);
			}
			else
			{
				rc[0] = (s[1] < (3 * s[0])) * 0;
				rc[0] += (s[1] >= (s[0] * 3)) * (s[0] - 1);
				rc[1] = s[1] % s[0];
			}
			if (!board[rc[0] + s[0] * rc[1]])
				placed++;
			board[rc[0] + s[0] * rc[1]] = s[0];
		}
		s[1]++;
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
	int itsize[2];

	itsize[0] = 0;
	itsize[1] = size;
	placed = 0;
	placed += rule_of_1(rules, itsize, board, placed);
	placed += rule_of_n(placed);
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
