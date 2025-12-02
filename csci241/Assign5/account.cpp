/********************************************************************
Title: account.cpp

Course: CSCI241 Assign 5

Writer: Milo Zak(z1917365) && Sebastian Lesny(1868275)

Use: contains member functions for the account class labeled in
     account.h. Shows account listings for First National Bank
********************************************************************/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "account.h"

using namespace std;
/********************************************************************
Class: account()

Use: creates the default constructor for accounts. Sets everything
     to zero so the files can be pulled from there.

Arguments: accountnum - number of account
	   custname - name which account is under
	   accountbal - balance of the accounts

Return: none
********************************************************************/
account::account()
{

	//starting by having no account open
	strcpy(accountnum, "None");
	strcpy(custname, "None");
	accountbal = 0.00;

}
/********************************************************************
Class: get_account_num()

Use: Retrieves the number associated with the account

Arguments: accountnum - unique number of the account

Return: returns account number
********************************************************************/
char* account::get_account_num()
{

	return accountnum;

}
/********************************************************************
Class: get_balance()

Use: retrieves balance for account.

Arguments: accountbal - balance of the account

Return: account balance
********************************************************************/
double account::get_balance()
{

	return accountbal;

}
/********************************************************************
Class: process_deposit(double)

Use: This will take a deposit amount and add it to the balance of the
     bank account.

Arguments: accountbal - balance of account
	   depositnum - amount being deposited

Return: none
********************************************************************/
void account::process_deposit(double depositnum)
{
	//adds the deposit ammount to the current
	//balance of the account.
	accountbal = accountbal + depositnum;

}
/********************************************************************
Class: process_withdrawal(double)

Use: This will take a withdrawal amount and subtract it from the
     existing balance in the account as long as they have sufficient
     funds.

Arguments: accountbal - balance of the account
	   withdrawalnum - ammount being withdrawed from account

Return: returns true or false (dependent on if they have money)
********************************************************************/
bool account::process_withdrawal(double withdrawalnum)
{
	//creates error when there is not
	//enough funds in the account.
	if(accountbal < withdrawalnum)
	{
		cout<<"*** Insufficient funds ***"<<endl;
		return false;
	}
	//if the account bal is >= then
	//the withdrawal will occur
	else
	{
		accountbal = accountbal - withdrawalnum;
		return true;
	}
}
/********************************************************************
Class: print()

Use: This will print the data from the account in a specific format.

Arguments:

Return: none
********************************************************************/
void account::print()
{
	cout<<"Account Number: "<<accountnum<<endl;
	cout<<"Name: "<<custname<<endl;
	cout<<"Balance: $"<<fixed<<setprecision(2)<<accountbal<<endl;
}
