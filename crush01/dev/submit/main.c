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

#include <stdlib.h>

int	rush_engine(int rules[], int size, int *board);
int	print_output(int token, int board[], int size);
int	parse_input(int argc, char *argv, int *rules, int *board);

int	get_size(char *input)
{
	int i;
	int arg_count;
	int size;

	size = 0;
	i = 0;
	arg_count = 0;
	while (input[i] != '\0')
	{
		if (input[i] == ' ')
			size++;
		i++;
	}
	return (size + 1);
}

int	main(int argc, char **argv)
{
	int size;
	int token;
	int *rules;
	int *board;
	int flag = -1;
	token = -1;
	rules = 0x0;
	board = 0x0;
	size = 0;
	if (argc != 2)
		token = -2;
	else
		size = get_size(argv[1]);
	if ((size >= 4) && (size % 4) == 0)
	{
		flag++;
		board = (int*)malloc((size / 4) * (size / 4) * sizeof(int));
		rules = (int*)malloc(size * sizeof(int));
		token = parse_input(size, argv[1], rules, board);
		if (token > 0)
			token = rush_engine(rules, size / 4, board);
	}
	token = print_output(token, board, size / 4);
	if(flag)
	{
	free(board);
	free(rules);
	}
	return (token);
}
