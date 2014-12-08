all: frequency int_sort

frequency: frequency.o
	g++ frequency.o -o frequency
	
frequency.o: frequency.cc
	g++ -c frequency.cc 
	
int_sort: int_sort.o
	g++ int_sort.o -o int_sort

int_sort.o: int_sort.cc
	g++ -c int_sort.cc

clean:
	rm frequency int_sort frequency.o int_sort.o
