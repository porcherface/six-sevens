
#include "get_next_line.h"

unsigned int		ft_strlen(const char *str)
{
	unsigned int	it;

	it = 0;
	while (str[it])
		it++;
	return (it);
}

char	*ft_strdup(const char *src)
{
	int		size;
	char	*out;
	int		it;

	size = ft_strlen(src);
	it = 0;
	out = (0x0);
	if ((size + 1) > 0)
		out = (char *)malloc((size + 1) * sizeof(char));
	if (out == 0x0)
		return (0x0);
	while (it < size)
	{
		out[it] = src[it];
		it++;
	}
	out[size] = src[size];
	return (out);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (char *)s;
		s++;
	}
	if (!c)
		return (char *)s;
	return (0x0);
}

void    ft_strdel(char **as)
{
    if (as != NULL)
    {
        free(*as);
        *as = NULL;
    }
}
