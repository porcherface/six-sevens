
#include "ft_repl.h"

char	*replace_float(char *fmt, double val)
{
	return (replace_generic(fmt, ft_dtoa(val, 6), "%f"));
}