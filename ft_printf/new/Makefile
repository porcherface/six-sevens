NAME = test_ftprintf.out

MAKE = make
REMAKE = make re
LINUX = make linux

SRC = printf_test
LIB = libftprintf.a
SHARED = libftprintf.so

CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME): test
	cp  src/$(LIB) test/
	$(CC) -Ltest/ $(CFLAGS) -o $(NAME) test/$(LIB) test/$(SRC).c  

test: 
	$(CC) -c $(CFLAGS) test/$(SRC).c

lib: 
	$(MAKE) -C src

relib: 
	$(REMAKE) -C src
	cp  src/$(LIB) test/

clean:
	rm -rf $(NAME)
	rm -rf test/$(LIB)
	rm -rf test/$(SHARED)
	rm -rf src/*.o

re: clean relib $(NAME)
	$(CC) $(CFLAGS) test/$(LIB) test/$(SRC).c -o $(NAME)

all: lib $(NAME)

linux: 
	$(LINUX) -C src
	cp  src/$(SHARED) test/
	$(CC) -Ltest/ $(CFLAGS) -o $(NAME) test/$(SRC).c -Lftprintf test/$(SHARED)

run:
	./$(NAME)
	./$(NAME) "custom string test"

rerun: re run
