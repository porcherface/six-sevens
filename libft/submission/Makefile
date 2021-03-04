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

NAME =	libft.a

FILES	=	ft_memset ft_bzero ft_calloc ft_memcpy ft_memccpy ft_memcmp \
		ft_memchr ft_strlen ft_strlcpy ft_strlcat ft_strchr ft_strrchr \
		ft_memmove ft_strdup\
		ft_strnstr ft_strncmp ft_atoi ft_isalpha ft_isdigit \
		ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower \
		ft_substr ft_strjoin ft_strtrim ft_split ft_itoa \
		ft_strmapi ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \

B_FILES = 	ft_lstnew ft_lstadd_front ft_lstadd_back ft_lstsize \
		ft_lstlast ft_lstdelone ft_lstclear ft_lstiter \
		ft_lstmap

SRC 	= $(addsuffix .c, $(FILES))
B_SRC 	= $(addsuffix .c, $(B_FILES))

OBJS	= $(addsuffix .o, $(FILES))
B_OBJS	= $(addsuffix .o, $(B_FILES))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: bonus

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@ar rcs $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS) $(B_OBJS)

fclean: clean
	@rm -f $(NAME)

bonus: $(NAME)
	@$(CC) $(CFLAGS) -c $(B_SRC)
	@ar rcs $(NAME) $(B_OBJS)


re: clean fclean all
