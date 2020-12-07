int ft_is_prime(int nb)
{
	unsigned int val;

	if ((nb == 0) || ((nb * nb) == 1))
	{
		return (0);
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