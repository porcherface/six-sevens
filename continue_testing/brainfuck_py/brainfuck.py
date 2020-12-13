'''
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.py                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amazzei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 13:41:24 by amazzei           #+#    #+#             */
/*   Updated: 2020/12/13 11:20:04 by amazzei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
'''

''' emulation of the unistd ascii write function '''
def putchar(char):
	print(chr(int(char)), end='')

''' emulation of getchar function '''
def getchar( ):
	return(ord(input( )[0]))

''' while loops '''
def brainfuck_goto(cursor, code, symbol):
	while code[cursor]!= symbol :
		if symbol == ']':
			cursor += 1
		if symbol == '[':
			cursor -= 1
	return cursor

''' the interpreter '''
def fuck_brain(code_string, buff_size = 4096):
	
	code_cursor = 0
	code_len = len(code_string)

	''' variables are limited to N bytes buffer '''
	buff = [0] * buff_size
	buff_ptr = 0

	''' run into code '''
	while code_cursor < code_len:
		
		''' handles memory leaks '''
		if (buff_ptr >= buff_size):
			raise  RuntimeError('Access to forbidden buffer position') 
		if (buff_ptr < 0):
			raise  RuntimeError('Access to forbidden buffer position') 

		instr = code_string[code_cursor]

		''' parse instruction '''
		if instr == '>':
			buff_ptr += 1
	
		if instr == '<':
			buff_ptr -= 1
					
		if instr == '+':
			buff[buff_ptr] += 1
	
		if instr == '-':
			buff[buff_ptr] -= 1
		
		if instr == '.':
			putchar( buff[buff_ptr] )

		if instr == ',':
			buff[buff_ptr] = getchar(  )

		if instr == '[':
			if buff[buff_ptr] == 0:
				code_cursor = brainfuck_goto(code_cursor, code_string, ']')

		if instr == ']':
			if buff[buff_ptr] != 0:
				code_cursor = brainfuck_goto(code_cursor, code_string, '[')

		''' move the cursor '''
		code_cursor += 1

''' a testing environment '''
if __name__ == "__main__":

	'''
	rules for brainfuck	(C like syntax)
	only one pointer, built-in putchar and getchar functions
	put and get are in ascii values

	syntax: 	
		>	++ptr;
		<	--ptr;
		+	++(*ptr);
		-	--(*ptr);
		.	putchar(*ptr);
		,	*ptr = getchar();
		[	while (*ptr) {
		]	}
	

	you can think of this main as a text editor, 
	
	- write your code (if u can)
	- call fuck_brain( code ) to run the code      
	- run brainfuck.py

	comes with 3 examples

	1) hello world
	2) sum two digits (5+2)
	3) a very nice 2-variables (with names) 
	   getstring() putstring() implementation, 
	   which is credited to https://github (dot) com/brain-lang/brain

	
    '''
	hello_world = """
					porcherface @ gmail (dot) com
					++++++++++
					[
					>+++++++>++++++++++>+++>+<<<<-
					] a starting loop for charsetting

			 		>++. here i print my first brainfuck H 

			   	          	HELLO____WORLD!!!!
		   			all these lines are interpeted as comments
(use triple quotes to avoid indentation problems) 
					>+.  
					+++++++. now L
					. another L
					+++. and so on
					>++.
					<<+++++++++++++++.
					>.  hope u like it
					+++.
					------.
					--------.
					>+.
					>.

				    """
	
	#one liner : ++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.	>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.

	god_dog = """ 
				
				    type setting to write god dog\n
				    
				    wgod dog  
				     
				    +++++ +++++ w = 10 i use it for while cycle
				    [           
				    	> +++++ +++++ d typesets to d
				    	> +++++ +++++ d 
				    	> +++++ +++++ d
				    	> +++++ +++++ d
				    	> +++++ +++++ d
				    	> +++++ +++++ d
				    	> +++++ +++++ d (d is 100 i wrote plus10 ten times in 7 variables)
				    	<<<<<<<-
				    ] (pointer is in w)
				
				    now we have a ddddddd
				    >
				    +++ g
				    >
				    +++++++++++ o
				    >
				     d
				    >
				    -----
				    >
				     d
				    >
				    +++++++++++ o
				    >
				    +++ g
				    <<<<<<
				
				    now a simple print 7 routine
				    .>.>.>.>.>.>.
				
				    > +++++ +++++ . print newline


   					 """


	fuck_brain(god_dog)

	five_plus_two = """

						++       Cell c0 = 2
						> +++++  Cell c1 = 5
						
						[        Start your loops with your cell pointer on the loop counter (c1 in our case)
						< +      Add 1 to c0
						> -      Subtract 1 from c1
						]        End your loops with the cell pointer on the loop counter
						
						At this point our program has added 5 to 2 leaving 7 in c0 and 0 in c1
						but we cannot output this value to the terminal since it is not ASCII encoded!
						
						To display the ASCII character "7" we must add 48 to the value 7
						48 = 6 * 8 so let's use another loop to help us!
						
						++++ ++++  c1 = 8 and this will be our loop counter again
						[
						< +++ +++  Add 6 to c0
						> -        Subtract 1 from c1
						]
						< .        Print out c0 which has the value 55 which translates to "7"!

						"""
	#fuck_brain(five_plus_two)

	string_test = """
					this program reads an input of 5 and stores in
					a string called B, then outputs the string 
					,>,>,>,>,>+++++++++++++++++++++++++++++++++
					+++++++++++++++++++++++++++++++++++++++++++
					++++++++++++++++++++++.--------------------
					-------------------------------------------
					---.+++++++++++++++++++++++++++++.---------
					--------------------.----------------------
					----------<<<<<.>.>.>.>.>++++++++++.-------
					---,>++++++++++++++++++++++++++++++++++++++
					+++++++++++++++++++++++++++++++++++++++++++
					++++++++++++++++++.------------------------
					-------------------------------------------
					.+++++++++++++++++++++++++++++.------------
					-----------------.-------------------------
					-------<.>					
					then does the same with an input of 1
					and stores it in C
					 ++++++++++.----------<<<<<<,>,>,>
					then overwrites the value of B and prints B 
					,>,>>++++++++++++++++++++++++++++++++++++++
					+++++++++++++++++++++++++++++++++++++++++++
					+++++++++++++++++.-------------------------
					-----------------------------------------.+
					++++++++++++++++++++++++++++.--------------
					---------------.---------------------------
					-----<<<<<<.>.>.>.>.>>++++++++++.----------
					
					this example is proudly stolen from
					
						https://github (dot) com/brain-lang/brain
					
					take a look at this repo (dot dot dot)
					"""

	#fuck_brain(string_test)