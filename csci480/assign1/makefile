#   Milo Zak
#   Z1917365
#   CSCI480
#
#   I certify that this is my own work and where appropriate an extension
#   of the starter code provided for the assignment.

# Variables
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11 -g

# Default target to build the executable
all: z1917365_project1

# Compiles the code to an executable
z1917365_project1: z1917365_project1.cpp
	$(CXX) $(CXXFLAGS) -o z1917365_project1 z1917365_project1.cpp

# Clean up object and executable files
clean:
	rm -f z1917365_project1 *.o

# Clean and rebuild the project
world: clean all
