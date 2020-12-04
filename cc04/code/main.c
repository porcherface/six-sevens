
#include <unistd.h>
int  ft_strlen(char *str);
int  ft_atoi(char *str);
void ft_putnbr(int nb);
void ft_putnbr_base(int nbr, char *base);
void ft_putstr(char *str);
//int ft_atoi_base(char *str, char *base);

int main()
{
	ft_putstr("using ft_putstr for stdout\n");
	ft_putstr("ft_strlen\n");
	if (5 == ft_strlen("bella"))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (5 == ft_strlen("bella\0aaaaaaaaaa"))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (6 == ft_strlen("bella\n\0aaaaaaaaaa"))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (0 == ft_strlen("\0bella\n\0aaaaaaaaaa"))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	ft_putstr("ft_atoi\n");

	/*ft_putnbr(666);
	write(1, "\n", 1);
	ft_putnbr(ft_atoi("666"));
	write(1, "\n", 1);
	*/
	if (42 == ft_atoi("42"))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (-42 == ft_atoi("---42"))
	{
		ft_putstr("  [ OK ]\n");
	}
	if (-42 == ft_atoi("---++++++++++++++++++42!42"))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	
	}
	if (2147483647 == ft_atoi("2147483647"))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}

	if (0 == ft_atoi("--+-       a2147483648aaaaaa4446s"))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (0 == ft_atoi("--+-00000000000000000000000000000000000000000"))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (-1 == ft_atoi("--+-00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (-2147483648 == ft_atoi("--+-2147483648"))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (-2147483648 == ft_atoi("--+-       2147483648aaaaaa4446s"))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (-2147483648 == ft_atoi("--+-   \n\t 2147483648aaaaaa4446s"))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	ft_putstr("ft_putnbr\n");
	write(1, "  ", 2);
 	ft_putnbr(666);
 	write(1, "\n  ", 3);
 	ft_putnbr(-2147483648);
 	write(1, "\n", 1);

	ft_putstr("ft_putnbr_base\n  ");
 	ft_putnbr_base(666, "0123456789");
 	write(1, "\n  ", 3);
 	ft_putnbr_base(1234567890, "qwertyuiop");
 	write(1, "\n  ", 3);
 	ft_putnbr_base(1234567890, "a");
 	write(1, "\n  ", 3);
  	ft_putnbr_base(1234567890, "abcdefa");
 	write(1, "\n  ", 3);
  	ft_putnbr_base(1234567890, "abcdef-");
 	write(1, "\n  ", 3);
 	ft_putnbr_base(-7, "01");
 	write(1, "\n  ", 3);
 	ft_putnbr_base(2147483647, "0123456789");
	write(1, "\n  ", 3);
 	ft_putnbr_base(-2147483648, "0123456789");
	write(1, "\n  ", 3);
 	ft_putnbr_base(65535, "0123456789abcdef");
	

	write(1, "\n", 1);

}