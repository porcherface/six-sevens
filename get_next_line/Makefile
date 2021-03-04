
# aaaargh absolute path
BOT_PWD = /Users/amazzei/Desktop/testenv

SIZE 	= 256
CC		= gcc 
CFLAG	= -Wall -Wextra -Werror 
FLAG	= -D BUFFER_SIZE=$(SIZE)


SRC		= src/get_next_line.c src/get_next_line_utils.c
HEAD	= src/get_next_line.h
TEST 	= test_main.c		  

NAME	= test_gnl.out

all: exe run clean

exe: 
	$(CC) $(CFLAG) $(FLAG) $(SRC) $(TEST) -o $(NAME)
	@echo "done"

run: 
	./$(NAME) | cat -e
	@echo "done"

clean:
	rm -f *.o
	rm -f $(NAME)
	@echo "done"

bot: 
	cp $(SRC) $(BOT_PWD)
	cp $(HEAD) $(BOT_PWD)
	@echo "copied into $(BOT_PWD)"