#Course: CS 12 <Winter 2012r>

#First Name: Zachary 
#Last Name: Sells
#Course username: zsell001
#email address: zsell001@ucr.edu

# Lecture Section: 001
# Lab Section: 025
# TA: Mirebrahim, Seyed Hamid
#
# Assignment: assn4
#
# I hereby certify that the code in this file
# is ENTIRELY my own original work.
#
# =================================================================
MAIN = main.cpp
OBJECTS = main.o intvector.o
OUT = a.out

CXX = g++
FLAGS = -W -Wall -Werror -pedantic -ansi
CXXFLAGS = -g $(FLAGS)
COMPFLAGS = -c $(FLAGS)

COMPILE = $(CXX) $(CXXFLAGS)
COMPILE_ONLY = $(CXX) $(COMPFLAGS)

all: $(OBJECTS)
	$(COMPILE) $(OBJECTS) -o $(OUT)

intvector.o: intvector.h intvector.cpp
	$(COMPILE_ONLY) intvector.cpp

clean:
	rm -rf *.out *.o *~ $(OUT) docs

docs:
	doxygen Doxyfile
