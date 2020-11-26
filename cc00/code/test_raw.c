#include <unistd.h>

void ft_putchar(const char c);
void ft_print_alphabet(void);
void ft_print_reverse_alphabet(void);
void ft_print_numbers(void);
void ft_is_negative(int n);
void ft_print_comb(void);
void ft_print_comb2(void);
void ft_putnbr(int nb);
void ft_print_combn(int nb);

int main(void)
{ 
	ft_putchar('c');
	ft_print_alphabet( );
	t_print_reverse_alphabet( );
	void ft_print_numbers( );
	ft_is_negative(int n);
	ft_print_comb(void);
	ft_print_comb2();
    ft_putnbr( 65535);
	ft_putnbr( 65535);
	ft_print_combn(int nb);

	return;
}

void ft_putchar(const char c)
{
	write(1, &c, 1);
	return;
}

void ft_print_alphabet(void)
{
	write(1, "abcdefghijklmnopqrstuvwxyz", 26);
	return;	
}

void ft_print_reverse_alphabet(void)
{
	write(1, "zyxwvutsrqponmlkjihgfedcba", 26);
	return;
}

void ft_print_numbers(void)
{
	write(1, "0123456789", 10);
	return;
}

void ft_is_negative(int number)
{
	if (number < 0)
	{
		write(1, "N", 1);
	}
	else
	{
		write(1, "P", 1);
	}
	return;
}

void ft_print_comb(void)
{
	int first;
	int second;
	int third;

	first = 0;
	second = 1;
	third = 2;
	while (first < 8)
	{
		while (second < 9)
		{
			while (third < 10)
			{
				write(1, '0' + (char) first, 1);
				write(1, '0' + (char) second, 1);
				write(1, '0' + (char) third, 1);
				write(1, ', ', 2);
				third++;
			}
			second++;
		}
		first++
	}
	return;
}

void ft_print_comb2(void)
{
	int first_count;
	int second_count;
	int first_digit_d;
	int first_digit_u;
	int second_digit_d;
	int second_digit_u;

	first_count = 0;
	second_count = 1;
	while (first < 99)
	{
		while (second < 100)
		{
			first_digit_u = first_count % 10;
			first_digit_d = (first_count - first_digit_u) / 10;
			first_digit_u = second_count % 10;
			first_digit_d = (second_count - second_count) / 10;
			write(1, '0' + (char) first_digit_d, 1);
			write(1, '0' + (char) first_digit_u, 1);
			write(1, ' ', 1);
			write(1, '0' + (char) first_digit_d, 1);
			write(1, '0' + (char) first_digit_u, 1);
			write(1, ', ', 2);
			second_count++;
		}
		first_count++
	}
	return;
}

/* array is 5 long cus we have 5 digits in 2^16 */
void ft_putnbr(int nb)
{
	int digits[5];
	bool sign;
	int it;

	it = 5;
	sign = ( nb < 0 );
	digit[4] = nb % 10 + '0';
	digit[3] = ( nb - digit[4] ) / 10 % 10  + '0';
	digit[2] = ( nb - digit[4] - 10 * digit[3] ) / 100 % 10  + '0';
	digit[1] = ( nb - digit[4] - 10 * digit[3] - 100 * digit[2] ) / 1000 % 10  + '0';
	digit[0] = ( nb - digit[4] - 10 * digit[3] - 100 * digit[2] - 1000 * digit[3] );
	digit[0] = digit[0] / 10000 % 10 + '0';
	if ( sign )
	{
		write(1, '-', 1);
	}
	while( it )
	{
		it--;
		write(1, digit[it], 1);
	}
}

/* here i guess i have to find something smart to succeed */
void ft_print_combn(int nb);
{
	return;
}