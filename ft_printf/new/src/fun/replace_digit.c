#include "ft_repl.h"

char	*replace_digit(char *fmt, int val, char spec)
{
	if (spec == 'd' || spec == 'i')
		return (replace_generic(fmt, ft_itoa_base(val, 10), "%d"));
	if (spec == 'x')
		return (replace_generic(fmt, ft_itoa_base(val, 16), "%x"));
	if (spec == 'X')
		return (replace_generic(fmt, ft_itoa_base2(val, 16, 1), "%X"));
	if (spec == 'o')
		return (replace_generic(fmt, ft_itoa_base(val, 8), "%o"));
	return (replace_generic(fmt, ft_itoa_base(val, 16), "%x"));

}