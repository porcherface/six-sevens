cd code
main=test_slot.c
oracle=c00_oracle.txt

#ls ex0*/*
others=""
others=$others"ex00/ft_putchar.c ex05/ft_print_comb.c "
others=$others"ex01/ft_print_alphabet.c ex06/ft_print_comb2.c "
others=$others"ex02/ft_print_reverse_alphabet.c ex07/ft_putnbr.c "
others=$others"ex03/ft_print_numbers.c ex08/ft_print_combn.c "
others=$others"ex04/ft_is_negative.c "

#bash norminette_c00.sh

gcc $main $others -Wall -Wextra -Werror -o c00_test.out

./c00_test.out > $oracle