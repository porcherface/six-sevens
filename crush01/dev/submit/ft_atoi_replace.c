/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboldini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:15:34 by rboldini          #+#    #+#             */
/*   Updated: 2020/12/06 10:28:47 by rboldini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	check_space(char *input);
int	ft_str_is_numeric(char *str);
int get_size(char *input, int size);
void pop_rules(char *input, int *rules, int size, int i);
int my_atoi(const char *input, int i);
int parse_input(int argc, char *argv, int *rules, int *board);

int my_atoi(const char *input,int i)
{
	int accumulator;
	int curr_val;

	curr_val = 0;
	accumulator = 0;
	while (input[i] != ' ' && input[i] != '\0') 
	{
		write(1, "ato2_ok\n", 8);
		curr_val = (int)(input[i] - '0');
			printf("curr_val: %d\n", curr_val);
		if (input[i + 1] >= '0' && input[i + 1] <= '9' && input[i + 1] != '\0')
		{
			accumulator = accumulator * 10 + curr_val;
		}
		else if (input[i + 1] == ' ' || input[i + 1] == '\0')
		{
			accumulator = curr_val;
		}
		i++;
	}
	printf("accumulator: %d\n", accumulator);
	return (accumulator);
}

void pop_rules(char *input, int *rules, int size, int i)
{
	int i2;

	i2 = 0;
	if (input[i] == ' ')
		i++;
	while (input[i] != '\0')
	{
		if (input[i] >= '0' && input[i] <= '9' )
		{
			rules[i2] = my_atoi(input, i);
			i2++;
		//	if (i2 != (size - 1) && input[i] != ' ')
		//		i2++;
			write(1, "ato1_ok\n", 8);
		}
		i++;
	}
		write(1, "pop_ok\n", 7);
}

int get_size(char *input, int size)
{
	int i;
	int arg_count;
	
	i = 0;
	arg_count = 0;
	while (input[i] != '\0')
	{
		if (input[i] == ' ')
			size++;
		i++;
    }
    write(1, "check_sz_ok\n", 12);
    return (size + 1);
}

int	check_rules(int *rules, int size)
{
	int i;
	int maxv;
	i = 0;
	maxv = 0;
	while(i < size)
	{
		if (constraint[i] == 0)
			return (-2);
		if (constraint[i] > maxv)
			maxv = constraint[i];
		i++;
	}
		if (maxv != size)
		return (-2);
	else
		return (0);
}

int	check_space(char *input)
{
	int a;

	a = 0;
	if (input[a] == ' ')
		return (-2);
	while (input[a] != '\0')
	{
		if (input[a] == ' ')
		{	
			if (input[a + 1] == ' ')
				return (-2);
		}
		a++;
	}
	write(1, "check_sp_ok\n", 12);
	if (input[a - 1] == ' ')
		return (-2);
	return 1;
}

int		ft_str_is_numeric(char *str)
{
	char *p_str;

	p_str = str;
	while(*p_str != '\0')
	{
		if ((*p_str < '0' || *p_str > '9') && *p_str != ' ')
        {
          //  if (*p_str != ' ' && (*p_str <= '0' && *p_str >= '9'))
			//	return (-2);
            return (-2);
        }
		p_str++;
    }
    write(1, "ok_num\n", 7);
    return (check_space(str));
}

int parse_input(int argc, char *argv, int *rules, int *board)
{
	int size;
	int i;

	i = 0;
	size = 0;
	if (argc != 2)
	{
		return (-1);
	}

	char *str;
	str = argv;
	if(ft_str_is_numeric(str) != 1)
		return (ft_str_is_numeric(str));

	size = get_size(argv, size);
	if ((size % 4) != 0)
		return (-2);
	printf("size: %d\n", size);
    int k;
	if (size > 0)
	{
		board = (int*)malloc((size/4) * (size/4) * sizeof(int));
		rules = (int*)malloc(size * sizeof(int));
		// fill board with zeros
		while (i != (size - 1))
		{
			board[i] = 0;
			i++;
		}

		write(1, "check_fill_bd\n", 15);
		// fill rules with str elements
		i = 0;
		pop_rules(str, rules, size, i);
		k = 0;
		while (k < size)
		{	
			printf("%d", rules[k]);
			k++;
		}
	//	check_rules(rules, )
	}
	else
		return (-4);
	if (board != 0x0 && rules != 0x0)
		return (size);
	return (-4);

}

int main(int argc, char **argv)
{
	int *board;
	int *rules;

	parse_input(argc, argv[1], rules, board);
}