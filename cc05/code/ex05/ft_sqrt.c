int ft_sqrt(int nb)
{
	int val;

	val = 0;
	while (val * val < nb)
	{
		val++;
	}
	if (val == nb)
		return (val);
	return (0);
}