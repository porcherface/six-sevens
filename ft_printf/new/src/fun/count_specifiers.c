#include <stdio.h>
#include "ft_repl.h"
/* parses a string to return va_count */

int		count_specifiers(const char *str)
{
	int		va_count;

    /* if string is fuffa */
    if (!str)
        return (-1);
    va_count = ft_chrcount(str, '%') - 2 * ft_strcount(str, "%%");
   
	return va_count;
}

