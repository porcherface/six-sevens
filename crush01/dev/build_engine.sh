seb=print_output.c
and=engine_test.c
rob=rush_engine_old.c

gcc -Wall -Wextra -Werror $rob code/$seb code/$and -o test_rush.out
./test_rush.out
rm test_rush.out