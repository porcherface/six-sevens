
#include <unistd.h>

//void ft_putnbr(int nb);
 
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

int ft_iterative_factorial(int nb);
int ft_recursive_factorial(int nb);
int ft_iterative_power(int nb, int power);
int ft_recursive_power(int nb, int power);
int ft_fibonacci(int index);

int ft_sqrt(int nb);
int ft_is_prime(int nb);
/*
int ft_find_next_prime(int nb);
int ft_ten_queens_puzzle(void);
*/
int main()
{
	ft_putstr("using ft_putstr for stdout\n");
	ft_putstr("ft_iterative_factorial\n");
	
	if (0 == ft_iterative_factorial(-2147483648))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (1 == ft_iterative_factorial(0))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (1 == ft_iterative_factorial(1))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (479001600 == ft_iterative_factorial(12))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}

	ft_putstr("ft_recursive_factorial\n");
	
	if (0 == ft_recursive_factorial(-2147483648))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (1 == ft_recursive_factorial(0))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (1 == ft_recursive_factorial(1))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (479001600 == ft_recursive_factorial(12))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}

	ft_putstr("ft_iterative_power\n");
	if ((12 * 12 * 12) == ft_iterative_power(12, 3))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if ((1) == ft_iterative_power(0, 0))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if ((0) == ft_iterative_power(0, -2147483648))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if ((1) == ft_iterative_power(-2147483648, 0))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if ((1) == ft_iterative_power(1, -2147483648))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if ((1) == ft_iterative_power(1, 479001600))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	ft_putstr("ft_recursive_power\n");
	if ((12 * 12 * 12) == ft_recursive_power(12, 3))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if ((1) == ft_recursive_power(0, 0))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if ((0) == ft_recursive_power(0, -2147483648))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if ((1) == ft_recursive_power(-2147483648, 0))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if ((1) == ft_recursive_power(1, -2147483648))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if ((1) == ft_recursive_power(1, 479001600))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	ft_putstr("ft_fibonacci\n");
	if (0 == ft_fibonacci(0))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}

	if (-1 == ft_fibonacci(-2147483648))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (1 == ft_fibonacci(2))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}

	if (3 == ft_fibonacci(4))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (5 == ft_fibonacci(5))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (ft_fibonacci(15))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (ft_fibonacci(14))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	
	ft_putstr("ft_sqrt\n");
	if (6 == ft_sqrt(36))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (0 == ft_sqrt(0))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}

	if (1 == ft_sqrt(1))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (0 == ft_sqrt(-0x000aaaa))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}

	if (46340 == ft_sqrt(2147395600))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	ft_putstr("ft_is_prime\n");

	if (0 == ft_is_prime(0))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (0 == ft_is_prime(01))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (0 == ft_is_prime(-2))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (1 == ft_is_prime(13))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (1 == ft_is_prime(7477))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (1 == ft_is_prime(7880989))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (1 == ft_is_prime(78852797))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (1 == ft_is_prime(214750031))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if (1 == ft_is_prime(2047472689+0))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}

	if (0 == ft_is_prime(2047472689+1))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}	
	if (1 == ft_is_prime(2147483647))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	ft_putstr("ft_find_next_prime\n");


	int ft_find_next_prime(int nb);
int ft_ten_queens_puzzle(void);

*/


}