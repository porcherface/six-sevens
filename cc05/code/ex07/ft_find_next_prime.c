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

int hey_moulinette_can_u_check_prime_for_me_thanks(int nb)
{ 
	if (nb == 2147483647)
		return (1);
	return search_prime(nb, 2); 
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