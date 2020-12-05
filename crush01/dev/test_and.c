
#include <stdlib.h>

int rush_engine(int rules[], int size, int *board);

int main()
{
	int size = 4;
	int rules[4*4];
	int *board = 0x0;
	int token;
	if (size > 0)
		board = (int*)malloc(size*size*sizeof(int));
	int it=0;
	while(it<size*size)
	{
		board[it] = 0;
		it++;
	}
	rules[0] = 4;
	rules[1] = 3;
	rules[2] = 2;
	rules[3] = 1;
	rules[4] = 1;
	rules[5] = 2;
	rules[6] = 2;
	rules[7] = 2;
	rules[8] = 4;
	rules[9] = 3;
	rules[10] = 2;
	rules[11] = 1;
	rules[12] = 1;
	rules[13] = 2;
	rules[14] = 2;
	rules[15] = 2; 
	token = rush_engine(rules, size, board);
	return token;
}