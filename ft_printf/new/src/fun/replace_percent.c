#include "ft_repl.h"

char	*replace_percent(char *fmt)
{
	fmt = ft_strreplone(fmt, "%%", "%");	
	return (fmt);	
}