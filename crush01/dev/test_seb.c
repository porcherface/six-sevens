
#include <stdlib.h>
#include <unistd.h>

int print_output(int token, int board[], int size);

int main()
{
	
	int token = -1;
	int board[9] = 0;
	int size = 3;


	print_output(token, board, size);

	int token = 0;
	int board[9];
	int size = 3;

	int it = 0;
	while (it < 9)
	{
		board[it] = it;
	}
	
	print_output(token, board, size);

	return token;
}