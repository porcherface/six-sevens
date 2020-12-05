
#include <stdlib.h>
#include <unistd.h>
int rush_engine(int rules[], int size, int *board);

int main()
{
	int size = 3;
	int rules[3*4];
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

	rules[0] = 2; /* col up */
	rules[1] = 2;
	rules[2] = 1;
	rules[3] = 2;
	rules[4] = 1; /* col down */
	rules[5] = 3;
	rules[6] = 3;
	rules[7] = 1;
	rules[8] = 2; /* row lleft */
	rules[9] = 1;
	rules[10] = 2;
	rules[11] = 2;/*
	rules[12] = 1; *//* row right */
	/*rules[13] = 2;
	rules[14] = 2;
	rules[15] = 2;*/
		char c;

	while (it < 12)
	{
		c = rules[it] + '0';
		write(1, &c, 1);
		if (it % 3 == 2)
			write(1, " ", 1);
		it++;
	}		 
	token = rush_engine(rules, size, board);
 	it = 0;
	write(1, "\n", 1);
	write(1, "\n", 1);


	it = 0;
	while (it < 9)
	{
		c = board[it] + '0';
		write(1, &c, 1);
			
		if (it % 3 == 2)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		it++;
	}


	return token;
}
