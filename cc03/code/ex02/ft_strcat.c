char *ft_strcat(char *dest, char *src)
{
	int it1;
	int it2;

	it1 = 0;
	it2 = 0;
	while (dest[it1] != '\0')
		it1++;

	while(src[it2] != '\0')
	{
		dest[it1+it2] = src[it2];
		it2++;
	}
	return dest;
}
