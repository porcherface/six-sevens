targetdir="submit/"
oraclename="seb_and_rob_oracle.txt"
#gcc -Wall -Wextra -Werror $targetdir"ft_atoi_replace.c" $targetdir"print_output.c" $targetdir"rush_engine.c" $targetdir"main.c" -o rush_01.out
gcc -Wall -Wextra -Werror "$targetdir"* -o rush_01.out

echo " --- positives --- " #> $oraclename
./rush_01.out "1 1 1 1" #> $oraclename
./rush_01.out "2 1 1 2 2 1 1 2" ##> $oraclename
./rush_01.out "1 3 2 2 1 2 1 3 2 2 1 2" #> $oraclename
./rush_01.out "4 2 1 2 1 2 4 2 3 2 2 1 2 3 1 2" #> $oraclename
./rush_01.out "2 2 2 3 1 3 2 2 1 4 4 1 3 2 3 1 3 2 2 2" #> $oraclename
./rush_01.out "3 1 2 2 4 3 3 3 2 3 1 2 2 2 3 1 3 4 4 2 3 4 1 2"
#./rush_01.out "2 3 1 3 2 4 3 4 2 3 2 1 3 3 3 1 3 4 2 2 5 4 5 1 2 2 4 2"


echo " --- negatives --- " #> $oraclename
./rush_01.out  #> $oraclename
./rush_01.out "" #> $oraclename
./rush_01.out " " #> $oraclename
./rush_01.out "1 1 1 1 a" #> $oraclename
./rush_01.out "1a 1 1 1" #> $oraclename
./rush_01.out "1  1 1 1" #> $oraclename
./rush_01.out "1	1 1 1" #> $oraclename
./rush_01.out "2 1 1 2"  #> $oraclename 
./rush_01.out "2 2 2 2 2 2 2 2"  #> $oraclename 
./rush_01.out "1 3 2 1 2 1 2 1 3 2 2 1 2" #> $oraclename
./rush_01.out "4 2 1 5 1 2 4 2 3 2 2 1 2 3 1 2" # > $oraclename
./rush_01.out "a" # > $oraclename
./rush_01.out "1 1 1" # > $oraclename
./rush_01.out "eaghjaeiughnaeiu giuaefg iae" # > $oraclename
./rush_01.out "1 1 1 1eaghjaeiughnaeiu giuaefg iae" # > $oraclename

echo " --- limit --- " #> $oraclename
./rush_01.out "01 1 1 1" #> $oraclename
./rush_01.out "1 1 1 1 " #> $oraclename
./rush_01.out " 1 1 1 1 " #> $oraclename
