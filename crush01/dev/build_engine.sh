seb=print_output.c
rob=engine_test.c
and="rush_engine_old.c"
and2="human_engine.c"


gcc -Wall -Wextra -Werror $rob code/$seb code/$and code/$and2 -o test_rush.out
./test_rush.out
rm test_rush.out