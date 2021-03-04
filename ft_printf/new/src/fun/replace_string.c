#include "ft_repl.h"

char	*replace_string(char *fmt, char *val)
{
	fmt = ft_strreplone(fmt, "%s", val);	
	return (fmt);
}