/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:18:41 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/05 14:36:31 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parse_input(int argc, char **argv, int *rules);
int	rush_engine(int rules[], int size, int *board);
int	print_output(int token, int board[], int size);

int	main(int argc, char **argv)
{
	int size;
	int token;
	int *rules;
	int *board;

	size = 0;
	token = 0;
	rules = 0x0;
	board = 0x0;
	token = parse_input(argc, argv, rules);
	if (token > 0)
	{
		size = token;
		token = rush_engine(rules, size, board);
	}
	token = print_output(token, board, size);
	free(board);
	free(rules);
	return (token);
}
