/***************************************************************************
Title: inpost.h

Course: CSCI241 Assign8

Programmer: Milo Zak (z1917365) && Sebastian Lesny (z1868275)

Use: contains function prototype for convert()
****************************************************************************/

#include <iostream>
#include <iomanip>

#ifndef INPOST_H
#define INPOST_H

using namespace std;


string convert(const string& infix);
int prec(char x);

#endif
