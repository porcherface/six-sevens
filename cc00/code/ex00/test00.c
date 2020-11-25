#include <unistd.h>
void ft_putchar(const char in_char);

int main(void)
{
	char test_char;
	char another_char;

	test_char = 'a';
	another_char = (char) 42;
	ft_putchar('c');
	return;
}

void ft_putchar(const char in_char)
{
	write(1, &in_char, 1);
}
