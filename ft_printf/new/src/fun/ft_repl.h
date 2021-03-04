#ifndef FT_REPL_H
# define FT_REPL_H

#include "../lib/libft.h"
#include <stdio.h>

char	*replace_char(char *fmt, int val);
char	*replace_string(char *fmt, char *val);
char	*replace_digit(char *fmt, int val, char spec);
char	*replace_pointer(char *fmt, unsigned long long val);
char	*replace_unsigned(char *fmt, unsigned val);
char	*replace_float(char *fmt, double val);
char	*replace_percent(char *fmt);
char	*replace_generic(char *fmt, char *val, char *spec);

#endif

