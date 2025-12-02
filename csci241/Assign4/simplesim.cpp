/********************************************************************
Title: simplesim.cpp
Course: Csci 241-1
Assignment: Assign 4
Author: Milo Zak(z1917365) && Sebastian Lesny(z1868275)
Use: This file contains the function definitions for simplesim, load
     execute, and dump. This turns the simpletron on and tells it
     how to execute programs to talk.
********************************************************************/

#include <iostream>
#include <iomanip>
#include "simplesim.h"		//includes header files
#include "sml.h"		//includes header files

using namespace std;

/***************************************************************
class: simplesim ::simplesim

Variables: int i = 0 --> makes the loop to initalize
            memory[100] --> array of words

Use: Initializes the Simplesim's memory to default values.
****************************************************************/
simplesim::simplesim()
{
	for(int i = 0; i < 100; i++)
	{
		//initalizing to 7777
		memory[i] = 7777;
	}
}

/*******************************************************************
 Class: simplesim::load_program()

 Variables: count --> counter for the instructions
 	    instruction ->> instruction which the code is given

 Use: Loads an SML program into the Simplesim's memory.

 Return: Returns true if a valid program is successfully loaded into
         memory; otherwise, false.
 ******************************************************************/
bool simplesim::load_program()
{
	int count = 0;
	int instruction = 0;

	//takes in instruction
	cin >> instruction;
        while (instruction != -99999)
	{
        	// Check for invalid word.
        	if(instruction >= 9999 || instruction <= -9999)
        	{
        		cout<<"\n***ABEND: pgm load: invalid word***\n\n";

        		return false;
		}
        	// Check for too large program.
		if(count >= 100)
		{
			cout<<"\n***ABEND: pgm load: pgm too large***\n\n";

			return false;
		}
        	// Add instruction to memory.
		memory[count] = instruction;

		cin>>instruction;
        	// Increment instruction count.
        	count++;
	}
	//return true means it goes to execute program
	return true;
}
/****************************************************************
Class: simplesim::execute_program()

Variables: temporary --> temp place holder
	   done --> says if the program is finished and to end
	   	    the execution

Use: Executes an SML program loaded into the Simplesim's memory.
 ****************************************************************/
