unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int it1;
	unsigned int it2;

	it2 = 0;
	while (dest[it1] != '\0')
		it1++;

	while ((src[it2] != '\0' )&& (it2 < size - 1 ))
	{
		dest[it1 + it2] = src[it2];
		it2++;
	}
	dest[it1 + it2] = '\0';
	if (it2 == size - 1 )
	{
		return (it1 + it2+1);
	}
	return (it1 + it2);
}
