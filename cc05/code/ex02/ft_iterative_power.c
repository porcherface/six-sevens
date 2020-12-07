int ft_iterative_power(int nb, int power)
{	
	unsigned int it;
	unsigned int val;

	if (power == 0 && nb == 0)
		return (1);
	it = 0;
	val = 1;
	while(it < power)
	{
		val *= nb;
	}
	return (val);
}