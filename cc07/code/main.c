
#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int it;

	it = 0;
	while (s1[it] != '\0' && s2[it] != '\0')
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
	if (s1[it] > s2[it])
		return (1);
	if (s1[it] < s2[it])
		return (-1);
	return (0);
}

  
void	ft_putstr(char *str)
{
	unsigned int it;

	it = 0;
	while (str[it] != '\0')
	{
		write(1, &str[it], 1);
		it++;
	}
}

char *ft_strdup(char *src);
char	*ft_strjoin(int size, char **strs, char *sep);
char *ft_convert_base(char *nbr, char *base_from, char *base_to);

#include <string.h>
#include <stdlib.h>
int meh_assert(int a)
{	if (a)
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
}
int main()
{ 
	ft_putstr("using ft_putstr for stdout\n");

	char *in  = "ajejebrazorf\0";
	char *out = ft_strdup(in);

	ft_putstr("ft_strdup\n");
	if (!ft_strcmp(in, out))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	char *in  = "ajejebrazorf";
	char *out = ft_strdup(in);
	if (!strcmp(in, out))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}


	char *sep = " /,**";
	char **strs = (char **)malloc(3*sizeof(char*));
	char *b1 = "cane*a";
	char *b2 = "                                            \n\n   wombat";
	char *b3 = "b";



	strs[0] = b1;
	strs[1] = b2;
	strs[2] = b3;
	/* what could possibly go wrong*/
	ft_putstr(ft_strjoin(3, strs, sep));
	if(!strcmp(ft_convert_base("3=======D", "3=D","(Y)"), "(YYYYYYY)"))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if(!ft_convert_base("3========D", "3==D",":)"))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}

	if(!ft_convert_base("3========D", "3=D",":-)"))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}

	if(!ft_convert_base("3========D", "23","\""))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	if(!strcmp(ft_convert_base("      --------!=", "!=","?^"), "-?^"))
	{
		ft_putstr("  [ OK ]\n");
	}
	else
	{
		ft_putstr("  [FAIL]\n");	
	}
	return (0);
}