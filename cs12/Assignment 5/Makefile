#Course: CS 12 <Winter 2012r>

#First Name: Zachary 
#Last Name: Sells
#Course username: zsell001
#email address: zsell001@ucr.edu

# Lecture Section: 001
# Lab Section: 025
# TA: Mirebrahim, Seyed Hamid
#
# Assignment: assn5
#
# I hereby certify that the code in this file
# is ENTIRELY my own original work.
#
# =================================================================
MAIN = main.cpp
OBJECTS = main.o bboard.o message.o reply.o topic.o user.o
OUT = a.out

CXX = g++
FLAGS = -W -Wall -Werror -pedantic -ansi
CXXFLAGS = -g $(FLAGS)
COMPFLAGS = -c $(FLAGS)

COMPILE = $(CXX) $(CXXFLAGS)
COMPILE_ONLY = $(CXX) $(COMPFLAGS)

all: $(OBJECTS)
	$(COMPILE) $(OBJECTS) -o $(OUT)

bboard.o: bboard.h bboard.cpp
	$(COMPILE_ONLY) bboard.cpp

message.o: message.h message.cpp
	$(COMPILE_ONLY) message.cpp

reply.o: reply.h reply.cpp
	$(COMPILE_ONLY) reply.cpp

topic.o: topic.h topic.cpp
	$(COMPILE_ONLY) topic.cpp

user.o: user.h user.cpp
	$(COMPILE_ONLY) user.cpp


clean:
	rm -rf *.out *.o *~ $(OUT) docs

docs:
	doxygen Doxyfile
