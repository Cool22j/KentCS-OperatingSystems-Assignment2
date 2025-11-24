# Instructions to run
The input file expects 3 and only 3 lines, 1st line is the allocated processes, 2nd line is the maximum processes, and the 3rd line is the avaiable process. Use the given input.txt as a guide to how to format the inputs you would want to test.
Be sure when you run the program, that the input file is in the same directory as the cpp file.

# Program description
This program takes in an input of vectors from a file and treats them like processes with resources. The program then computes each process's remaining need and then repeatedly searches for a process whose needs can be satisfied with the currently available resources. 
When such a process is found, it is treated as if it finishes its allocated resources are returned to the available pool. 

Answering the question that this assignment asks: Yes, the system is in a safe state and the safe sequence of processes is [P3 -> P4 -> P1 -> P2 -> P0].

