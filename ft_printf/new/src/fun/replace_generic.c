
#include "ft_repl.h"

char	*replace_generic(char *fmt, char *val, char *spec)
{
	fmt = ft_strreplone(fmt, spec, val);	
	return (fmt);
}