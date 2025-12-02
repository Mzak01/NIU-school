/****************************************************************************
Title: simplesim.h

Course: CSCI241 Assign9

Programmer: Milo Zak(Z1917365)

Use: Holds the class definition for the simplesim program.
****************************************************************************/

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
