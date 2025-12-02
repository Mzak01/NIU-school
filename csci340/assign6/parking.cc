/*
 	Milo zak
	z1917365
	csci340-3

	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/

#include <bits/stdc++.h>
#include "garage.h"
#include "car.h"

using namespace std;

void get_input_vals(const std::string &line, char &xact_type, std::string &license);

int main()
{
    std::string line;
    std::string license_num;
    garage movement;
    char xact_type;


    while(getline(cin, line, '\n')) //getting line input
    {
        get_input_vals(line, xact_type, license_num); //gets val type to find arrive or depart

        if(xact_type == 'A')
        {
            movement.arrival(license_num);
        }
        else if(xact_type == 'D')
        {
            movement.departure(license_num);
        }
        else
        {
            std::cout << "'" << xact_type << "': invalid action!\n\n";
        }
    }
    return 0;
}

/*
Func: void get_input_vals(const std::string, char, std::string);

Arg: extracts the individual components from the input line line,
     where act indicates if the line corresponds to an arrival
     or a departure event, and license is the license plate number
     of the arriving/departing car.

Ret: noen
*/
void get_input_vals(const std::string &line, char &xact_type, std::string &license)
{
    if(line[0] == 'A')
    {
        xact_type = 'A';
    }
    else if(line[0] == 'D')
    {
        xact_type = 'D';
    }
    else
    {
        xact_type = line[0];
    }
    license = line.substr(2, line.length() - 3);
}
