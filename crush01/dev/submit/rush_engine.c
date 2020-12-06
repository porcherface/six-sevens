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

int	check_view_pro(int rule, int *s, int board[], int hero)
{
	int a[8];

	a[5] = 0;
	a[2] = 0;
	a[1] = ((s[4] % 2) == 0) * (s[3]) + ((s[4] % 2) == 1) * (-1);
	a[0] = ((s[4] % 2) == 0) * 0 + ((s[4] % 2) == 1) * (s[3] - 1);
	a[6] = hero % s[3];
	a[7] = hero / s[3];
	a[3] = 0;
	while (a[0] != a[1])
	{
		a[4] = (a[6] + s[3] * a[0]) * (s[4] < 2);
		a[4] += (a[0] + s[3] * a[7]) * (s[4] > 1);
		if (board[a[4]] > a[3])
		{
			a[3] = board[a[4]];
			a[2]++;
		}
		if (!board[a[4]])
			a[5] = (1);
		a[0] = (a[0] + 1) * ((s[4] % 2) == 0) + (a[0] - 1) * ((s[4] % 2) == 1);
	}
	if (a[2] != rule && !a[5])
		return (0);
	return (1);
}

int	check_boxes(int r[], int s, int b[], int hero)
{
	int h[6];
	int is_valid;

	h[3] = s;
	is_valid = 0;
	h[1] = hero % s;
	h[0] = hero / s;
	h[5] = 0;
	while (h[5] < s)
	{
		if ((b[h[1] + s * h[5]] == b[hero]) && ((h[1] + s * h[5]) != hero))
			return (0);
		if ((b[h[5] + s * h[0]] == b[hero]) && ((h[5] + s * h[0]) != hero))
			return (0);
		h[5]++;
	}
	h[4] = 0;
	is_valid = check_view_pro(r[hero % s + s * 0], h, b, hero);
	h[4] = 1;
	is_valid *= check_view_pro(r[hero % s + s * 1], h, b, hero);
	h[4] = 2;
	is_valid *= check_view_pro(r[hero / s + s * 2], h, b, hero);
	h[4] = 3;
	is_valid *= check_view_pro(r[hero / s + s * 3], h, b, hero);
	return (is_valid);
}

int	choose_hero(int board[], int size)
{
	int hero;
	int it;

	it = 0;
	while (board[it] != 0 && it < size * size)
		it++;
	hero = it;
	return (hero);
}

int	tree_search(int rules[], int size, int *board, int placed)
{
	int hero;
	int it;
	int result;

	it = 0;
	if (placed == size * size)
	{
		return (1);
	}
	hero = choose_hero(board, size);
	it = 0;
	while (it < size)
	{
		board[hero] = it + 1;
		if (check_boxes(rules, size, board, hero))
		{
			result = tree_search(rules, size, board, placed + 1);
			if (result == 1)
				return (1);
		}
		board[hero] = 0;
		it++;
	}
	return (0);
}
