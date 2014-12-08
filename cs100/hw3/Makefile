all: testString fork unix_io

testString: testString.o String.o
	g++ testString.o String.o -o testString

testString.o: testString.cc
	g++ -c testString.cc
	
String.o: String.cc
	g++ -c String.cc
	
fork: fork.o
	g++ fork.o -o fork

fork.o: fork.cc
	g++ -c fork.cc
	
unix_io: unix_io.o
	g++ unix_io.o -o unix_io
	
unix_io.o: unix_io.cc
	g++ -c unix_io.cc
	
clean:
	rm unix_io unix_io.o fork fork.o testString testString.o String.o
