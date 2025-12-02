/********************************************************************
CSCI 480                 Assignment 4                     Spring 2025
Programmer: Milo Zak (z1917365)
Section: 1
Date Due: 3/25
Purpose: simulates CPU scheduling in an operating system (C++ is more
suitable than C for this assignment)
*********************************************************************/

#include <sys/wait.h>
#include <bits/stdc++.h>

using namespace std;

const int MAX_TIME = 500;
const int IN_USE = 5;
const int HOW_OFTEN = 25;

class process
{
public:
    string processName;
    int processID;
    vector<pair<string, int>> history;
    size_t sub = 0;
    int cpuTimer = 0;
    int inputTimer = 0, outputTimer = 0;
    int cpuTotal = 0;
    int inputTotal = 0, outputTotal = 0;
    int cpuCount = 0;
    int inputCount = 0, outputCount = 0;
    int arrivalTime = 0;
};

int printDataSummary(process*&, int);
void printStatus(deque<process *>,deque<process *>,deque<process *>,deque<process *>, int, int, int, int);
//void terminateProcess(process*, int, int);


int printDataSummary(process *&processPtr, int timer)
{
    string inputBurst;
    string cpuBurst;
    string outputBurst;
    
    timer++; // End this increase

    // See if you need plural
    if (processPtr->cpuCount <= 1)
    {
        cpuBurst = "burst";  
    } 
    else
    {
        cpuBurst = "bursts";
    }

    if (processPtr->inputCount != 1)
    {
        inputBurst = "bursts";  
    } 
    else
    {
        inputBurst = "burst";  
    }
    
    if (processPtr->outputCount != 1)
     {
        outputBurst = "bursts"; 
    }
    else 
    {
        outputBurst = "burst";  
    }

    // wait time for the process
    int waitTime = (timer - (processPtr->cpuTotal + processPtr->inputTotal + processPtr->outputTotal + processPtr->arrivalTime)); 

    // Summary
    cout << "\nProcess " << processPtr->processID << " has ended.\n";
    cout << "Name:  " << processPtr->processName << endl;
    cout << "Started at time " << processPtr->arrivalTime << " and ended at time " << timer << endl;
    cout << "Total CPU time = " << processPtr->cpuTotal << " in " << processPtr->cpuCount << " CPU " << cpuBurst << endl;
    cout << "Total Input time =  " << processPtr->inputTotal << " in " << processPtr->inputCount << " Input " << inputBurst << endl;
    cout << "Total Output time =  " << processPtr->outputTotal << " in " << processPtr->outputCount << " Output " << outputBurst << endl;
    cout << "Time spent in waiting:  " << waitTime << endl << endl;

    return waitTime;
}

// This prints the status of the queues of process IO
void printStatus(deque<process *> entryQueue, deque<process *> readyQueue, deque<process *> inputQueue, deque<process *> outputQueue, int timer, int activeProcess, int activeInput, int activeOutput)
{
    cout << "Active process is " << activeProcess << endl;
    cout << "Active input is " << activeInput << endl;
    cout << "Active output is " << activeOutput << endl;

    //Math to figure out if each queue has things in it (pretty copy paste)
    cout << "Contents of the Entry Queue:\n";
    if (entryQueue.size() != 0)
    {
        for (size_t i = 0; i < entryQueue.size(); i++)
        {
            cout << entryQueue[i]->processID << "  ";
        }
    }
    else
    {
        cout << "(Empty)";
    }

    cout << "\nContents of the Ready Queue:\n";
    if (readyQueue.size() != 0)
    {
        for (size_t i = 0; i < readyQueue.size(); i++)
        {
            cout << readyQueue[i]->processID << "  ";
        }
    }
    else
    {
        cout << "(Empty)";
    }

    cout << "\nContents of the Input Queue:\n";
    if (inputQueue.size() != 0) 
    {
        for (size_t i = 0; i < inputQueue.size(); i++)
        {
            cout << inputQueue[i]->processID << "  ";
        }
    }
    else
    {
        cout << "(Empty)";
    }

    cout << "\nContents of the Output Queue:\n";
    if (outputQueue.size() != 0)
    {
        for (size_t i = 0; i < outputQueue.size(); i++)
        {
            cout << outputQueue[i]->processID << "  ";
        }
    }
    else
    {
        cout << "(Empty)";
    }
    cout << endl;
}

