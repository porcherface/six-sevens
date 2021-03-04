

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int get_next_line(int fd, char **line);

int test_1_line()
{
	int fd;
	char *line;
	int ret;

	line = 0x0;
	fd = open("test/test_1_line.txt", O_RDONLY);
	if (!fd)
		return (9999);

	printf("calling\n");
	ret = get_next_line(fd, &line);
	printf("line: %s\n", line);
	printf("gnl returned %d\n", ret);

	return (00000000);
}


int test_2_lines()
{
	int fd;
	char *line;
	int ret;

	line = 0x0;
	fd = open("test/test_2_line.txt", O_RDONLY);
	if (!fd)
		return (9999);

	printf("calling twice (1) \n");
	ret = get_next_line(fd, &line);
	printf("line: %s\n", line);
	printf("gnl returned %d\n", ret);

	printf("calling twice (2) \n");
	ret = get_next_line(fd, &line);
	printf("line: %s\n", line);
	printf("gnl returned %d\n", ret);

	return (00000000);
}


int test_empty_lines()
{
	int fd;
	char *line;
	int ret;
	line = 0x0;
	fd = open("test/test_empty_7_lines.txt", O_RDONLY);
	if (!fd)
		return (9999);

	printf("calling till eof?\n");
	ret = get_next_line(fd, &line);
	printf("line: %s\n", line);

	while( ret > 0 )
	{
		ret = get_next_line(fd, &line);
		printf("line: %s\n", line);
	}

	printf("gnl returned %d\n"  , ret);
	return (ret);
}

int main()
{

	printf("***************************************************\n" );
	printf("********************* TEST 1 **********************\n" );
	printf("***************************************************\n" );
	test_1_line();
	
	printf("***************************************************\n" );
	printf("********************* TEST 2 **********************\n" );
	printf("***************************************************\n" );
	test_2_lines();

	printf("***************************************************\n" );
	printf("********************* TEST 3 **********************\n" );
	printf("***************************************************\n" );
	test_empty_lines();


}
