/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main   .c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 17:43:24 by amazzei           #+#    #+#             */
/*   Updated: 2020/11/29 17:45:04 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);
int		ft_strlen(char *str);
void	ft_rev_int_tab(int *tab, int size);
void	ft_sort_int_tab(int *tab, int size);
void	ft_ft(int *nbr);
void	ft_ultimate_ft(int *********nbr);
void	ft_swap(int *a, int *b);
void	ft_div_mod(int a, int b, int *div, int *mod);
void	ft_ultimate_div_mod(int *a, int *b);

void	ft_putnbr(int nb);

int main()
{


	int str[10];
	int it;
	int yo;
	int d;
	int m;

	it = 0;
	yo = 5;
	while( it < 10)
	{
	 	str[it] = it;
	 	it++;
 		str[5] = 42;
	}

	ft_ft(&it);
	ft_putnbr(it);
	it = 0;
	ft_putnbr(it);
	
	ft_putstr("bella");
	ft_putnbr( ft_strlen("bella zio") );

	ft_putnbr(it);
	ft_putnbr(yo);
	ft_swap(&it, &yo);
	ft_putnbr(it);
	ft_putnbr(yo);
	ft_div_mod(42, 5, &d, &m);
	ft_putstr("divmod");
	ft_putnbr(d);
	ft_putnbr(m);
	ft_rev_int_tab(str,10);
	it=0;
	while(it<10)
	{
		ft_putnbr(str[it]);
		it++;
	}

	ft_rev_int_tab(str,7);
	it=0;
	while(it<10)
	{
		ft_putnbr(str[it]);
		it++;
	}
	ft_sort_int_tab(str,10);
	it=0;
	while(it<10)
	{
		ft_putnbr(str[it]);
		it++;
	}
}