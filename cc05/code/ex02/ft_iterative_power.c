int ft_iterative_power(int nb, int power)
{	
	unsigned int it;
	unsigned int val;

	if (power == 0 && nb == 0)
		return (1);
	if (nb == 0)
		return (0);
	if (power == 0) 
		return (1);
	if (nb == 1) 
		return (1);
	
	it = 0;
	val = 1;
	while(it < (unsigned int)power)
	{
		val *= nb;
		it++;
	}
	return (val);
}