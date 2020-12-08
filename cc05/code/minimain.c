
#include <unistd.h>

void ft_putnbr(int nb);
 
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

int ft_ten_queens_puzzle(void);

int main()
{
 	
	ft_putstr("ft_ten_queens_puzzle\n");

	ft_ten_queens_puzzle();
	/*if (724 == ft_ten_queens_puzzle())
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}*/
	//ft_putnbr();

}