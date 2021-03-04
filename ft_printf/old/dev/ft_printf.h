
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "lib/libft.h"
#include <stdarg.h>

int		count_specifiers(const char *s);
char 	*substitute_shift(char *dart, char *str, va_list list, int num);


#endif