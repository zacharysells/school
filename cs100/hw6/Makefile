all: my_shell matrix_main

my_shell: my_shell.o
	g++ -ggdb my_shell.o -o my_shell

my_shell.0: my_shell.cc
	g++ -c -ggdb my_shell.cc
	
matrix_main: main.o 
	g++ -ggdb main.o -o matrix_main
	
main.o: main.cpp Array.cpp Array.h Matrix.cpp Matrix.h
	g++ -c -ggdb main.cpp
	
clean: 
	rm my_shell my_shell.o matrix_main main.o 
