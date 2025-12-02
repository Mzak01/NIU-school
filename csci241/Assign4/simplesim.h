/*********************************************************************
Title: simplesim.h

Course: CSCI241 Assign 4

Author: Milo Zak(z1917365) && Sebastian Lesny(z1868275)

Use: This header file should contain the class definition for a
     class called simplesim. This class definition should contain
     the private data members described below under 7. Simulating
     the Simplesim. It should also contain public declarations
     (i.e., prototypes) for the four member functions whose
     definitions are contained in simplesim.cpp.
*********************************************************************/

#ifndef SIMPLESIM_H
#define SIMPLESIM_H

class simplesim
{
private:
    // Simplesim memory.
    int memory[100];

    // Simplesim registers.
    int accumulator = 0;
    int instruction_counter = 0;
    int instruction_register = 0;
    int operation_code = 0;
    int operand = 0;

public:

    simplesim();
    bool load_program();
    void execute_program();
    void dump() const;
};

#endif
