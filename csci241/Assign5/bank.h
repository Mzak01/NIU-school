/********************************************************************
Title: bank.h

Course: CSCI241 Assign 5

Writer: Milo Zak(z1917365) && Sebastian Lesny(1868275)

Use: Contains class definition for bank, representing the information
     about bank accounts.
********************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "account.h"

#ifndef BANK_H
#define BANK_H

using namespace std;
class bank
{
private:
	char bankname[31];
	account accounts[20];
	int valid;
public:
	bank();
	void read_accounts(std::string accountsfile);
	void process_transactions(std::string transactionfile);
	void print();
	int binary_search(account*, int, char*);

};

#endif