void simplesim::execute_program()
{

	int temporary;
	bool done = false;

	//loop to get instructions
	while (!done)
	{
        	// Check for addressability error.
		if(instruction_counter >= 0 && instruction_counter <= 99)
		{
 	        	// Fetch instruction
        		instruction_register = memory[instruction_counter];
				operation_code = instruction_register / 100;
				operand = instruction_register % 100;
		}
		else
		{
			cout<<"***ABEND: Addressability Error***\n";
			done = true;
		}

	        // Execute instruction.
		switch (operation_code)
		{
			//defines code for reads
			case READ:
			while(cin>>memory[operand])
			{
				if (memory[operand] < -9999 || memory[operand] > 9999)
				{
					memory[operand] = 0;
					cout<<"***ABEND: Illegal Input***\n\n";
					done = true;
				}
				else
				{
					cout<<setfill('0');
					cout<<"Read: "<<showpos<<setw(5)<<internal<<memory[operand]<<endl;
				}
			}
              	        break;


			//has code print answers
        		case WRITE:
        		cout<<setfill('0');
        		cout<<showpos<<setw(5)<<internal<<memory[operand]<<endl;
           	        break;

			//has code store answers
           		case STORE:
           		memory[operand] = accumulator;
           		break;

			//has code load the things
           		case LOAD:
           		accumulator = memory[operand];
           		break;


			//Does addition and looks for error :0
           		case ADD:
           		temporary = accumulator + memory[operand];
           		if (temporary < -9999)
           		{
           			cout<<"***ABEND: Underflow***\n\n";
           			done = true;
           		}
           		else if (temporary > 9999)
           		{
           			cout<<"***ABEND: Overflow***\n\n";
           			done = true;
           		}
           		else
           		{
           			accumulator = temporary;
           		}
           		break;

			//does subtraction and error check :0
           		case SUBTRACT:

           		temporary = accumulator - memory[operand];
           		if (accumulator < -9999)
                        {
                                cout<<"***ABEND: Underflow***\n\n";
                                return;
                        }
                        else if (accumulator > 9999)
                        {
                                cout<<"***ABEND: Overflow***\n\n";
                                return;
                        }
                        else
                        {
                        	accumulator = temporary;
                        }
           		break;

			//does multiplication and error check :0
           		case MULTIPLY:
           		temporary = accumulator * memory[operand];
           		if (temporary < -9999)
                        {
                                cout<<"***ABEND: Underflow***\n\n";
                                done = true;
                        }
                        else if (temporary > 9999)
                        {
                                cout<<"***ABEND: Overflow***\n\n";
                                done = true;
                        }
                        else
                        {
                                accumulator = temporary;
                        }
           		break;

			//does division and error check :0
           		case DIVIDE:
           		if(memory[operand] == 0)
           		{
           			cout<<"***ABEND: Attempted Division By Zero***\n\n";
           			return;
           		}
           		else
           		{
           			temporary = accumulator / memory[operand];
           		}

           		if(accumulator < -9999)
           		{
           			cout<<"***ABEND: Underflow***\n\n";
           			return;
           		}
           		if(accumulator < 9999)
           		{
           			cout<<"***ABEND: Overflow***\n\n";
           		}
           		else
           		{
           			temporary = accumulator;
			}
                   	break;

			//looks at the branching of the code
          		case BRANCH:
          		instruction_counter = operand;
           		break;

			//tests to see if the branch is zero
           		case BRACHZERO:
           		if(accumulator == 0)
           		{
           			instruction_counter = operand;
           		}
           		else
           		{
           		instruction_counter++;
           		}
           		break;

			//test to see if the branch is negative
           		case BRANCHNEG:
           		if(accumulator < 0)
           		{
           			instruction_counter = operand;
           		}
           		else
           		{
           			instruction_counter++;
           		}
           		break;

			//look into halt and the end of the program :)
           		case HALT:
                        cout<<"***Simplesim execution terminated***\n\n";
			done = true;
                        break;

        		default:
            	   	cout << "*** ABEND: invalid opcode ***\n\n";
            		done = true;
        	}

		// Increment instruction counter if needed.
		if(operation_code != BRANCH && operation_code != BRACHZERO && operation_code != BRANCHNEG && operation_code != HALT && !done)
		{
			instruction_counter++;
		}
    	}
}
/*****************************************************************
Class: simplesim::dump()

Variables: row --> inputs the rows into the dump
	   totalval --> total value of the variables

Use: Prints the contents of the Simplesim's registers and memory.
 *****************************************************************/
void simplesim::dump() const
{
	int row;
	int totalval = 0;

	// Print registers.
	cout<<"REGISTERS: \n";
	cout<<"accumulator:		"<<showpos<<setfill('0')<<setw(5)<<internal<<accumulator<<noshowpos<<setfill(' ')<<endl;
	cout<<"instruction_counter:	"<<setfill('0')<<right<<setw(2)<<instruction_counter<<setfill(' ')<<endl;
	cout<<"instruction_register: 	"<<showpos<<setfill('0')<<internal<<setw(5)<<instruction_register<<noshowpos<<setfill(' ')<<endl;
	cout<<"operation_code:	        "<<setfill('0')<<right<<setw(2)<<operation_code<<setfill(' ')<<endl;
	cout<<"operand:		"<<setfill('0')<<right<<setw(2)<<operand<<setfill(' ')<<endl;

	// Print memory.
	cout<<"\nMEMORY: \n";

        for(row = 0; row < 10; row++)
        {

                cout<<noshowpos;

                if(row == 0)
                {
                        cout<<setw(8)<<row;
                }
                else
                {
                        cout<<setw(7)<<row;
                }
        }

        cout<<"\n";

	//checks to see if there are errors in dumping
	bool start = true;

	for(totalval = 0; totalval < 100; totalval++)
	{
		setfill(' ');
		if(start == true)
		{
			cout<<setw(2)<<right<<noshowpos<<setfill(' ')<<totalval;

			start = false;
		}

		cout<<" "<<right<<setw(5)<<internal<<showpos<<setfill('0')<<memory[totalval]<<" ";

		if((totalval+1) % 10 == 0)
		{
			cout<<" "<<endl;
			start = true;
		}
	}
}

