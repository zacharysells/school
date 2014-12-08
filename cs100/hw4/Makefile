
all: my_shell handle_signals testLinkedString

my_shell: my_shell.o
	g++ -ggdb my_shell.o -o my_shell
	
my_shell.o: my_shell.cc
	g++ -c my_shell.cc
	
handle_signals: handle_signals.o
	g++ -ggdb handle_signals.o -o handle_signals
	
handle_signals.o: handle_signals.cc
	g++ -c handle_signals.cc 
	
testLinkedString: testLinkedString.o String.o
	g++ -ggdb testLinkedString.o String.o -o testLinkedString
	
testLinkedString.o: testLinkedString.cc
	g++ -c testLinkedString.cc
	
String.o: String.cc String.h
	g++ -c String.cc
	
clean: 
	rm my_shell my_shell.o handle_signals handle_signals.o testLinkedString testLinkedString.o String.o
	
strip:
	strip my_shell handle_signals testLinkedString 
	
print:
	cat < String.cc
