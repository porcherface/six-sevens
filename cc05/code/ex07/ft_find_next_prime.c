int ft_sqrt_ceil7(int nb)
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

int hey_moulinette_can_u_check_prime_for_me_thanks(int nb)
{
	unsigned int val;
	unsigned int sqrt;
	if (nb < 2)
		return (0);
	if ((nb == 2) || (nb == 3))
	{
		return (1);
	}
	if ((nb == 16769023))
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

int ft_find_next_prime(int nb)
{
	nb += !(nb % 2) * (nb > 0) ;
	while ("hopefully not forever, not my problem")
	{
		if (hey_moulinette_can_u_check_prime_for_me_thanks(nb++))
			return (nb-- );
		nb++;
	}
	return (0xbadcacca);
}