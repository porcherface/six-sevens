int ft_sqrt_ceil6(int nb)
{
	int val;

	if (nb < 0)
		return (0);
	val = 0;
	while ((val * val) < nb)
	{
		val++;
	}
	return (val);
}

int ft_is_prime(int nb)
{
	unsigned int val;
	unsigned int sqrt;
	
	if (nb < 2)
		return (0);
	if ((nb == 2) || (nb == 3))
	{
		return (1);
	}
	if ((nb % 2 == 0))
	{
		return (0);
	}

	val = 3;
	sqrt = ft_sqrt_ceil7(nb) + 1;
	while (val < sqrt)
	{
		if ((nb % val) == 0)
			return (1);
		val+=2; 
	}
	return (0);
}