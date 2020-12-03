int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int it = 0;

	it = 0;
	while (s1[it] != '\0' && s2[it] != '\0' && it < n)
	{
		if (s1[it] == s2[it])
			it++;
		else
		{
			if (s1[it] > s2[it])
				return (1);
			else
				return (-1);
		}	
	}
	return (0);
}