  
#!/bin/bash

main=code/main.c
oracle=crush_oracle.txt
name=rusherino.out
#ls ex0*/*
others="code/ft_putchar.c code/rush99.c "

Norminette $main $others -R CheckForbiddenSourceHeader
gcc $main $others -Wall -Wextra -Werror -o $name

./$name #> $oracle