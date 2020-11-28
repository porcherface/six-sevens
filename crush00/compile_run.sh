  
#!/bin/bash
cd code
main=main.c
oracle=c00_oracle.txt

#ls ex0*/*
others=""
others=$others"code/ft_putchar.c rushXX.c "

Norminette $main $others -R CheckForbiddenSourceHeader
gcc $main $others -Wall -Wextra -Werror -o c00_test.out

./c00_test.out > $oracle