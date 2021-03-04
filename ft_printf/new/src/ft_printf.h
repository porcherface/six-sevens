
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "lib/libft.h"
#include <stdio.h>
#include <stdarg.h>
#include "fun/ft_repl.h"

int		count_specifiers(const char *s);
char 	*substitute_shift(char *str, va_list list, int num);


#endif