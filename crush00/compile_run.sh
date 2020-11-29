  
#!/bin/bash
rm -rf builds
mkdir builds
main=code4/main.c
#ls ex0*/*

name=rush00
echo "
               running $name..."
others="code4/ft_putchar.c code4/$name.c"
#Norminette $main $others -R CheckForbiddenSourceHeader
gcc $main $others -Wall -Wextra -Werror -o builds/$name".out"
./builds/$name".out" #> builds/$name".log"

name=rush01
echo "
               running $name..."
others="code4/ft_putchar.c code4/rush01.c "
#Norminette $main $others -R CheckForbiddenSourceHeader
gcc $main $others -Wall -Wextra -Werror -o builds/$name".out"
./builds/$name".out" #> builds/$name".log"

name=rush02
echo "
               running $name..."
others="code4/ft_putchar.c code4/rush02.c "
#Norminette $main $others -R CheckForbiddenSourceHeader
gcc $main $others -Wall -Wextra -Werror -o builds/$name".out"
./builds/$name".out" #> builds/$name".log"

name=rush03
echo "
               running $name..."
others="code4/ft_putchar.c code4/rush03.c "
#Norminette $main $others -R CheckForbiddenSourceHeader
gcc $main $others -Wall -Wextra -Werror -o builds/$name".out"
./builds/$name".out" 

name=rush04
echo "
               running $name..."
others="code4/ft_putchar.c code4/rush04.c "
#Norminette $main $others -R CheckForbiddenSourceHeader
gcc $main $others -Wall -Wextra -Werror -o builds/$name".out"
./builds/$name".out" # > builds/$name".log"

diff code4/rush03.c code4/rush00.c