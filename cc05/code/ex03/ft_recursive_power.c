int ft_recursive_power(int nb, int power)
{	
	unsigned int val;

	if (power == 0)
		return (1);
	val *= ft_recursive_power(val, power - 1);
	return (val);
}