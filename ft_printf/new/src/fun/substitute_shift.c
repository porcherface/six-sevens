#include <stdarg.h>
#include "ft_repl.h"

char *substitute_shift(char *str, va_list args, int num)
{
	char	spc;
	char 	*dart;
	int		found;

	found = 0;
	dart = str;
	while(!found && *dart)
	{
		if(*dart == '%' && *(dart + 1) != '%' )
			found = 1;
		if(*dart == '%' && *(dart + 1) == '%' )
			dart++;	
		dart++;
	}
	if(!*dart)
		return (0x0);
	spc = *dart;
	if (spc == 's')
		str = replace_string(str, va_arg( args, char *));
	if (spc == 'd' || spc == 'o' || spc == 'x' || spc == 'X' || spc == 'i')
		str = replace_digit(str, va_arg(args, int), spc);		
	if (spc == 'u')
		replace_unsigned(str, va_arg(args, unsigned));
	if (spc == 'f')
		str = replace_float(str, va_arg(args, double));
	if (spc == 'p')
		str = replace_pointer(str, va_arg(args, unsigned long long));
	if (spc == 'c')
		replace_char(str, va_arg( args, int));
	
	return (str);
}