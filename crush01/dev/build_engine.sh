

target="submit/"

seb=$target"print_output.c"
rob="engine_test.c"
and=$target"rush_engine.c"
and2=$target"human_engine.c"

Norminette $target -R CheckForbiddenSourceHeader
gcc -Wall -Wextra -Werror $rob $seb $and $and2 -o test_rush.out

#valgrind -v --leak-check=yes $(cd "$(dirname "$1")" && pwd -P)/test_rush.out
./test_rush.out
#rm test_rush.out
