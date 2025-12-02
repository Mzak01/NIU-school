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
all: parking

#compiles the code to an object
josephus: parking.cc car.h garage.h
	g++ $(CXXFLAGS) -o parking parking.cc

#remove object code and exe files
clean:
	rm -f parking test *.o

world: clean all
