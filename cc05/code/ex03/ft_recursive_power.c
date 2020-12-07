int ft_recursive_power(int nb, int power)
{	
	if (power == 0 && nb == 0)
		return (1);
	if (nb == 0)
		return (0);
	if (power == 0) 
		return (1);
	if (nb == 1) 
		return (1);
	nb *= ft_recursive_power(nb, power - 1);
	return (nb);
}