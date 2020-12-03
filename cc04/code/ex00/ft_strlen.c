

int ft_strlen(char *str)
{
	int it;

	it = 0;
	while (str[it] != '\0')
	{
		it++;
	}
	return (it);
}