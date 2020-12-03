char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	int it1;
	unsigned int it2;

	it1 = 0;
	it2 = 0;
	while (dest[it1] != '\0')
		it1++;

	while ((src[it2] != '\0' )&& (it2 < nb ))
	{
		dest[it1 + it2] = src[it2];
		it2++;
	}
	dest[it1 + it2] = '\0';
	return dest;
}