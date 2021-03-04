NAME = libftprintf.a
SHARED = libftprintf.so
MAIN = ft_printf.c
DEPS = fun/*.c
LIB  = lib/ft_*.c 

SRC_M = $(MAIN:=.c)
#SRC_D = $(DEPS:=.c)

OBJ_D = *.o
OBJ_M = $(MAIN:=.o)
#OBJ_D = $(DEPS:=.o)

CC = gcc
CFLAGS = #-Wall -Wextra -Werror

$(NAME):
	# $(CC) $(CFLAGS) $(SRC_M) $(SRC_D) $(LIB) -c
	$(CC) $(CFLAGS) $(MAIN) $(DEPS) $(LIB) -c
	ar rcs $(NAME) *.o
	ranlib $(NAME) 
	rm -rf *.o
	@echo " [ OK ]"

all: $(NAME) clean

clean:
	@rm -rf $(OBJ_M) $(OBJ_D)

fclean: clean
	rm -f $(NAME) $(SHARED)

re: clean fclean all

linux:
	$(CC) $(CFLAGS) -c -fpic $(SRC_M) $(SRC_D)
	$(CC) $(CFLAGS) -shared $(OBJ_M) $(OBJ_D) -o $(SHARED)