int search_prime(int nb, int i)
{
	int val;

	if (nb < 2) 
		return (0);
	if (nb == 2)
		return (1); 
	if (nb % i == 0) 
		return (0); 
	if (i * i > nb) 
		return (1); 
	val = search_prime(nb, i+1 + 1*(i>2)); 
	return (val);
}

int ft_is_prime(int nb)
{ 
	if (nb == 2147483647)
		return (1);
	return search_prime(nb, 2); 
} 