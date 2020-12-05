

int parse_input(int argc, char **argv, int *rules);
int rush_engine(int rules[], int size, int *board);
int print_output(int token, int board[], int size);
int allocate_all_memories(int *rules, int *board, int size);

int main(int argc, char **argv)
{
	int size;
	int token;
	int *rules;
	int *board;

	token = parse_input(argc, argv, rules);
	
	/* do we wanna keep it here or mask it */
	/* inside a module? */
	if (token > 0)
	{
		token = allocate_all_memories(rules, board, size);
	}
	if(token > 0)
	{
		size = token;
		token = rush_engine(rules, size, board);
	}
	token = print_output(token, board, size);
	return (token);
}