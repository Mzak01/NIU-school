/***************************************************************
CSCI 240         Program 8     Fall 2021

Programmer: Milo Zak, Sebastian Lesny

Section: CSCI 240

Date Due: Nov. 19, 2021

Purpose: For this assignment, implement and use the methods for
		 a class called Elevator.
***************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

/***************************************************************
Class: Elevator

Use: creates 2 elevator systems 

Arguments: currentfloor- stores current floor
		   topfloor- stores top floor of elevator
		   bottomfloor- stores lowest floor

Note: None
***************************************************************/
class Elevator
{
	//sets integers
	private:
		int currentfloor;
		static const int topfloor;
		static const int bottomfloor;
		
	//sets bottom to current floor
	public:
		Elevator()
		{
			currentfloor = bottomfloor;
		}
		
		Elevator(int floor)
		{
			if(floor >= bottomfloor && floor<= topfloor)
			currentfloor = floor;
			else
			currentfloor = bottomfloor;
		}
		
		/***************************************************************
		Function: void moveup
		
		Use: moves elevator up floors
		
		Arguments: higherfloor- stores higher floor to go to
		   		   i- floors as moves up
		   		   currentfloor- floor currently on
		
		returns: nothing

		Note: None
		***************************************************************/
		void moveup(int higherfloor)
		{
			int i;
			//shows starting floor
			cout<<"Starting at floor # "<<i<<endl;
			
			//going up to higherfloor
			for(i=currentfloor+1; i<higherfloor; i++)
			{
				cout<<"Going up--now at floor # "<<i<<endl;
			}
			cout<<"Now at floor # "<<i<<endl;
			currentfloor=i;
		}
		
		/***************************************************************
		Function: void movedown
		
		Use: moves elevator down floors
		
		Arguments: lowerfloor- stores lower floor to go to
		   		   i- floors as moves down
		   		   currentfloor- floor on
					  		
		returns: nothing

		Note: None
		***************************************************************/
		void movedown(int lowerfloor)
		{
			int i;
			//shows starting floor
			cout<<"Starting at floor # "<<i<<endl;
			
			//floor goes down
			for(i=currentfloor-1; i>lowerfloor;i--)
			{
				cout<<"Going down--now at floor # "<<i<<endl;
			}
			cout<<"Now at floor # "<<i<<endl;
			currentfloor=i;
		}
		
		/***************************************************************
		Function: void request
		
		Use: goes to floor requested
		
		Arguments: newfloor- floor requested
		
		returns: nothing

		Note: None
		***************************************************************/
		void request(int newfloor)
		{
			if(newfloor==13)
			{
				cout<<newfloor<<" Is an invalid floor number."<<endl<<endl;
				return;
			}
			if(newfloor<bottomfloor || newfloor>topfloor)
			{
				cout<<newfloor<<" Is an invalid floor number."<<endl<<endl;
				return;
			}
			if(newfloor==currentfloor)
			{
				cout<<"You are already on this floor."<<endl<<endl;
				return;
			}
			if(newfloor<currentfloor)
			{
				movedown(newfloor);
			}
			else
			{
				if(newfloor>currentfloor)
				{
					moveup(newfloor);
				}
			}
		}
		
		/***************************************************************
		Function: getcurrentfloor
		
		Use: gets current floor
		
		Arguments: currentfloor-floor currently on
		
		returns: floor on

		Note: None
		***************************************************************/
		int getcurrentfloor()
		{
			return currentfloor;
		}};
		
		//constants
		const int Elevator::topfloor = 20;
		const int Elevator::bottomfloor = 1;
		
	int main()
	{
		Elevator e1(1);

		Elevator e2(7);
			
		cout<<"The first Elevator object "<<endl<<endl;
		
		e1.request(11);
				
		e1.request(8);
		
		e1.request(8);
		
		e1.request(19);
		
		e1.request(2);
		
		cout<<endl<<"The second Elevator object "<<endl<<endl;
		
		e2.request(1);
		
		e2.request(13);
		
		e2.request(-5);
		
		e2.request(20);
		
		e2.request(25);
		
		cout<<endl<<"The 1st elevator is currently on "<<e1.getcurrentfloor()<<" floor";
		cout<<endl<<"The 2nd elevator is currently on "<<e2.getcurrentfloor()<<" floor";
	}
