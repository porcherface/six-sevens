
targetdir="code/"
AND=1

if [ $AND ]
then
	gcc -Wall -Wextra -Werror $targetdir"rush_engine_old.c" test_and.c -o out_and.out
fi
