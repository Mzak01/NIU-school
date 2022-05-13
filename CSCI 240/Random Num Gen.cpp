/***************************************************************
CSCI 240         Program 4    Fall 2021

Programmer: Milo Zak

Section: CSCI 240

Date Due: Sept. 24, 2021

Purpose: This prgram will generate three sets of random numbers.
***************************************************************/


	
	#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
	double price = 1;							//stores the starting price
	double yearInt = 1;							//stores the yearly interest
	double monthInt; 							//will store monthly interest once yearly interest is added
	double payment = 1;							//stores how much is paid per month
	double month = 1;							//month counter
	double paidInt;								//displays how much interest was paid
	double paidPrice;							//displays how much of loan was paid off after interest
	double balance	;							//displays balance after payment is made
	double remBalance;
	{
		cout << "Please enter the dollar amount of the loan: $";
		cin >> price;
		cout << "Please enter the yearly rate of interest: ";
		cin >> yearInt;
		cout << "Please enter the monthly payment made: $";
		cin >> payment;
		cout << "Month	Principle	Interest Paid	Principle Paid	Remaining Balance" <<endl;
		cout << fixed << setprecision(2);
		balance = price;
		monthInt = yearInt / 1200;
		while (balance > 0)
		{
			month++;
			paidInt = balance * monthInt;
			paidPrice = payment - paidInt;
			remBalance = balance - paidPrice;

			cout << month << setw(6) << " "<< balance << setw(6)<< " "<< paidInt << setw(6) << " "<< paidPrice << setw(6) << " "<< remBalance << endl;
			balance = remBalance;
		}
		cout << "Number of months to pay off loan: " << month << endl;
		cout << "Total interest paid on loan: " << endl;
		cout << "You have a credit of: " << remBalance << endl;
	}
	return 0;
}
	

