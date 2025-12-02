/********************************************************************
Title: bank.cpp

Course: CSCI241 Assign 5

Writer: Milo Zak(z1917365) && Sebastian Lesny(1868275)

Use: Contains members for the bank class. Process transactions in
     accounts.
********************************************************************/

#include "bank.h"
#include "account.cpp"
#include <string>
#include <fstream>
#include <ostream>
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;
/********************************************************************
Class: binary_search()

Use: reads the account information.

Arguments: account array[] - array of information
	   int s - length of the file
	   search - what to search for
	   low = low end of array
	   high = high end of array
	   mid = middle of the array

Return: -1 :/
********************************************************************/
int bank::binary_search(account array[], int s, char* search)
{
	//declaring variables
	int low = 0;
	int high = s - 1;

	while (low <= high)
        {
        	//mid
       		int mid = (low + high) / 2;

            	//Compare the two account numbers for equality
            	if (strcmp(search, array[mid].get_account_num()) == 0)
            	{
                	return mid;
		}
        	//compares to see if a number is kess (want equality here)
        	if (strcmp(search, array[mid].get_account_num()) < 0)
                {
            		high = mid - 1;
        	}
                else
                {

	        	low = mid + 1;
	        }
       }
       return -1;
}

/********************************************************************
Class: bank()

Use: creates the default constructor for bank. This initizalizes the
     banks information before anything is opened.

Arguments: bankname - initalizes the name of the bank
           valid - sets the number of array elements with valid data
                   to zero. Stating nothing has opened yet.

Return: none
********************************************************************/
bank::bank()
{
    strcpy(bankname, "None");
    valid = 0;
}

/********************************************************************
Class: read_account(string)

Use: reads the account information and sorts it into numeroligical
     order for account numbers. (least to most)

Arguments: readfile - string to get the function to read :)
           file - file it is currently reading from
           bank - array of the bank
           valid - number of valid elements within the array
           accounts - array of different account numbers
           int array[] - array of numbers
           int n - amount of variables within the array
           int i - variable holder of a single number
           int j - variable hold of a single number
           int min_index - holds the minimum value
           account temp - temporarily holds account information
                          as it being swapped around

Return: none
********************************************************************/
void bank::read_accounts(string fileread)
{
	//declaring variables
        int j;
        int min_index;
        int i;
        account temp;

	ifstream file;

	file.open(fileread);


    	if (!file)
    	{
        	cerr << "***Unable to open input file***" << fileread << endl;
        	exit(1);
    	}

        // Read the next bank object in the file.
    	while (file.read((char*) this, sizeof(bank))) 
        {

                valid++;

    	}

	//close
    	file.close();

	//selection sort
        i = 0;

        //starts the sorting process
        //i has to be less than the number of n elements.
        //will increase through n from there.
        while( i < valid - 1)
        {
                min_index = i;
                j = i + 1;

                while( j < valid )
                {

                        //Checks through two accounts to see which account number is less
                        if (strcmp(accounts[j].get_account_num(), accounts[min_index].get_account_num()) < 0)
                        min_index = j;

                j = j + 1;

        }

        //Swap the elements
        temp = accounts[i];
        accounts[i] = accounts[min_index];
        accounts[min_index] = temp;
        i = i + 1;

    }

}

/********************************************************************
Class: process_transactions(string)

Use: processes the transations made for the accounts.

Arguments: date[6] - prints the date
	   account_number - array holding the account number
	   type - type of transaction
	   amount - amount beinf added or subtracted
	   element - index where account is found
	   success - checks is withdraw is good

Return: none
********************************************************************/

void bank::process_transactions(string processfile)
{
	//coding object :)
	ifstream file;

	//variables (see argument for explanation)
    	char date[6];
    	char account_number[11];
    	char type[2];
    	double amount;
    	int element;
    	bool success;

    	file.open(processfile);

	//if file doesnt open
    	if (!file)
    	{
        	cerr << "***Unable to open input file***" << processfile << endl;
        	exit(1);

    	}

	//setting up the transaction list
    	cout << "Transaction Report\n\n";
    	cout << "Date\t" << "Account\t\t" << "Type\t" << "Amount\t" << "New Balance\t" << endl << endl;

	//make setprecision for balances
    	cout << right << setprecision(2) << fixed;

    	//Reading data into the files
    	while (file >> date)
       	{

        	file >> account_number;
        	file >> type;
        	file >> amount;


	        element = binary_search(accounts, valid, account_number);

        	if (element != -1)
                {

            		//add money to the account and print new balance
                        if (strcmp(type, "D") == 0)
                        {

                                accounts[element].process_deposit(amount);

                                cout << date << "\t" << account_number << "\t" << type 
                                     << "\t" << amount << "\t" << accounts[element].get_balance() << endl;

                        }

                        //If it is a withdrawal take money out
                        if (strcmp(type, "W") == 0)
                        {

                                success = accounts[element].process_withdrawal(amount);
                                //not successful then print out error
                                //is successful then print new account balance
                                if (success == false)
                                {

                                        cout << date << "\t" << account_number << "\t" << type 
                                             << "\t" << amount << "\t" << "*** Insufficient funds ***" << endl;

                                }
                                else
                                {

                                        cout << date << "\t" << account_number << "\t" << type 
                                             << "\t" << amount << "\t" << accounts[element].get_balance() << endl;

                                }

                        }
		}
                else
                {

                        //If an account was not found error
                        cout << date << "\t" << account_number << "\t" << type 
                             << "\t" << amount << "\t" << "*** Invalid account number ***" << endl;

                }


       }

       file.close();

       cout << endl;

}

/********************************************************************
Class: print()

Use: Prints all the account information and transactions.

Arguments: int i - used to create a loop checking the printing process
           int valid - valid elements of a bank account
           account[].print - calls print function from account class
                             to properky print the answer.

Return: none
********************************************************************/
void bank::print()
{

    cout << "Account Listing for "<<bankname << endl << endl;

    for (int i = 0; i < valid - 1; i++)
        {

                accounts[i].print();

    	}
}
