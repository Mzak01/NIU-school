/*
 	Milo zak
	z1917365
	csci340-3

	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/

#include "josephus.h"

#include <list>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <getopt.h>


void print_underlined_string(const std::string &message);
void print_list(const std::list<std::string> &collection, const unsigned &eliminations, int num_cols);


/**
* Print a 'Usage' message and exit(1).
*
* @param a0 The name of the command to include in the usage message.
*****************************************************************************/
static void usage(const char *a0)
{
    std::cerr << "Usage: " << a0 << " [-n number of people] [-m modulus] [-p print frequency] [-c print columns]" << std::endl;
    exit(1);
}


/**
* Create a std::list of people with generated ID/names and reduce the
* list as per the Josephus problem algorithm.
*****************************************************************************/
int main(int argc, char **argv)
{
    unsigned num_people = 41;       // The number of people to start with
    unsigned modulus = 3;           // The count used to determine the elimination
    unsigned print_frequency = 13;  // How often to print the state of the system
    unsigned num_cols = 12;         // Number of colums to print per line
    unsigned int counter = 1;
    int eliminated = 0;

    int opt;
    while ((opt = getopt(argc, argv, "n:m:p:c:")) != -1)
    {
        switch (opt)
        {
        case 'n':
            std::istringstream(optarg) >> num_people;
            break;
        case 'm':
            std::istringstream(optarg) >> modulus;
            break;
        case 'p':
            std::istringstream(optarg) >> print_frequency;
            break;
        case 'c':
            std::istringstream(optarg) >> num_cols;
            break;
        default:
            usage(argv[0]);
        }
    }

    if (optind < argc)
        usage(argv[0]); // If we get here, there was extra junk on command line

    //add code below
    std::list<std::string> new_list;
    auto it = new_list.begin();

    generate_n(back_inserter(new_list), num_people, SEQ(num_people));
    print_list(new_list, 0, num_cols);

    while(new_list.size() > 1)
    {
        while(counter < modulus)
        {
            counter++;
            it++;

            if(it == new_list.end())
            {
                it = new_list.begin();
            }
        }

        it = new_list.erase(it);
        ++eliminated;

        if(it == new_list.end())
        {
            it = new_list.begin();
        }
        else if(eliminated % print_frequency == 0)
        {
            print_list(new_list, eliminated, num_cols);
        }
    }
    std::cout<<"Eliminations Completed"<<std::endl;
    print_list(new_list, eliminated, num_cols);

  return 0;
}

/*
Func: void print_underlined_string(const string &message)

Arg: Print the given message with an underline that matches
     the length of the message text.

Ret: none
*/

void print_underlined_string(const std::string &message)
{
    std::cout<<message;
    std::cout<<std::endl<<std::string(message.length(), char('-'))<<std::endl;
}


/*
Func: void print_list(const list<string> &collection, const unsigned &eliminations, int num_cols)

Arg: Print a heading including the number of eliminations and the
     contents of collection with num_cols elements on each line

Ret: none
*/
void print_list(const std::list<std::string> &collection, const unsigned &eliminations, int num_cols)
{
    int counter = 0;

    //prints different headers by calling print_underlined_string
    if(eliminations == 0)
    {
        print_underlined_string("Initial group of people");
    }
    else
    {
        std::string post_elim = "After elimination " + std::to_string(eliminations) + std::string(" people");
        print_underlined_string(post_elim);
    }

    //iterates to place commas and find each row
    for(auto it = collection.begin(); it != collection.end(); ++it)
    {
        if(counter != num_cols && counter != 0)
        {
            std::cout<<", ";
        }
        //if equal create new row
        else if(counter == num_cols)
        {
            std::cout<<std::endl;
            counter = 0;
        }
    }
    std::cout<<std::endl<<std::endl;
}
