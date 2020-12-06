int ft_iterative_factorial(int nb)
{	
	unsigned int it;
	unsigned int res;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	it = nb;
	res = 1;
	while(it > 0)
	{
		res = res * nb; 
		it--;
	}
	return (res);
}