//CAUSED SEG FAULT
//This function terminates the process at the end on input
/*void terminateProcess(process *processPtr, int totalWaitTime, int timer) 
{
    totalWaitTime += printDataSummary(processPtr, timer);
    delete processPtr;
    processPtr = nullptr;
}*/

int main(int argc, char **argv)
{
    // Queues
    deque<process *> entryQueue;
    deque<process *> readyQueue;
    deque<process *> inputQueue;
    deque<process *> outputQueue;

    // Used a lot of math
    int cpuIdleTime = 0;
    int getProcessId = 101;
    int Timer = 0;
    int Active = 0;
    int activeInput = 0;
    int activeOutput = 0;
    int getArrivalTime = 0;
    int runTime = 0;       
    int processesInUse = 0;
    int totalProcesses = 0;
    int totalWaitTime = 0; 

    // Store input and actions
    string nextAction;
    string readInputFile;

    //to see if things are in use or idle
    bool isCpuBusy = false;
    bool isInputBusy = false;
    bool isOutputBusy = false;
    bool isCpuIdle = false; 
    bool isCpuDone = false; 
    bool outputNextTick = false;
    bool inputNextTick = false;

    //Pointers to look at the process
    process *processPtr;
    process *cpuPtr;
    process *inputPtr;
    process *outputPtr;
    process *queuedPtr;

    cout << "Simulation of CPU Scheduling\n\n";
    
    ifstream file;
    file.open(argv[1]); // open file
    file >>  readInputFile; // Read name

    while (!file.eof())
    {
        // STOPHERE if the end
        if ( readInputFile == "STOPHERE")
        {
            break;
        }

        //get process and pull basic info
        process fcfs; 
    
        fcfs.processName = readInputFile;

        fcfs.processID = getProcessId;
        getProcessId++;

        file >> getArrivalTime;
        fcfs.arrivalTime = getArrivalTime;

        file >>  readInputFile;
        
        // Loop instructions and store
        for (int i = 0; i < 10; i++)
        {
            //store and get next action
            file >> runTime;
            fcfs.history.push_back(make_pair(readInputFile, runTime));
            file >> readInputFile;
        }
        
        // getArrivalTime > 0 & there is <= 5 process in readyQueue get info and make it in use
        if (Timer >= getArrivalTime && readyQueue.size() <= IN_USE)
        {
            cout << "\nProcess " << fcfs.processID << " moved from the entryQueue Queue into the Ready Queue at time " << Timer << endl << endl;
            readyQueue.push_back(new process(fcfs));
            processesInUse++;
        }
        else // If full keep don't proces yet
        {
            entryQueue.push_back(new process(fcfs));
        }
    }
    //close file and get everything null
    file.close();

    processPtr = nullptr;
    inputPtr = nullptr;
    outputPtr = nullptr;

    while (Timer != MAX_TIME)
    {

        // Empty and not active break
        if (entryQueue.empty() && readyQueue.empty() && inputQueue.empty() && outputQueue.empty() && processPtr == nullptr && inputPtr == nullptr && outputPtr == nullptr && cpuPtr == nullptr)
        {
            break;
        }

        //not Active so idle
        if (Active == 0 && isCpuIdle == false && readyQueue.empty() && entryQueue.empty())
        {
            cout << "\nAt time " << Timer << ", Active is 0, so we have idle time for a while\n\n";
            isCpuIdle = true;
        }

        // Ready empty and none running
        if (readyQueue.empty() && isCpuBusy == false)
        {
        
            // Cheching entry
            if (!entryQueue.empty())
            {
                while (processesInUse < IN_USE)
                {
        
                    // Entry needs to be empty
                    if (entryQueue.empty())
                    {
                        break;
                    }
        
                    // Get info and pop
                    queuedPtr = entryQueue.front();
                    entryQueue.pop_front();
        
                    if (queuedPtr->arrivalTime <= Timer) // Move around
                    {
                        cout << "\nProcess " << queuedPtr->processID << " moved from the Entry Queue into the Ready Queue at time " << Timer << endl << endl;
                        processesInUse++;            
                        queuedPtr->arrivalTime = Timer;
                        readyQueue.push_back(queuedPtr);
                    }
                    else
                    {
                        break; // Breaking out of the hosiptal
                    }
                }
            }
        }

        if (Timer == 0 || Timer % HOW_OFTEN == 0) // Print statuses
        {
            cout << "\nStatus at time " << Timer << endl;
            printStatus(entryQueue, readyQueue, inputQueue, outputQueue, Timer, Active, activeInput, activeOutput);
            cout << endl;
        }
        if (!readyQueue.empty() && processPtr == nullptr && isCpuBusy == false)
        {
            processPtr = readyQueue.front(); // pull to front and pop
            readyQueue.pop_front(); 
        }
        if (processPtr != nullptr || cpuPtr != nullptr)
        {
            if (!isCpuBusy) //not busy pull things out and get things set to run
            {
                cpuPtr = processPtr;
                processPtr = nullptr;
        
                isCpuBusy = true;
                isCpuIdle = false;
        
                Active = cpuPtr->processID;
            }
            // Finding burst time
            if (cpuPtr->cpuTimer != cpuPtr->history[cpuPtr->sub].second)
            {
                cpuPtr->cpuTimer++;
            }
            else if (cpuPtr->cpuTimer == cpuPtr->history[cpuPtr->sub].second)
            {
                cpuPtr->cpuTotal += cpuPtr->history[cpuPtr->sub].second;
                cpuPtr->sub++; 
                nextAction = cpuPtr->history[cpuPtr->sub].first; 

                cpuPtr->cpuTimer = 0;
                cpuPtr->cpuCount++;

                isCpuBusy = false;
                Active = 0;
                isCpuDone = true;

                // Figure out next action and what to do
                if (nextAction == "I")
                {
                    if (inputQueue.empty() && inputPtr == nullptr) // Not busy set it up and make it busy
                    {
                        inputPtr = cpuPtr;
                        activeInput = inputPtr->processID;

                        inputNextTick = true;
                        isInputBusy = true;
                        cpuPtr = nullptr;
                    }
                    else // GET IN LINE!!!
                    {
                        inputQueue.push_back(cpuPtr);
                        cpuPtr = nullptr;
                    }
                }
                // Same as before but with output
                else if (nextAction == "O")
                {
                    if (outputQueue.empty() && outputPtr == nullptr)
                    {
                        outputPtr = cpuPtr;
                        activeOutput = outputPtr->processID; 

                        isOutputBusy = true;
                        outputNextTick = true;
                        cpuPtr = nullptr;
                    }
                    else
                    {
                        outputQueue.push_back(cpuPtr);
                        cpuPtr = nullptr;
                    }
                }
                else if (nextAction == "N") //Same as before but TERMINATE (plus counting active and processes complete)
                {
                    //terminateProcess(cpuPtr,totalWaitTime,Timer); BROKEN
                    totalWaitTime += printDataSummary(cpuPtr, Timer);
                    delete cpuPtr;
                    cpuPtr = nullptr;
                
                    totalProcesses++;
                    processesInUse--;
                }
            }
        }

        //Section deals with what do for input. Copy and paste with output essientially
        if (!inputQueue.empty() || inputPtr != nullptr) // Not empty or busy
        {
            if (isInputBusy == false) // dealing with busy
            {
                if ((inputQueue.size() > 1 || isCpuDone == false) && inputNextTick == false) //set up
                {
                    inputPtr = inputQueue.front(); 
                    isInputBusy = true;
        
                    activeInput = inputPtr->processID;
                    inputQueue.pop_front();
                }
            }
            if (inputPtr != nullptr && inputNextTick == false) // active and alse
            {
                // not hit brust time
                if (inputPtr->inputTimer < inputPtr->history[inputPtr->sub].second - 1)
                {
                    inputPtr->inputTimer++;
                }
                else // Hit burst time reset and go to next action
                {
                    inputPtr->inputTotal += inputPtr->history[inputPtr->sub].second;
                    inputPtr->sub++; 

                    inputPtr->inputTimer = 0;
                    inputPtr->inputCount++;
                
                    activeInput = 0;
                    nextAction = inputPtr->history[inputPtr->sub].first;

                    isInputBusy = false;
                    
                    if (nextAction == "C") // Figure out next action and where to put it
                    {
                        readyQueue.push_back(inputPtr);
                    }
                    else if (nextAction == "O") 
                    {
                        outputQueue.push_back(inputPtr);
                    }
                    else if (nextAction == "N") //TERMINATE
                    {
                        totalWaitTime += printDataSummary(inputPtr, Timer);
                        delete inputPtr;
                        inputPtr = nullptr;
        
                        totalProcesses++;
                        processesInUse--;
                    }
                    
                    inputPtr = nullptr; // Make everything null agan
                }
            }
        }

        //section deals with Output.Same isea as the input
        if (!outputQueue.empty() || outputPtr != nullptr) // Output now
        {
            if (isOutputBusy == false) // Check busy
            {
                //Not active make active
                if ((outputQueue.size() > 1 || isCpuDone == false) && outputNextTick == false)
                {
                    outputPtr = outputQueue.front();
                    isOutputBusy = true;
        
                    activeOutput = outputPtr->processID;
                    outputQueue.pop_front();
                }
            }
            //not next 
            if (outputPtr != nullptr && outputNextTick == false)
            {
                // Dealing with birst times
                if (outputPtr->outputTimer < outputPtr->history[outputPtr->sub].second - 1)
                {
                    outputPtr->outputTimer++;
                }
                else // Hit the time reset and moce on
                {
                    outputPtr->outputTotal += outputPtr->history[outputPtr->sub].second;
                    outputPtr->sub++;       
                    outputPtr->outputCount++;
                    outputPtr->outputTimer = 0;
                    
                    activeOutput = 0;
                    nextAction = outputPtr->history[outputPtr->sub].first;
                    isOutputBusy = false;

                    //what to do with next task
                    if (nextAction == "C")
                    {
                        readyQueue.push_back(outputPtr);
                    }
                    else if (nextAction == "I")
                    {
                        inputQueue.push_back(outputPtr);
                    }
                    else if (nextAction == "N") // TER<OMATE
                    {
                        totalWaitTime += printDataSummary(outputPtr, Timer);
                        delete outputPtr;
                        outputPtr = nullptr;
     
                        totalProcesses++;
                        processesInUse--;
                    }
                    outputPtr = nullptr;
                }
            }
        }

        // closing everything 
        inputNextTick = false;
        outputNextTick = false;
        isCpuDone = false;
        
        // What to if idleing and true
        if (isCpuIdle == true)
        {
            cpuIdleTime++;
        }

        //increase timer per go
        Timer++;
    }

    // Last put of math
    totalWaitTime = totalWaitTime / totalProcesses; 
    
    // Final run status 
    cout << "The run has ended.\n";
    cout << "The final value of the timer was:  " << Timer << endl;
    cout << "The amount of time spent idle was:  " << cpuIdleTime << endl;
    cout << "Number of terminated processes = " << totalProcesses << endl;
    cout << "Average waiting time for all terminated processes = " << totalWaitTime << endl;
    printStatus(entryQueue, readyQueue, inputQueue, outputQueue, Timer, Active, activeInput, activeOutput);

    return 0;
}
