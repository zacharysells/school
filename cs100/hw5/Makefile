
all: my_shell polymorphism

my_shell: my_shell.o
	g++ -ggdb my_shell.o -o my_shell

my_shell.o: my_shell.cc
	g++ -c -ggdb my_shell.cc
	
polymorphism: main.o game.h hangman.o mathGame.o guessingGame.o
	g++ -ggdb main.o hangman.o mathGame.o guessingGame.o -o polymorphism
	
main.o: main.cc game.h
	g++ -c -ggdb main.cc
	
hangman.o: hangman.cc game.h
	g++ -c -ggdb hangman.cc
	
mathGame.o: mathGame.cc game.h
	g++ -c -ggdb mathGame.cc
	
guessingGame.o: guessingGame.cc game.h
	g++ -c -ggdb guessingGame.cc
	
clean: 
	rm my_shell polymorphism my_shell.o main.o hangman.o mathGame.o guessingGame.o my_shell.pdf

strip: 
	strip my_shell

print:
	a2ps -R --columns=1 --borders=0 -B -P pdf my_shell.cc
	



