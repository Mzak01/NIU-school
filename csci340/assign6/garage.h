/*
    Milo zak
    z1917365
    csci340-3

    I certify that this is my own work and where appropriate an extension
    of the starter code provided for the assignment.
*/

#ifndef GARAGE_H
#define GARAGE_H

#include <bits/stdc++.h>
#include "car.h"

using namespace std;

class garage
{
public:
        garage(size_t limit = 10) : parking_lot_limit(limit) {}

        /// @param license The license of the car that has arrived.
        void arrival(const std::string &license);

        /// @param license The license of the car that has departed.
        void departure(const std::string &license)
        {
            bool lplate_found = false;
            int position_found = 0;
            std::stack<car> replace;
            unsigned temporary = 0;
            int increment = 0;

            for(temporary = 0; temporary < parking_lot.size(); ++temporary)
            {
                if(parking_lot[temporary].get_license() == license)
                {
                    position_found = temporary;
                    lplate_found = true;
                }
            }
            if(lplate_found == true)
            {
                while(increment < position_found)
                {
                    replace.push(parking_lot.front());
                    parking_lot.pop_front();
                    ++increment;
                }
                std::cout << parking_lot[0] << " has departed.\n";
                parking_lot[0].move();

                std::cout << "    car was moved " << parking_lot[0].get_num_moves() << " time in the garage.\n\n";
                parking_lot.pop_front();

                while(0 < replace.size())
                {
                    (replace.top()).move();
                    parking_lot.push_front(replace.top());
                    replace.pop();
                 }
            }
            else
            {
                std::cout << "No car with the license plate \"" << license << "\" is in the garage.\n\n";
            }
        }

private:
        int next_car_id = { 1 };
        std::deque<car> parking_lot;
        size_t parking_lot_limit;
};

//look above for the param
void garage::arrival(const std::string &license)
{
    car vroom(next_car_id,license);
    if( parking_lot.size() == parking_lot_limit )
    {
        std::cout << vroom << " has arrived.\n    But the garage is full!\n\n";
    }
    else if (parking_lot.size() < parking_lot_limit)
    {
        std::cout << vroom << " has arrived.\n\n";
        parking_lot.push_back(vroom);
        ++next_car_id;
    }
}

//look above for the param
/*void departure (const std::string &license)
{
    bool lplate_found = false;
    int position_found = 0;
    std::stack<car> replace;
    unsigned temporary = 0;
    int increment = 0;

    for(temporary = 0; temporary < parking_lot.size(); ++temporary)
    {
        if(parking_lot[temporary].get_license() == license)
        {
            position_found = temporary;
            lplate_found = true;
        }
    }
    if(lplate_found == true)
    {
        while(increment < position_found)
        {
            replace.push(parking_lot.front());
            parking_lot.pop_front();
            ++increment;
        }
        std::cout << parking_lot[0] << " has departed.\n\n";
        parking_lot[0].replace();

        std::cout << "\tcar was moved " << parking_lot[0].get_num_moves() << " time in the garage.\n\n";
        parking_lot.pop_front();

        while(0 < replace.size())
        {
            (replace.top()).move();
            parking_lot.push_front(replace.top());
            replace.pop();
        }
    }
    else
    {
        std::cout << "No car with the license plate \"" << license << "\" is in the garage.\n\n";
    }
}*/

#endif //Garage_h
