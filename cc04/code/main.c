
#include <unistd.h>
int ft_strlen(char *str);
int ft_atoi(char *str);

int main()
{
	write(1, "ft_strlen\n",10);
	if (5 == ft_strlen("bella"))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (5 == ft_strlen("bella\0aaaaaaaaaa"))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (6 == ft_strlen("bella\n\0aaaaaaaaaa"))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
		write(1, " ft_putstr\n",10);
	if (5 == ft_strlen("bella"))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (5 == ft_strlen("bella\0aaaaaaaaaa"))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (6 == ft_strlen("bella\n\0aaaaaaaaaa"))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}


	write(1, "ft_atoi\n",8);
	if (42 == ft_atoi("42"))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (-42 == ft_atoi("---42"))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (2147483647 == ft_atoi("2147483647"))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (-2147483647 == ft_atoi("--+-       2147483647"))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}

}