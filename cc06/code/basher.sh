

gcc -Wall -Wextra -Werror ex00/* -o out0.out
gcc -Wall -Wextra -Werror ex01/* -o out1.out
gcc -Wall -Wextra -Werror ex02/* -o out2.out
gcc -Wall -Wextra -Werror ex03/* -o out3.out

./out0.out "abba" dabba "cabba"
./out1.out "abba" dabba "cabba"
./out2.out "abba" dabba "cabba"
./out3.out "abba" dabba "cabba"

./out0.out 
./out1.out 
./out2.out 
./out3.out 

rm out*.out