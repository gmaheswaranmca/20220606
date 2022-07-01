valgrind --leak-check=full --show-leak-kinds=all -s ./main

$gcc dia-03.c -o main -g
$gdb ./main 
>run
>list 1, 		#display code from line no 1 #10 lines are printed 
>list           #display code after line no it printed before ie from line #11, total 10 lines is printed 
-------------------------


$gcc pattern.c -o main -g
$gdb ./main 
(gdb)list 1,20
(gdb)b 10
(gdb)b 13
(gdb)info b
(gdb)run 
(gdb)display N-I
(gdb)display I
(gdb)display I-1
(gdb)display

-------------------------


start the gdb by attaching your program build 
	Note: the build you take via -g flag 
	
Basic Commands: 
list 1,					to see the code from line # 1 
list 11,30 				to see the code from line # 11 till 30 
list main 				to see which line no the main is 
list printPattern 		to see which line no the function printPattern is 
break 17 				to set the break point at 17 
next 					to move next line 
step					if there is a function in the line, it will go inside the function 
continue				to go to next break point 
info b 					to print break points 
return 					to return from the function without executing the code after getting confirmation 
q 						to quit from gdb 


-------------------------





