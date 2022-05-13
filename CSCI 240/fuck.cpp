#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>

#define UPPER_BOUND 250.0
#define LOWER_BOUND 1.0
#define MAX_SIZE 75
#define MIN_SIZE 25
#define MAX_VALUES_PER_LINE 12

using namespace std;

double randDouble() {
    // generating the random double value
    double randomValue = LOWER_BOUND + ((rand()*1.0) / (RAND_MAX / (UPPER_BOUND - LOWER_BOUND)));
    // returning the random value
    return randomValue;
}

int buildRandom(double array[]) {
    // generates a random size of the array, and populates elements as per that size
    // generate total elements
    int totalElements = MIN_SIZE + (rand() % (MAX_SIZE - MIN_SIZE + 1));
    for (int i = 0; i < totalElements; ++i) {
        // generating the random double array
        array[i] = randDouble();
    }
    return totalElements;
}

void print(string title, double array[], int numberOfValues) {
    // printing the array with 12 values per row
    cout << title << endl; // displaying title
    for (int i = 0; i < numberOfValues; ++i) {
        // printing 12 rows per line
        for (int j = i; j < i + MAX_VALUES_PER_LINE && j < numberOfValues; ++j) {
            cout << setw(8) << setprecision(2) << fixed << array[j] << " ";
        }
        // value i becomes i + 11 not i + 12, since at the end of this iteration
        // value of i will be incremented by 1, so i will become i + 12
        i += 11;
        cout << endl;
    }
}

void sort(double array[], int numberOfValues) {
    //  using selection sort algorithm
    int minPos;
    for (int i = 0; i < numberOfValues; ++i) {
        minPos = i; // storing minPos as i
        for (int j = i + 1; j < numberOfValues; ++j) {
            // if value of array at pos j less than value at minPos
            // set minPos to j
            if (array[j] < array[minPos]) {
                minPos = j;
            }
        }
        // swapping the elements between i and minPos
        double temp = array[minPos];
        array[minPos] = array[i];
        array[i] = temp;
    }
}

int buildFile(double array[]) {
    // input file stream to read data from nums.txt
    ifstream inputFileStream;
    inputFileStream.open("nums.txt");   // opening the file nums.txt
    // if the file cannot be open, show error and exit the program
    if (!inputFileStream.is_open()) {
        cerr << "Cannot open the file please check!";
        exit(0);
    }
    // set initial index to 0
    int subscript = 0;
    // while not reached the end of the file
    while (!inputFileStream.eof()) {
        // store the stream value to the double currentVal
        double currentVal;
        inputFileStream >> currentVal;
        // and add the current to current subscript and
        // increment subscript by 1
        array[subscript++] = currentVal;
    }
    // closing the file
    inputFileStream.close();
    // subscript contains the total number of elements in the array
    // so return it
    return subscript;
}


int main() {
    srand(52);
    // creating a double array of size MAX_SIZE
    double array[MAX_SIZE];
    double fileArray[MAX_SIZE];

    // build the array of random double values
    int totalElements = buildRandom(array);

    cout << "Total number of elements in the random array: " << totalElements << endl;

    string printString = "Array of Random Numbers";
    print(printString, array, totalElements);

    cout << endl;

    // sorting the array
    sort(array, totalElements);

    string sortedPrintString = "Sorted Array of Random Numbers";
    print(sortedPrintString, array, totalElements);

    cout << endl;

    // now reading from the file nums.txt
    int totalFileArrayElements = buildFile(fileArray);

    cout << "Total number of elements in the array from file: " << totalFileArrayElements << endl;

    // displaying the initial list of file array elements
    string printFileString = "Array of File Elements";
    print(printFileString, fileArray, totalFileArrayElements);

    // sorting the file array
    sort(fileArray, totalFileArrayElements);

    // displaying the sorted array
    string sortedPrintFileString = "Sorted Array of File Elements";
    print(sortedPrintFileString, fileArray, totalFileArrayElements);


}

