SOURCES=my_ls.cc Coins.cc main.cc betterMain.cc bestMain.cc
OBJECTS=my_ls.o Coins.o main.o betterMain.o bestMain.o

CXX=g++

all: my_ls Coins_main Coins_better Coins_best

my_ls: my_ls.o
	$(CXX) my_ls.o -o my_ls

my_ls.o: my_ls.cc
	$(CXX) -c my_ls.cc

Coins_main: Coins.o main.o
	$(CXX) Coins.o main.o -o Coins_main

Coins_better: Coins.o betterMain.o
	$(CXX) Coins.o betterMain.o -o Coins_better

Coins_best: Coins.o bestMain.o
	$(CXX) Coins.o bestMain.o -o Coins_best

Coins.o: Coins.h Coins.cc
	$(CXX) -c Coins.cc

main.o: main.cc
	$(CXX) -c main.cc

betterMain.o: betterMain.cc
	$(CXX) -c betterMain.cc

bestMain.o: bestMain.cc
	$(CXX) -c bestMain.cc

clean:
	rm $(OBJECTS) Coins_best Coins_better Coins_main my_ls
