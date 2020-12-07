/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:35:19 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/01 14:35:28 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int ft_strcmp(char *s1, char *s2);
int ft_strncmp(char *s1, char *s2, unsigned int n);
char *ft_strcat(char *dest, char *src);
char *ft_strncat(char *dest, char *src, unsigned int nb);
char *ft_strstr(char *str, char *to_find);
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int main()
{
	write(1, "ft_strcmp\n",10);
	if (0 == ft_strcmp("bella", "bella\0"))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (ft_strcmp("bello", "bella\0") > 0)
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (ft_strcmp("balla", "bello\0") < 0)
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
 	if (ft_strcmp("ballaaaaaaaaa", "ballaaaaaaaaa\0eeeeeeee") == 0)
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	write(1, "ft_strncmp \n",12);

	if (!ft_strncmp("bello", "bella\0",4))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (ft_strncmp("bello", "bella\0",5) > 0)
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (ft_strncmp("balla", "bello\0",7) < 0)
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
 	if (ft_strncmp("ballaaaaaaaaa", "ballaaaaaaaaa\0eeeeeeee",2222222222) == 0)
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (ft_strncmp("balla", "ball\0",4) == 0)
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (ft_strncmp("balla", "ball\0",5) > 0)
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	char catty[32];
	char app[5];
	int it = 0;
	while(it < 8)
	{
		app[it % 4] = 'b';
		catty[it] = 'a';
		it++;
	}
	catty[it] = '\0';
	app[4] = '\0';
	write(1, "ft_strcat \n ",11);
	if (!ft_strcmp(ft_strcat(catty, app),"aaaaaaaabbbb"))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (!ft_strcmp(ft_strcat(catty, app),"aaaaaaaabbbbbbbb"))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	it = 0;
	while(it < 8)
	{
		app[it % 4] = 'b';
		catty[it] = 'a';
		it++;
	}
	write(1, "ft_strncat \n ",12);
	if (!ft_strncmp(ft_strncat(catty, app,3),"aaaaaaaabbb", 11))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (!ft_strncmp(ft_strncat(catty, app,1),"aaaaaaaabbbb", 11))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	write(1, "ft_strstr \n ",11);		
	if (!ft_strcmp(ft_strstr("badcacca", "cca"), "cca"))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}		
	if (!ft_strncmp(ft_strstr("badcaccacafebabe", "accacafebabe"), "accaca",6))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (!ft_strcmp(ft_strstr("badcaccacafebabe", "accacafebabe"), "accacafebabe"))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	it = 0;
	while(it < 8)
	{
		app[it % 4] = 'b';
		catty[it] = 'a';
		it++;
	}
	catty[it] = '\0';
	app[4] = '\0';
	write(1, "ft_strlcat \n ",12);		
		
	if (8 == ft_strlcat(catty, app, 2))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (0 == ft_strncmp(catty,"aaaaaaaab",9))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}


	it = 0;
	while(it < 8)
	{
		app[it % 4] = 'b';
		catty[it] = 'a';
		it++;
	}
	catty[it] = '\0';
	app[4] = '\0';
	if (12 == ft_strlcat(catty, app,12521))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (ft_strcmp(catty,"aaaaaaaabbbb") == 0)
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (16 == ft_strlcat(catty, "ccc?\0ddd",12521))
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}
	if (ft_strcmp(catty,"aaaaaaaabbbbccc?") == 0)
	{
		write(1, "  [ OK ]\n",9);
	}
	else
	{
		write(1, "  [FAIL]\n",9);	
	}


 



























}