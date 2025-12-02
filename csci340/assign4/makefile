#   Milo Zak
#   Z1917365
#   CSCI340-3
#
#   I certify that this is my own work and where appropriate an extension 
#   of the starter code provided for the assignment.

#variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11 -g

#links everything to exe file
all: stack

#compiles the code to an object
stack: rational.h stack.h rational.cc main.cc
	g++ $(CXXFLAGS) -o stack rational.cc main.cc

#remove object code and exe files
clean:
	rm -f stack test *.o

world: clean all
