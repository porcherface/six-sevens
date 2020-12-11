
#ifndef STK_STR_H
#define STK_STR_H

struct s_stock_str *ft_strs_to_tab(int ac, char **av);


typedef struct s_stock_str
{
	int size;
	char *str;
	char *copy;
} t_stock_str;

#endif