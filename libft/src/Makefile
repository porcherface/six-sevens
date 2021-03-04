#/ ************************************************************************** */
#/                                                                            */
#/                                                        :::      ::::::::   */
#/   libft Makefile                                     :+:      :+:    :+:   */
#/                                                    +:+ +:+         +:+     */
#/   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
#/                                                +#+#+#+#+#+   +#+           */
#/   Created: 2020/12/09 14:17:19 by amazzei           #+#    #+#             */
#/   Updated: 2020/12/11 13:20:40 by amazzei          ###   ########.fr       */
#/                                                                            */
#/ ************************************************************************** */

MAINNAME = test_libft.c
NAME = out.out
LIBNAME = libft.a

.PHONY = clean fclean aclean cleanall re

# karen 
CC = gcc
CFLAGS = -Wall -Werror -Wextra #-pedantic
SRCS = ft_*.c

all: lib clean

# create obj and arch rule
objects: clean
	@$(CC) $(CFLAGS) $(SRCS) -c 

pic: clean
	@$(CC) $(CFLAGS) $(SRCS) -c -fpic

so: pic
	@$(CC) $(CFLAGS) -shared -o libft.so *.o

lib: objects 
	@ar rcs $(LIBNAME) *.o
	@rm -f *.o

# create executables
test: lib
	$(CC) $(CFLAGS) $(MAINNAME) $(LIBNAME) -o $(NAME)
	@./$(NAME)

bonus: lib

#@$(MAKE) cleanall
$(NAME): lib
	$(CC) $(CFLAGS) $(MAINNAME) $(LIBNAME) -o $(NAME)

# phony targets to clean
clean:
	@rm -f *.o *.so

fclean:
	@rm -f $(NAME) $(LIBNAME)

aclean:
	@rm -f libft.a

cleanall :clean fclean aclean

re: cleanall all
	