/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboldini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:15:34 by rboldini          #+#    #+#             */
/*   Updated: 2020/12/05 19:51:23 by rboldini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int my_atoi(const char *input) 
{
	int accumulator = 0;
	int curr_val = 0;
	//int sign = 1;
	int i;

	i = 0;
	if (input[0] == '+')
	i++;
	while (input[i] != 32) 
	{
	curr_val = (int)(input[i] - '0'); 
	if (curr_val > 9)
		accumulator = accumulator * 10 + curr_val;
	i++;
	}
	return (accumulator);
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
			if (input[a++] == ' ')
				return (-2);
	}
	if (input[a--] == ' ')
		return (-2);
}

int		ft_str_is_numeric(char *str)
{
	char *p_str;

	p_str = str;
	while(*p_str != '\0')
	{
		if (*p_str < '0' || *p_str > '9')
			if (*p_str != ' ')
				return (-2);
		p_str++;
	}
	return (0);
}

int parse_input(int argc, char **argv, int *rules, int *board)
{

	if (argc != 2)
	{
		return (-1);
	}

	char *str = argv[1];
	if(!ft_str_is_numeric(str))
	{
		return (-1);
	}

	// get size()

	if (size > 0)
	{
		board = (int*)malloc(size * size * sizeof(int));
		rules = (int*)malloc(4 * size * sizeof(int));
		// fill board with zeros
		// fill rules with str elements
	}
	else
	{
		return (-4);
	}
	if (board != 0x0 && rules != 0x0)
	{
		return (size);
	}
	return (-4);

}