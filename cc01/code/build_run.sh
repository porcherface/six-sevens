main=main.c
rm -rf build

#ls ex0*/*
others=""
others=$others"ex00/ft_ft.c ex01/ft_ultimate_ft.c "
others=$others"ex02/ft_swap.c ex03/ft_div_mod.c "
others=$others"ex04/ft_ultimate_div_mod.c ex05/ft_putstr.c "
others=$others"ex06/ft_strlen.c ex07/ft_rev_int_tab.c "
others=$others"ex08/ft_sort_int_tab.c "

mkdir build
gcc $main $others ft_putnbr.c -Wall -Wextra -Werror -o build/test.out
./build/test.out