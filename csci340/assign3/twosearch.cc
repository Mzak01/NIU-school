/*
    Milo Zak
	Z1917365
	CSCI340-3

	I certify that this is my own work and where appropriate an extension
	of the starter code provided for the assignment.
*/

#include "twosearch.h"

#include <getopt.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

/**
* see: 
* https://en.wikipedia.org/wiki/Usage_message
* https://www.ibm.com/docs/en/aix/7.2?topic=commands-usage-statements
*
* @param a0 The value of argv[0] (the name of the command) so that it 
*   can be printed.
*
* @note This function will terminate the application via exit(1).
******************************************************************************/
static void usage(const char *a0)
{
    std::cerr << "Usage: " << a0 << " [-l rand_low] [-h rand_high] [-a a_size] [-b b_size] [-x a_seed] [-y b_seed] [-c print_cols] [-w col_width]" << std::endl;
    std::cerr << "    rand_low   = rand() low bound (default=1)" << std::endl;
    std::cerr << "    rand_high  = rand() high bound (default=1000)" << std::endl;
    std::cerr << "    a_size     = size of vector A (default=200)" << std::endl;
    std::cerr << "    b_size     = size of vector B (default=100)" << std::endl;
    std::cerr << "    a_seed     = random seed for vector A (default=1)" << std::endl;
    std::cerr << "    b_seed     = random seed for vector B (default=3)" << std::endl;
    std::cerr << "    print_cols = number of colums per line (default=16)" << std::endl;
    std::cerr << "    col_width  = printed column value width (default=4)" << std::endl;
    exit(1);
} // End of usage()

/**
* Parse the command-line args, create and sort vector A, create vector B,
* search vector A for those elements appearing in vector B using both
* a linear and binary search, and print the hit-rate (the percentage of 
* items in B that have been located in A.)
*
* If an invalid command-line arg is encountered, print a Usage statement 
* and terminte with an exit-status of 1.
*
* @return zero
******************************************************************************/
int main(int argc, char **argv)
{
    // Demonstrate the use of getopt() to override default config parameters 
    int rand_low = 1;
    int rand_high = 1000;
    int a_size = 200;
    int b_size = 100;
    int a_seed = 1;
    int b_seed = 3;
    int print_cols = 16;
    int col_width = 4;

    int opt;
    // see: http://faculty.cs.niu.edu/~winans/CS340/2022-sp/#getopt
    while ((opt = getopt(argc, argv, "a:b:c:h:l:w:x:y:")) != -1)
    {
        switch(opt)
        {
        case 'a':
            // see https://en.cppreference.com/w/cpp/string/basic_string/stol
            a_size = std::stoi(optarg); // override the default for a_size
            break;

        case 'b':
            b_size = std::stoi(optarg);
            break;
        case 'c':
            print_cols = std::stoi(optarg);
            break;
        case 'h':
            rand_high = std::stoi(optarg);
            break;
        case 'l':
            rand_low = std::stoi(optarg);
            break;
        case 'w':
            col_width = std::stoi(optarg);
            break;
        case 'x':
            a_seed = std::stoi(optarg);
            break;
        case 'y':
            b_seed = std::stoi(optarg);
            break;

        default:
            // got an arg that is not recognized...
            usage(argv[0]);     // pass the name of the program so it can print it
        }
    }

    // Make sure there are not any more arguments (after the optional ones)
    if (optind < argc)
        usage(argv[0]);

    // Add application logic here...

    int found = 0;
    typedef std::vector<int> container;

    container A(a_size);
    container B(b_size);

    init_vector(A, a_seed, rand_low, rand_high);
    init_vector(B, b_seed, rand_low, rand_high);

    std::cout<< "A vector: "<< std::endl;
    print_vector(A, print_cols, col_width);

    sort_vector(A);

    std::cout<<"A vector sorted: "<<std::endl;
    print_vector(A, print_cols, col_width);

    std::cout<<"B vector:"<<std::endl;
    print_vector(B, print_cols, col_width);

    found = search_vector(A, B, linear_search);


    std::cout << "Linear Search: Percent of Successful Searches = ";
    print_stat( found, B.size());

    found = search_vector(A, B, binary_search);

    std::cout << "Binary Search: Percent of Successful Searches = ";
    print_stat( found, B.size());

    return 0;

} // End of main()

/*
Func: void init_vector(std::vector<int> &vec, int seed, int lo, int hi)

Arg: Assign random valued to the elements in vec by using the seed value

Ret: none
*/
void init_vector(std::vector<int> &vec, int seed, int lo, int hi)
{
    srand(seed);

    for(unsigned int temp = 0; temp < vec.size(); ++temp)
    {
        vec[temp] = rand()%(hi-lo+1)+lo;
    }
}


/*
Func: void print_vector(const std::vector<int> &v, int print_cols, int col_width)

Arg: Print the given vector v with print_cols elements on each line and with
     each numeric value padded out to col_width wide (use std::setw()).

Ret: none
*/
void print_vector(const std::vector<int> &v, int print_cols, int col_width)
{
    //this thing -
    std::cout << std::string(print_cols * (col_width + 2) + 1, '-') << std::endl;

    for(unsigned int temp = 0; temp < v.size(); ++temp)
    {
        if(temp % print_cols == 0)
        {
            std::cout << std:: endl << "|";
        }

        std::cout << std::setw(col_width) << std::right << v[temp] << " |";
    }

    std::cout<<std::endl;
    std::cout << std::string(print_cols * (col_width + 2) + 1, '-') << std::endl;
}


/*
Func: void sort_vector(std::vector<int> &v)

Arg: sort the elements of vector v in ascending order

Ret: none
*/
void sort_vector(std::vector<int> &v)
{
    std::sort(v.begin(), v.end());
}


/*
Func: int search_vector(const std::vector<int> &v1, const std::vector<int> &v2, bool (*p)(const std::vector<int> &, int))

Arg: Implement a generic search algorithm

Ret: number of successful searches
*/
int search_vector(const std::vector<int> &v1, const std::vector<int> &v2, bool (*p)(const std::vector<int> &, int))
{
    int success = 0;

    for(unsigned int temp = 0; temp < v2.size(); ++temp)
    {
        if(p(v1, v2[temp]))
        {
            success++;
        }
    }

    return success;
}


/*
Func: void print_stat(int found, int total)

Arg: Print the percent of successful searches as a floating-point number
     on stdout

Ret:none
*/
void print_stat(int found, int total)
{
    float percent;

    percent = found * 100 / total;

    std::cout << std::setprecision(2) << std::fixed << percent <<"%\n";
}


/*
Func: bool linear_search(const std::vector<int> &v, int x)

Arg: A linear search algorithm, where x is the value to search for in vector v

Ret: true if x is found
*/
bool linear_search(const std::vector<int> &v, int x)
{
    if(find(v.begin(), v.end(), x) != v.end())
    {
        return true;
    }

    return false;
}


/*
Func: bool binary_search(const std::vector<int> &v, int x)

Arg: A binary search algorithm, where x is the value to search for in vector v

Ret: true if x is found
*/
bool binary_search(const std::vector<int> &v, int x)
{
    if(binary_search(v.begin(), v.end(), x))
    {
        return true;
    }
    else return false;
}
