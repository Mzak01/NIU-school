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
all: hash

#compiles the code to an object
hash: entry.h hashmain.cc hashmain.h htable.cc htable.h
	g++ $(CXXFLAGS) -o hash htable.cc hashmain.cc

#remove object code and exe files
clean:
	rm -f hash test *.o

world: clean all
