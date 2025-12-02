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
all: simplegraph

#compiles the code to an object
simplegraph: graph.h graph.cc simplegraph.cc
	g++ $(CXXFLAGS) -o simplegraph graph.cc simplegraph.cc

#remove object code and exe files
clean:
	rm -f simplegraph test *.o

world: clean all
