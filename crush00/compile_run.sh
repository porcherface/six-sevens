  
#!/bin/bash

main=code3/main.c
#ls ex0*/*

name=rush00
others="code3/ft_putchar.c code3/$name.c"
#Norminette $main $others -R CheckForbiddenSourceHeader
gcc $main $others -Wall -Wextra -Werror -o builds/$name".out"
./builds/$name".out" #> builds/$name".log"

name=rush01
others="code3/ft_putchar.c code3/rush01.c "
#Norminette $main $others -R CheckForbiddenSourceHeader
gcc $main $others -Wall -Wextra -Werror -o builds/$name".out"
./builds/$name".out" #> builds/$name".log"

name=rush02
others="code3/ft_putchar.c code3/rush02.c "
#Norminette $main $others -R CheckForbiddenSourceHeader
gcc $main $others -Wall -Wextra -Werror -o builds/$name".out"
./builds/$name".out" #> builds/$name".log"

name=rush03
others="code3/ft_putchar.c code3/rush03.c "
#Norminette $main $others -R CheckForbiddenSourceHeader
gcc $main $others -Wall -Wextra -Werror -o builds/$name".out"
./builds/$name".out" 

name=rush04
others="code3/ft_putchar.c code3/rush04.c "
#Norminette $main $others -R CheckForbiddenSourceHeader
gcc $main $others -Wall -Wextra -Werror -o builds/$name".out"
./$name".out" # > builds/$name".log"