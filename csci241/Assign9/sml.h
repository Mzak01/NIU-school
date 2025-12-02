/***************************************************************************
Title: sml.h

Course: CSCI241 Assign9

Programmer: Milo Zak (z1917365)

Use: this is a header file containing the #define statements that define
     the Simplesim's instruction set
**************************************************************************/


#ifndef SML_H
#define SML_H

//input && output operations

#define READ 11
#define WRITE 12

//store && load operations

#define STORE 21
#define LOAD 22

//Arithmetic operations

#define ADD 31
#define SUBTRACT 32
#define MULTIPLY 33
#define DIVIDE 34

//transfer of control operations

#define BRANCH 41
#define BRANCHZERO 42
#define BRANCHNEG 43
#define HALT 44

#endif
