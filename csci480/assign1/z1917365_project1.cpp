/********************************************************************
CSCI 480                 Assignment 1                       Fall 2025
Programmer: Milo Zak (z1917365)
Section: 1
Date Due: 1/28
Purpose:  Although the /proc file system is virtual, you can open and read
the virtual files the same way as any other file. So you can start this
assignment without the instructor discussing the /proc file system. For
the purpose of this assignment, you just need to read the virtual files
specified in the writeup. 
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

//Functions
string readFile(const string&);
void formatTime(double);
void printCpuDetails(const string&);
void printUptime(const string&);
void printSwapDeviceSize(const string&);

//Read file content and return as string
string readFile(const string& filePath) 
{
    ifstream file(filePath);   //Open file
    string line;
    string content = "";

    while (getline(file, line))  //Read file
    {
        content += line + "\n";  //Append each line
    }
    return content;
}

//Output time in days, hours, minutes, and seconds
void formatTime(double totalSeconds) 
{
    //self explanatory
    int days = totalSeconds / (24 * 3600);
    totalSeconds -= days * 24 * 3600;
    int hours = totalSeconds / 3600;
    totalSeconds -= hours * 3600;
    int minutes = totalSeconds / 60;
    totalSeconds -= minutes * 60;
    cout << "Up for " << days << " days, " << hours << " hours, " << minutes << " minutes, and " 
         << totalSeconds << " seconds." << endl;
}

//nxt to hopper
//print CPU details 
void printCpuDetails(const string& cpuInfoContent) 
{
    int processorCount = 0;
    set<string> physicalCpuChips;
    stringstream cpuInfoStream(cpuInfoContent);
    string cpuInfoLine;

    //loop to find counts
    while (getline(cpuInfoStream, cpuInfoLine)) 
    {
        if (cpuInfoLine.find("processor") == 0 || cpuInfoLine.find("physical id") == 0) 
        {
            processorCount++;
            physicalCpuChips.insert(cpuInfoLine.substr(cpuInfoLine.find(":") + 2));
        }
    }
    cout << "Hopper has " << processorCount << " processors." << endl
         << "Hopper has " << physicalCpuChips.size() << " physical multi-core chips." << endl << endl;
}

//uptime info
void printUptime(const string& uptimeContent) 
{
    double uptimeInSeconds;
    stringstream(uptimeContent) >> uptimeInSeconds;
    cout << "Hopper has been up for " << uptimeInSeconds << " seconds." << endl;
    formatTime(uptimeInSeconds);
}

//print swap device size in MB
void printSwapDeviceSize(const string& swapInfoContent) 
{
    double totalSwapSizeMB = 0;
    stringstream swapInfoStream(swapInfoContent);
    string swapInfoLine;
    
    while (getline(swapInfoStream, swapInfoLine)) 
    {
        double swapSizeKB;
        string device;
        stringstream(swapInfoLine) >> device >> swapSizeKB;
        totalSwapSizeMB += swapSizeKB / 1024;  //Convert KB to MB
    }
    cout << "The size of hopper's swap device is " << totalSwapSizeMB << " MB." << endl << endl;
}

int main() 
{
    //Read files for OS info
    string osTypeContent = readFile("/proc/sys/kernel/ostype");        //OS type
    cout << "OS type: " << osTypeContent;

    string machineNameContent = readFile("/proc/sys/kernel/hostname");  //Hostname
    cout << "Hostname: " << machineNameContent;

    string osReleaseContent = readFile("/proc/sys/kernel/osrelease");  //OS release
    cout << "OS release: " << osReleaseContent;

    string osVersionContent = readFile("/proc/sys/kernel/version");    //OS version
    cout << "OS version: " << osVersionContent << endl << endl;

    //Output Processor details
    string cpuInfoContent = readFile("/proc/cpuinfo");
    printCpuDetails(cpuInfoContent);

    string uptimeContent = readFile("/proc/uptime");
    printUptime(uptimeContent);

    //Output Processor 0 info
    stringstream cpu0InfoStream(cpuInfoContent);
    string cpuInfoLine,
           cpuVendor, 
           cpuModel;

    while (getline(cpu0InfoStream, cpuInfoLine)) 
    {
        if (cpuInfoLine.find("processor") == 0) 
        {
            getline(cpu0InfoStream, cpuInfoLine); cpuVendor = cpuInfoLine.substr(cpuInfoLine.find(":") + 2);
            getline(cpu0InfoStream, cpuInfoLine); cpuModel = cpuInfoLine.substr(cpuInfoLine.find(":") + 2);
        }
    }
    cout << "The vendor for processor 0 is " << cpuVendor << "." << endl;
    cout << "The model name of processor 0 is " << cpuModel << "." << endl << endl;
    //lost on how to get rst
    //Processor 5 info
    cout << endl;
    string statInfoContent = readFile("/proc/stat");
    stringstream statInfoStream(statInfoContent);
    string statInfoLine;
    //loop to get info
    while (getline(statInfoStream, statInfoLine))
    {
        if (statInfoLine.find("cpu5") == 0)
        {
            int userModeTime, niceModeTime, systemModeTime, idleTime;
            stringstream(statInfoLine) >> statInfoLine >> userModeTime >> niceModeTime >> systemModeTime >> idleTime;
            cout << "Processor 5 has spent " << (userModeTime + niceModeTime) << " seconds in user mode." << endl;
            cout << "Processor 5 has spent " << systemModeTime << " seconds in system mode." << endl;
            cout << "Processor 5 has spent " << idleTime << " seconds in idle mode." << endl;
            formatTime(idleTime);
        }
    }
    //swap device size
    cout << endl;
    string swapInfoContent = readFile("/proc/swaps");
    printSwapDeviceSize(swapInfoContent);

    return 0;
}
