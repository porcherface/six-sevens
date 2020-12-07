int ft_sqrt(int nb)
{
	int val;

	if (nb < 0)
		return (0);
	val = 0;
	while ((val * val) < nb)
	{
		val++;
	}
	if ((val * val) == nb)
		return (val);
	return (0);
}