/*************************************************************************
Title: main.cpp

Couse: csci241 Assign5

Code: Milo Zak (z1917365) && Sebastian Lesny (1868275)

Use: compiles everything with main
*************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <ostream>
#include "bank.h"
#include "bank.cpp"

using namespace std;

int main(int argc, const char * argv[])
{

	//object
        bank FirstNational = bank();
        cout << endl;

	//reads
    	FirstNational.read_accounts("accounts");

	//prints reads
    	FirstNational.print();

	//does transactions
    	FirstNational.process_transactions("transactions.txt");

	//print
    	FirstNational.print();
    	return 0;
}
