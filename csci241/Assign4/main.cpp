/*********************************************************************
Title: main.cpp

Class: CSCI 242 Assign 4

Author: Milo Zak(z1917365) && Sebastian Lesny(z1868275)

Use: Attempts to load and execute an SML program and then dumps the
     contents of the Simplesim's registers and memory. (Returns 0)

*********************************************************************/

#include <iostream>
#include <iomanip>
#include "simplesim.h"
#include "sml.h"

using namespace std;

int main()
{

    simplesim s;

    if (s.load_program())
        s.execute_program();

    s.dump();

    return 0;
}
