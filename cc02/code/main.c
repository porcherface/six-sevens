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
#include <string.h>
#include <unistd.h>

char *ft_strcpy(char *dest, char *src);
char *ft_strncpy(char *dest, char *src, unsigned int n);
int ft_str_is_alpha(char *str);
int ft_str_is_numeric(char *str);
int ft_str_is_lowercase(char *str);
int ft_str_is_uppercase(char *str);
int ft_str_is_printable(char *str);
char* ft_strupcase(char *str);
char* ft_strlowcase(char *str);
char *ft_strcapitalize(char *str);
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
void ft_putstr_non_printable(char *str);
void *ft_print_memory(void *addr, unsigned int size);


int main()
{
	char dest[6];
	char dest2[6];
	char *destp;
	int it = 0;
  	int lc2;

  	/* ex0 and 1*/ 
	while(it < 6)
	{
		dest[it] = '0';
		dest2[it] = 'a';
		it++;
	}
	it = 0;
	destp = ft_strcpy(dest, "bella");
	lc2 = ft_strlcpy(dest, "bella",8);


	if(lc2 == 6)
	{
		write(1, "OK\n", 3);
	}
	else
	{
		write(1, "fail\n", 5);
	}
	lc2 = ft_strlcpy(dest, "bella",2);


	if(lc2 == 2)
	{
		write(1, "OK\n", 3);
	}
	else
	{
		write(1, "fail\n", 5);
		//return 0;
	}


	lc2 = ft_strlcpy(dest, "bella",5);
	if(lc2 == 4)
	{
		write(1, "OK\n", 3);
	}
	else
	{
		write(1, "fail\n", 5);
	}
	write(1, destp, 6);
	write(1,"\n02\n", 4);

	destp = ft_strncpy(dest2, dest, 3);


    /* ex 3&4 */
	if (ft_str_is_alpha("aeiou"))
	{
		write(1, "alpha", 5);
	}
	else
	{
		write(1, "fail", 4);	
	}

	if (ft_str_is_alpha("aei1ou"))
	{
		write(1, "alpha", 5);
	}
	else
	{
		write(1, "fail", 4);	
	}
	write(1,"\n03\n", 4);

	if (ft_str_is_numeric("11"))
	{
		write(1, "numer", 5);
	}
	else
	{
		write(1, "fail", 4);	
	}
	if (ft_str_is_numeric("1f1"))
	{
		write(1, "numer", 5);
	}
	else
	{
		write(1, "fail", 4);	
	}


	//yeeeeee

	if (ft_str_is_lowercase("yeyone"))
	{
		write(1, "lower", 5);
	}
	else
	{
		write(1, "fail", 4);	
	}
	if (ft_str_is_lowercase("yeyOne"))
	{
		write(1, "lower", 5);
	}
	else
	{
		write(1, "fail", 4);	
	}
	write(1,"\n05\n", 4);

	if (ft_str_is_uppercase("YEYONE"))
	{
		write(1, "upper", 5);
	}
	else
	{
		write(1, "fail", 4);	
	}
	if (ft_str_is_uppercase("YEY0NE"))
	{
		write(1, "lower", 5);
	}
	else
	{
		write(1, "fail", 4);	
	}

	write(1,"\n07\n", 4);


	char bastemmion[64]= "p0rco!meo\n42cod sio\nco 77co aio\n\0";
	char tabbon[128] = "a\tb ...>\0\0\0\0<...   52395 23jf£%99£=£KJFQ£D=)Q£=DI)||\\\n\n\n\en\e8\e\n\ee\e8\\ff\fff\fff\0xff\0";
	char cazzo[16 * 12] = "aaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaa\0\0\0\0aaaaaaaaaa\0aaaa\0aaaaaaaaaa\0aaaa\0aaaaaaaaaa\0aaaa\0aaaaaaaaaa\0aaaa\0aaaaaaaaaa\0aaaa\0aaaaaaaaaa\0aaaa\0aaaaaaa\0\0\0aaaaaa\0\0\0aaaa\0\0\0aaaaaa\0\0\0aaaa\0\0\0aaaaaa\0\0\0aa";		

	write(1, ft_strupcase(destp), 6);
	write(1, ft_strlowcase(destp), 6);
	write(1, ft_strcapitalize(bastemmion), 32); 
	ft_putstr_non_printable(bastemmion);
	ft_putstr_non_printable(tabbon);

	write(1,"\n12\n", 4);
	ft_print_memory(bastemmion, 2);
	ft_print_memory(tabbon,4);

	
	ft_print_memory(cazzo, 12);
}
