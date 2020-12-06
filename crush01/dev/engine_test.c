#include <stdlib.h>

int rush_engine(int rules[], int size, int *board);
int print_output(int token, int board[], int size);


int main()
{
	/*
	int size = 3;
	char *args = "1 3 2 2 1 2 1 3 2 2 1 2";
	*/

	/*
	int size = 4;
	char *args = "1 2 3 2 3 2 1 2 1 3 2 3 3 1 3 2";
	*/

	/* subject example */
	
	int size = 4;
	char *args = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	
	/*
	int size = 5;
	char *args = "2 4 3 1 2 3 1 3 5 2 2 1 3 3 2 2 3 3 1 2";
	*/
	/*
	int size = 6;
	char *args = "3 1 2 2 4 3 3 3 2 3 1 2 2 2 3 1 3 4 4 2 3 4 1 2";
	*/
	/*
	int size = 7;
	char *args = "2 3 1 3 2 4 3 4 2 3 2 1 3 3 3 1 3 4 2 2 5 4 5 1 2 2 4 2";
	*/
	/*
	int size = 9;
	char *args = "2 1 4 3 3 3 3 3 2 5 2 2 2 5 3 1 4 2 2 1 2 5 3 3 4 3 3 2 5 3 2 2 1 3 5 2";
	*/




	int token = size;
	int *rules;
	int *board;
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