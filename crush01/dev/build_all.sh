targetdir="code/"

gcc -Wall -Wextra -Werror $targetdir"print_output.c" $targetdir"rush_engine.c" $targetdir"main.c" -o rush_01.out


#casi positivi
./rush_01.out "1 1 1 1"
./rush_01.out "2 1 1 2 2 1 1 2"
./rush_01.out "1 3 2 2 1 2 1 3 2 2 1 2"
./rush_01.out "4 2 1 2 1 2 4 2 3 2 2 1 2 3 1 2"
./rush_01.out "2 2 2 3 1 3 2 2 1 4 4 1 3 2 3 1 3 2 2 2"

#casi limite
./rush_01.out "01 1 1 1"
./rush_01.out "1 1 1 1 "
./rush_01.out " 1 1 1 1 "

#negativi
./rush_01.out "1 1 1 1 a" #un char
./rush_01.out "2 1 1 2" #bad constr
./rush_01.out "1 3 2 1 2 1 2 1 3 2 2 1 2" #wrong str size
./rush_01.out "4 2 1 5 1 2 4 2 3 2 2 1 2 3 1 2" #bad constr
