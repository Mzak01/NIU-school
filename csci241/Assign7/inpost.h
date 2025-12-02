/*************************************************************************
Title: inpost.h

Course: CSCI241 Assign7

Author: Milo Zak (z1917365) && Sebastian Lesny (z1868275)

Use: Contains the function prototype for convert() so that the main() can
     call it
*************************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>

#ifndef INPOST_H
#define INPOST_H

using namespace std;

//functions
string convert(const string& infix);
int postfix(char x);

#endif
