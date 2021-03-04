NAME = libftprintf.a
SHARED = libftprintf.so
MAIN = ft_printf
DEPS = fun/ft_*.c
LIB  = lib/libft.a 
#LIB  =  lib/ft_putstr_fd.c

SRC_M = $(MAIN:=.c)
#SRC_D = $(DEPS:=.c)
SRC_D = fun/*.c

OBJ_D = *.o
OBJ_M = $(MAIN:=.o)
#OBJ_D = $(DEPS:=.o)

CC = gcc
CFLAGS = #-Wall -Wextra -Werror

$(NAME):
	$(CC) $(CFLAGS) $(SRC_M) $(SRC_D) -I$(LIB) -c
	ar rcs $(NAME) $(OBJ_M) $(OBJ_D)
	ranlib $(NAME) 
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