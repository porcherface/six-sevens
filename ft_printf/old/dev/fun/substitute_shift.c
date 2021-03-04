#include <stdarg.h>
#include "ft_repl.h"

char *substitute_shift(char *dart, char *str, va_list list, int num)
{
	char spec_val;

	// shift up to first specifier
	// we can condense these 4 into a single strchr('%')
	while((*dart != '%') && *dart)
	{
		dart++;
	}
	// string has ended and i didnt find the specifier...
	if(!*str)
		return (0x0);
	
	//specifier value is
	spec_val = *str;
	
	if (spec_val == 's')
		replace_string(str, va_arg( list, char *));
	if (spec_val == 'c')
	//	replace_char(str, va_arg( list, char));
		replace_char(str, va_arg( list, int));
	if (spec_val == 'd')
		replace_digit(str, va_arg(list,int));		
	if (spec_val == 'u')
		replace_unsigned(str, va_arg(list,unsigned));
	if (spec_val == 'p')
		replace_pointer(str, va_arg(list, void *));
	if (spec_val == 'f')
		replace_float(str, va_arg(list, double));
	if (spec_val == '%')
		replace_percent(str);
	
	return (str);

}