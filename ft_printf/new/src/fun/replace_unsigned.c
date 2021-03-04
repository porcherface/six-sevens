#include "ft_repl.h"

char	*replace_unsigned(char *fmt, unsigned val)
{

	return (replace_generic(fmt, ft_itoa_base_long(val, 10), "%u"));
}