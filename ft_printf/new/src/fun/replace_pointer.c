
#include "ft_repl.h"

char	*replace_pointer(char *fmt, unsigned long long val)
{
	fmt = ft_strreplone(fmt, "%p", "0x%p");
	return replace_generic(fmt, ft_itoa_base_long(val, 16), "%p");
}