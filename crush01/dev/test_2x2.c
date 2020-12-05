int main()
{
	int size = 2;
	int rules[2*4];
	int *board = 0x0;
	int token;
	int it;
	if (size > 0)
		board = (int*)malloc(size*size*sizeof(int));
	it=0;
	while(it < size*size)
	{
		board[it] = 0;
		it++;
	}
	it=0;

	rules[0] = 4; /* col up */
	rules[1] = 3;
	rules[2] = 2;
	rules[3] = 1;
	rules[4] = 1; /* col down */
	rules[5] = 2;
	rules[6] = 2;
	rules[7] = 2;
	rules[8] = 4; /* row lleft */
	rules[9] = 3;
	rules[10] = 2;
	rules[11] = 1;
	rules[12] = 1; /* row right */
	rules[13] = 2;
	rules[14] = 2;
	rules[15] = 2;

	token = rush_engine(rules, size, board);
	char c;
	it = 0;
	write(1, "\n", 1);
	write(1, "\n", 1);


	it = 0;
	while (it < 16)
	{
		c = board[it] + '0';
		write(1, &c, 1);
			
		if (it % 4 == 3)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		it++;
	}


	return token;
}