/********************************************************************
Title: account.h

Course: CSCI241 Assign 5

Writer: Milo Zak(z1917365) && Sebastian Lesny(1868275)

Use: Contains class definition for "account" which represents
     information about one's bank account.
********************************************************************/

#include <iostream>
#include <iomanip>

#ifndef ACCOUNT_H
#define ACCOUNT_H

class account
{
   private:

	char accountnum[11];
	char custname[21];
	double accountbal;

   public:

   	account();
   	char* get_account_num();
   	double get_balance();
   	void process_deposit(double);
   	bool process_withdrawal(double);
   	void print();
};

#endif
