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

int check_view_pro(int rulvalue, int s, int board[], int hero, int f)
{
	int hcr[2];
	int A[6];
	
	A[5] = 0;
	A[2] = 0;
	A[1] = ((f % 2) == 0) * (s) + ((f % 2)==1) * (-1);
	A[0] = ((f % 2) == 0) * 0 + ((f % 2)==1) * (s - 1);
	hcr[0] = hero % s;
	hcr[1] = hero / s;
	A[3] = 0;
	while ( A[0] != A[1])
	{
		A[4] = (hcr[0] + s * A[0]) * (f < 2) + (A[0] + s * hcr[1]) * (f > 1);
		if (board[A[4]] > A[3])
		{
			A[3] = board[A[4]];
			A[2]++;
		}
		if (!board[A[4]])
			A[5] = (1);
		A[0]  = (A[0] + 1)*((f % 2) == 0) + (A[0] - 1)*((f % 2) == 1);
	}
	if( A[2] != rulvalue && !A[5])
		return (0);
	return(1);
}

int check_boxes(int rules[], int s, int board[], int hero)
{
	int hr; 
	int hc;
	int it;
	int is_valid;

	is_valid = 0;
	hc = hero % s;
	hr = hero / s;
	it = 0;  
	while (it < s)
	{
		if ((board[hc + s * it] == board[hero]) && ((hc + s * it)!= hero))
			return (0);
		if ((board[it + s * hr] == board[hero]) && ((it + s * hr)!= hero))
			return (0);
		it++;
	}
	is_valid = check_view_pro(rules[hero % s + s * 0], s, board, hero, 0);
	is_valid *= check_view_pro(rules[hero % s + s * 1], s, board, hero, 1);
	is_valid *= check_view_pro(rules[hero / s + s * 2], s, board, hero, 2);	
	is_valid *= check_view_pro(rules[hero / s + s * 3], s, board, hero, 3);
	return (is_valid);
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

int tree_search(int rules[], int size, int *board, int placed )
{
	int hero;
	int it;
	int result;
	
	it = 0;
	if (placed == size*size)
	{
		return (1);
	}
	hero = choose_hero(board, size);
	it =0;
	while (it < size)
	{
		board[hero] = it + 1;
		if (check_boxes(rules, size, board, hero))
		{	
			result = tree_search(rules, size, board, placed + 1);
			if(result == 1)
				return (1);
		}
 		board[hero] = 0;
		it++;
	}
	return (0);
}
