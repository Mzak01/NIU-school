/***************************************************************
CSCI 240         Program 3     Fall 2021

Programmer: Milo Zak, Sebastian Lesny

Section: CSCI 240

Date Due: Sept. 17, 2021

Purpose: This program will write a program that will calculate
		 the quiz and test portion of a student's CSCI 240 grade. 
		 This is to learn to code decision statements.
***************************************************************/

	#include <iostream>
	#include <iomanip>
	
	using namespace std;
	int main () {
		
		//Variables
		
		int TESTPOINTSEARNED,
		    TESTPOINTSAVAIL,
		    QUIZZESTAKEN,
			QUIZPOINTSEARNED,
			SUMLOWQUIZZES;
			
		float TQAVG;
			  
		//input system for test points earned and check
		
		cout << "How many test points were earned?";
		cin >> TESTPOINTSEARNED;
		
		if(TESTPOINTSEARNED < 0) 	
		{
			cout <<endl<< "***ERROR: Test points earned cannot be negative. Try again"<<endl;
			cout << "How many test points were earned?";
			cin >> TESTPOINTSEARNED;
		}
		
		// test points available input and check
		
		cout << "How many test points were available?";
		cin >> TESTPOINTSAVAIL;
		
		if (TESTPOINTSAVAIL < 0 )
		{
			cout <<endl<< "***ERROR: Test points available cannot be negative. Try again."<<endl;
			cout << "How many test points were available?";
			cin >> TESTPOINTSAVAIL;
			
		if (TESTPOINTSAVAIL < TESTPOINTSEARNED)
		
			cout <<endl<< "***ERROR: Earned points cannot exceed points available. Try again."<<endl;
			cout << "How many test points were available?";
			cin >> TESTPOINTSAVAIL;
		}
		
		//input system for amount of quizzes taken and checks
		
		cout << "How many quizzes were taken?";
		cin >> QUIZZESTAKEN;
		
		if (QUIZZESTAKEN < 0)
		{
			cout <<endl<< "***ERROR: Quizzes taken cannot be a negative. Try again."<<endl;
			cout << "How many quizzes were taken?";
			cin >> QUIZZESTAKEN;
		
		if (QUIZZESTAKEN > 12)
		
			cout <<endl<< "***ERROR: There should be no more then 12 quizzes taken. Try again"<<endl;
			cout << "How many quizzes were taken?";
			cin >> QUIZZESTAKEN;
		}
		
		//input system for quiz points earned and checks
		
		cout << "How many quiz points were earned?";
		cin >> QUIZPOINTSEARNED;
		
		if (QUIZPOINTSEARNED > 10 * QUIZZESTAKEN)
		{
			cout <<endl<< "***ERROR: Quiz points earned cannot exceed " << 10 * QUIZZESTAKEN <<" points. Try again."<<endl;
			cout << "How many quiz points were earned?";
			cin >> QUIZPOINTSEARNED;
		}
		
		//input system if user has taken more then two quizzes and checks
		
		if (QUIZZESTAKEN > 2)
		{
			cout<< "What is the sum of the two lowest quiz scores?"<<endl;
			cin >> SUMLOWQUIZZES;
		if (SUMLOWQUIZZES > 20)
		{
			cout<<endl<< "***ERROR: The sum of the lowest quiz scores cannot be greater then 20."<<endl;
			cout<<endl<< "What is the sum of the two lowest quiz scores?"<<endl;
			cin >> SUMLOWQUIZZES;
		}}

		//math for averages
		
		if (QUIZZESTAKEN <= 2)
		{
			TQAVG = (TESTPOINTSEARNED + QUIZPOINTSEARNED) / ((10.00 * QUIZZESTAKEN) + TESTPOINTSAVAIL) * 100.00;
			cout<<endl<<fixed<<setprecision(2)<<"Test/Quiz Average:"<<TQAVG;
		}
		
		if (QUIZZESTAKEN > 2)
		{
			TQAVG = (TESTPOINTSEARNED + QUIZPOINTSEARNED - SUMLOWQUIZZES) / (TESTPOINTSAVAIL + (10.0 * (QUIZZESTAKEN - 2.0))) * 100.0;
			cout<<endl<<fixed<<setprecision(2)<<"Test/Quiz Average:"<<TQAVG;
		}
		
	return 0;
	}
	
