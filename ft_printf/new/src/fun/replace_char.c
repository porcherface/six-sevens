
#include "ft_repl.h"

char	*replace_char(char *fmt, int val)
{
	
	return (replace_generic(fmt, ft_itoa(val), "%d"));
}