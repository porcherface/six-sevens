#include <unistd.h>

#define BUFF_LEN 4096

void bf_putchar(char c)
{
	write(1, &c, 1);
}

int bf_getchar( )
{
	return 0;
}

int bf_strlen(char *str)
{
	int it = 0;
	while(str[it])
	{
		it++;
	}
	return it;
}

int bf_brainfuck_goto(int cursor, char *code, char symbol)
{
	while (code[cursor] != symbol) 
	{	
		if (symbol == ']')
			cursor++;
		if (symbol == '[')
			cursor--;
	}
	return cursor;
}

int fuck_brain(char *code_string)
{
	int code_cursor = 0;
	int code_len = bf_strlen(code_string);
	int buff_ptr = 0;
	char instr;
	int buff[BUFF_LEN];
	/* initialize buffer to zero */
	while(buff_ptr<BUFF_LEN)
	{
		buff[buff_ptr] = 0;
		buff_ptr++;
	}

	buff_ptr = 0;
	while (code_cursor < code_len)
	{	
		instr = code_string[code_cursor]; 

		if(buff_ptr < 0 || buff_ptr > BUFF_LEN)
		{
			write(1, "Memory access error, returning 1",33);
			return (1);
		}
		if (instr == '>')
			buff_ptr++;
	
		if (instr == '<')
			buff_ptr--;
					
		if (instr == '+')
			buff[buff_ptr]++;
	
		if (instr == '-')
			buff[buff_ptr]--;
		
		if (instr == '.')
			bf_putchar( buff[buff_ptr] );

		if (instr == ',')
			buff[buff_ptr] = bf_getchar(  );

		if (instr == '[')
		{
			if (buff[buff_ptr] == 0)
				code_cursor = bf_brainfuck_goto(code_cursor, code_string, ']');
		}

		if (instr == ']')
		{
			if (buff[buff_ptr] != 0)
				code_cursor = bf_brainfuck_goto(code_cursor, code_string, '[');
		}
		code_cursor++;
	}

	return 0;
}


int main(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "Error: no code submitted\n", 26);
		return 1;
	}
	fuck_brain(argv[1]);

}