/* test_raw.c */

#include <stdio.h>
#include "libft.h"
#include <ctype.h>
#include <stdlib.h> 
int test_isdigit(int c)
{
	printf("%d\t\t", c);
	if (isdigit(c) == ft_isdigit(c))
		printf("    [ OK ]\n");
	else
		printf("    [FAIL]\n");
	return 0;

}

int test_isalpha(int c)
{
	printf("%d\t\t", c);
	if (isalpha(c) == ft_isalpha(c))
		printf("    [ OK ]\n");
	else
		printf("    [FAIL]\n");
	return 0;

}

int test_isprint(int c)
{	
	printf("%d\t\t", c);
	if (isprint(c) == ft_isprint(c))
		printf("    [ OK ]\n");
	else
		printf("    [FAIL]\n");
	return 0;

}

int test_isalnum(int c)
{
	printf("%d\t\t", c);
	if (isalnum(c) == ft_isalnum(c))
		printf("    [ OK ]\n");
	else
		printf("    [FAIL]\n");
	return 0;

}

int test_isascii(int c)
{
	printf("%d\t\t", c);
	if (isascii(c) == ft_isascii(c))
		printf("    [ OK ]\n");
	else
		printf("    [FAIL]\n");
	return 0;

}

int check_split(char *s, char c)
{
	char **list;
	size_t it = 0;

	printf("splitting %s with %c\n", s, c);
	list = ft_split(s,c);
	while(list[it])
	{
		printf("%s\n", list[it]);
		it++;
	}
	return 0;
}

int main()
{
	printf("libft raw tester\n");
	int it = 0;

	int min = -2147483648;
	int max = 2147483647;

	printf("%d", min);
	printf("isdigit\n");
	for(it = -3; it < 0xffff; it = (it>0)*it*2 + (it<=0)*it+1)
		test_isdigit(it);
	ft_isdigit(min);
	ft_isdigit(max);
	printf("isalpha\n");
	for(it = -3; it < 0xffff; it = (it>0)*it*2 + (it<=0)*it+1)
		test_isalpha(it);

	printf("isprint\n");
	for(it = -3; it < 0xffff; it = (it>0)*it*2 + (it<=0)*it+1)
		test_isprint(it);

	printf("isalnum\n");
	for(it = -3; it < 0xffff; it = (it>0)*it*2 + (it<=0)*it+1)
		test_isalnum(it);

	printf("isascii\n");
	for(it = -3; it < 0xffff; it = (it>0)*it*2 + (it<=0)*it+1)
		test_isascii(it);

	printf("itoa\n");
	printf("%d=%s \n",0, ft_itoa(0));
	printf("%d=%s \n",1, ft_itoa(1));
	printf("%d=%s \n",-1, ft_itoa(-1));
	printf("%d=%s \n",10, ft_itoa(10));
	printf("%d=%s \n",112345, ft_itoa(112345));
	printf("%d=%s \n",min, ft_itoa(min));

	printf("%s\n", ft_strjoin("cane", "dio"));

	printf("ft-split\n");

	check_split("ciao,belli",',');
	check_split("ciao,cioa,aieg,a,,,aeg,aeaefaefeaef,,,",',');
	check_split(",,,,,ciao",',');
	check_split("",',');
	check_split("",' ');

	check_split(",,,,",',');
	check_split(",",',');	
	printf("ft-substr\n");
	printf("%s \n", ft_substr("diocane", 3, 4) );
	printf("%s \n", ft_substr("diocane", 3, 3) );
	printf("%s \n", ft_substr("diocane", 3, 9) );
	printf("%s \n", ft_substr("diocane", 33, 9) );

	printf("itoa base\n");
	printf("%d=%s \n",0, ft_itoa_base(0, 10));
	printf("%d=%s \n",1, ft_itoa_base(1, 10));
	printf("%d=%s \n",-1, ft_itoa_base(-1, 10));
	printf("%d=%s \n",10, ft_itoa_base(10, 10));
	printf("%d=%s (base2)\n",10, ft_itoa_base(10, 2));

	printf("%d=%s \n",112345, ft_itoa_base(112345, 10));
	printf("%d=%s \n",min, ft_itoa_base(min, 10));
	printf("%d=%s (base16)\n",min, ft_itoa_base(min, 16));
	printf("%d=%s (base16)\n",max, ft_itoa_base(max, 16));
	int power16 = 16*16*16*16;
	printf("%d=%s (base16)\n",power16, ft_itoa_base(power16, 16));


}