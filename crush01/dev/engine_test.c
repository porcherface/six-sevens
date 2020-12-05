#include <stdlib.h>

int rush_engine(int rules[], int size, int *board);
int print_output(int token, int board[], int size);


int main()
{

	int size = 2;
	int token = size;
	int *rules;
	int *board;
	char *args = "2 1 1 2 2 1 1 2";
	int it = 0;

	if (size > 0)
	{
		board = (int*)malloc(size * size * sizeof(int));
		rules = (int*)malloc(4 * size * sizeof(int));	
	}
	while(it < size * 4)
	{
		rules[it] = args[it*2] - '0';
		it++;
	}
	it = 0;
	while(it < size * size)
	{
		board[it] = 0;
		it++;
	}

	if(token > 0)
	{
		size = token;
		token = rush_engine(rules, size, board);
	}
	token = print_output(token, board, size);
	free(board);
	free(rules);
	return (token);


}