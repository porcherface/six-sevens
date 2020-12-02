






void *ft_print_memory(void *addr, unsigned int size);

int main()
{	
	//char a[16] = "i bacini forever";
	char b[32] = "badcaccacafebabe\n1234567890acdé";
	//char *c;

	ft_print_memory(b, 2);
	return 0;
}