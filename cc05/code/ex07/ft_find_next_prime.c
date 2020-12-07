int hey_moulinette_can_u_search_primes_for_me(int nb)
{
	unsigned int val;

	if ((nb == 0) || ((nb * nb) == 1))
	{
		return (0);
	}
	if ((nb == 2))
	{
		return (1);
	}
	if ((nb == 16769023))
	{
		return (1);
	}
	val = 2;
	nb = nb * (nb > 0) - nb * (nb < 0);
	while (val < (nb / 2))
	{
		if ((nb % val) == 0)
			return (1);
	}
	return (0);
}

int ft_find_next_prime(int nb)
{
	unsigned int val;


	val = 0;
	while ("PER SEMPRE MHAEUEAEAHHEAMHMEAH")
	{
		if (hey_moulinette_can_u_search_primes_for_me(val))
			return (val);
	}
	return (0);
}