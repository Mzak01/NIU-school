/********************************************************************
CSCI 480                 Assignment 1                     Spring 2025
Programmer: Milo Zak (z1917365)
Section: 1
Date Due: 2/17
Purpose:  Write a Linux program in C or C++ which uses fork() to
start child process(es), and also uses pipe() to do inter-process
communication. Other system calls such as getpid() and wait() are
also used. You'll create a simulation of an intergalactic space race
where multiple child processes represent competing spaceships, and
the parent process acts as the control center, coordinating the race
and displaying the results
**********************************************************************/

#include <sys/wait.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 5;
const int GOAL = 1000;
const int FULL_FUEL_AMOUNT = 300;
const int MIN_LIGHTYEAR_PROG = 10;
const int MAX_LIGHTYEAR_PROG = 50;

// Functions
void displayProg();
void makeRace();
void makeSpaceship();


//Spaceship behavior- progress, fuel, and winning
void makeSpaceship(int spaceshipId, int pipeWriteFd)
{
    char status[100];
    int distanceTraveled = 0;
    int fuelLevel = FULL_FUEL_AMOUNT;

    // Random seed
    srand(getpid());

    while (distanceTraveled < GOAL)
    {
        int progress = rand() % (MAX_LIGHTYEAR_PROG - MIN_LIGHTYEAR_PROG + 1) + MIN_LIGHTYEAR_PROG;

        // Refuel
        if (fuelLevel >= progress)
        {
            fuelLevel -= progress;
            distanceTraveled += progress;
        }
        else 
        {
            //not enough fuel, refuel
            fuelLevel = FULL_FUEL_AMOUNT;
        }

        // Send progress and fuel status to the parent
        snprintf(status, sizeof(status), "Spaceship %d: %d light-years, Fuel: %d", spaceshipId, distanceTraveled, fuelLevel);
        write(pipeWriteFd, status, strlen(status) + 1);

        sleep(1);  //shoert rest
    }
    while(distanceTraveled >= GOAL) 
    {
        cout << "🚀 Spaceship " << spaceshipId << " wins the race! 🚀" << endl;
            close(pipeWriteFd);
            exit(0);
    }
    // Clsie and exit pipes
    close(pipeWriteFd);
    exit(0);
}

// pipes and fork spaceships
void makeRace(int spaceshipPipes[N][2], pid_t spaceshipPid[N]) 
{
    //ERROR HANDEL
    for (int i = 0; i < N; ++i) {
        if (pipe(spaceshipPipes[i]) == -1) 
        {
            cerr << "Pipe failed\n";
            exit(1);
        }

        spaceshipPid[i] = fork();
        if (spaceshipPid[i] < 0) 
        {
            cerr << "Fork failed\n";
            exit(1);
        }

        if (spaceshipPid[i] == 0) 
        {  
            for (int j = 0; j < N; ++j) 
            {
                close(spaceshipPipes[j][0]);  // Close the read end of all pipes in child
            }
            makeSpaceship(i + 1, spaceshipPipes[i][1]);
            exit(0);
        } 
        else 
        {
            close(spaceshipPipes[i][1]);  // Close the write end in the parent
        }
    }
}

// Display the leaderboard and progress
void displayProg(int spaceshipPipes[N][2], bool &isRaceGoing) 
{
    char raceStatus[1000];
    bool spaceshipsFinished = true;
    int distanceGone = 0;
    int fuelRemain = 0;

    //clear the screen
    cout << "\033[2J\033[1;1H";
    cout << "🚀 Intergalactic Space Race Leaderboard 🚀\n";
    cout << "-------------------------------------------------------\n";

    // Display progress of spaceship
    for (int i = 0; i < N; ++i) 
    {
        if (read(spaceshipPipes[i][0], raceStatus, sizeof(raceStatus)) > 0)
         {
            sscanf(raceStatus, "Spaceship %*d: %d light-years, Fuel: %d", &distanceGone, &fuelRemain);

            cout << "Spaceship " << (i + 1) << ": ";
            //progress bar
            for (int j = 0; j < distanceGone / MAX_LIGHTYEAR_PROG; ++j)
            {
                cout << "=";
            }
            cout << " " << distanceGone << " light-years, Fuel: " << fuelRemain << endl;

            // Check if spaceship has not finished the race
            if (strstr(raceStatus, "wins the race") == nullptr)
            {
                spaceshipsFinished = false;
            }
        }
    }

    // If all spaceships finished, end the race
    isRaceGoing = !spaceshipsFinished;
    cout << "--------------------------------------------------------\n";
//        close(spaceshipPipes[i][0]);
}

int main() {
    int spaceshipPipes[N][2];
    pid_t spaceshipPid[N];
    bool isRaceGoing = true;

    srand(time(0));  // Initialize seed

    //create spaceships
    makeRace(spaceshipPipes, spaceshipPid);

    // Race loop
    while (isRaceGoing)
    {
        displayProg(spaceshipPipes, isRaceGoing);  // Display leaderboard
        sleep(1);  
    }

    //wait
    for (int i = 0; i < N; ++i) {
        waitpid(spaceshipPid[i], NULL, 0);
    }
    return 0;
}
