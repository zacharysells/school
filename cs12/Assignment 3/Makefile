# filenames of main, classes to be compiled, and output:
MAIN = main.cpp
OBJECTS = user.o message.o bboard.o
OUT = a.out

# Compile components:
CXX = g++
FLAGS = -W -Wall -pedantic -ansi
CXXFLAGS = -g $(FLAGS)
COMPFLAGS = -c $(FLAGS)

# The directory where ccc_win library header files reside:
# NONE NEEDED FOR THIS ASSIGNMENT
INCDIR =

# The basic compile command:
COMPILE = $(CXX) $(CXXFLAGS)
COMPILE_ONLY = $(CXX) $(COMPFLAGS)

# Libraries & where to find them:
# NONE NEEDED FOR THIS ASSIGNMENT
LIBS =
LIBDIRS =

# Now compile it all:
all: $(OBJECTS)
	$(COMPILE) $(MAIN) $(OBJECTS) -o $(OUT) #REPLACE THE SPACES AT THE BEGINNING OF LINE WITH A 'TAB'.


user.o: user.h user.cpp

	$(COMPILE_ONLY) user.cpp #REPLACE THE SPACES AT THE BEGINNING OF LINE WITH A 'TAB'.


message.o: message.h message.cpp

	$(COMPILE_ONLY) message.cpp #REPLACE THE SPACES AT THE BEGINNING OF LINE WITH A 'TAB'.


bboard.o: bboard.h bboard.cpp user.h message.h

	$(COMPILE_ONLY) bboard.cpp #REPLACE THE SPACES AT THE BEGINNING OF LINE WITH A 'TAB'.




# ... or clean it up:

clean:

	rm -rf *.out *.o *~ $(OUT) docs #REPLACE THE SPACES AT THE BEGINNING OF LINE WITH A 'TAB'.


# ... or generate documentation (you must have a doxygen

# configuration file in the current directory):

docs:

	doxygen Doxyfile #REPLACE THE SPACES AT THE BEGINNING OF LINE WITH A 'TAB'.
