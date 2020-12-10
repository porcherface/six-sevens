
#include <unistd.h>

  
void	ft_putstr(char *str)
{
	unsigned int it;

	it = 0;
	while (str[it] != '\0')
	{
		write(1, &str[it], 1);
		it++;
	}
}

char *ft_strdup(char *src);

int main()
{
	ft_putstr("using ft_putstr for stdout\n");

	ft_putstr("ft_strdup\n");
	if ()
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	} 
}