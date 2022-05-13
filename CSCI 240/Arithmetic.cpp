/***************************************************************
CSCI 240         Program 1     Fall 2021

Programmer: Milo Zak

Section: CSCI 240

Date Due: Sept. 3, 2021

Purpose: This program performs simple arithmetic calculations and
         displays the results.
***************************************************************/

#include <iostream> 
#include <iomanip>

using namespace std;
int main () {
	
   int num1 = 7;
   int num2 = 2;
   int result;
	
	//using addition
   result = num1 + num2;
   cout << "7 + 2 = " << result << endl;
   
   //using subtraction
   result = num1 - num2;
   cout << "7 - 2 = " << result << endl;
   
   //using multiplication
   result = num1 * num2;
   cout << "7 * 2 = " << result << endl;
   
   //using division
   result = num1 / num2;
   cout << "7 / 2 = " << result << endl;
   
   //using modulus
   result = num1 % num2;
   cout << "7 % 2 = " << result << endl;
   
   //using substraction, but variables are switched
   result = num2 - num1;
   cout << "2 - 7 = " << result << endl;
   
   //using division but variables are switched
   result = num2 / num1;
   cout << "2 / 7 = " << result << endl;
   
   
   //using modulus but variables are switched
   result = num2 % num1;
   cout << "2 % 7 = " << result << endl;
   
   return 0;
}

