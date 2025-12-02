/********************************************************************
CSCI 480                 Assignment 5                     Spring 2025
Programmer: Milo Zak (z1917365)
Section: 1
Date Due: 3/25
Purpose: In this assignment, you will solve the Reader-Writer 
problem using the PThreads library
*********************************************************************/

#include <sys/wait.h>
#include <bits/stdc++.h>
#include <semaphore.h>

using namespace std;

string testString = "All work and no play makes Jack a dull boy.";
int readcount = 0;
pthread_t readerThread[100];
pthread_t writerThread[100];
sem_t rw_sem; // used by both readers and writers
sem_t cs_sem; // used for protecting critical sections of readers

//Building the writer function
void *writer(void *param)
{
    int writerId = *(int *)param;

    //test to see if things are empty otherwise write
    while (!testString.empty() || testString == "")
    {
        sem_wait(&rw_sem);

        if (testString.empty())
        {
            sem_post(&rw_sem);
            break;
        }

        // not empty chop last char off and take a nap
        printf("writer %i is writing\n", writerId);
        fflush(stdout);
        testString.pop_back();

        sem_post(&rw_sem);
        sleep(1);
    }
    // Show the writer is exiting and end the writer thread
    printf("writer %i is exiting ...\n", writerId);
    pthread_exit(0);
}

// Create the reader threads and read through everything
void *reader(void *param)
{
    int readerId = *(int *)param;

    while (!testString.empty() || testString == "") // This is the same as writer
    {
        if (testString.empty())
        {
            break;
        }

        //if not empty increment readcount
        // This will help writer know when it's time to join and decrment a letter
        sem_wait(&cs_sem);
        readcount++;
        printf("readcount increments to %i \n", readcount);
        fflush(stdout);

        if (readcount == 1)
        {
            sem_wait(&rw_sem); // Wait
        }

        sem_post(&cs_sem);

        printf("reader %i is reading ... content: %s \n", readerId, testString.c_str());
        fflush(stdout);

        //After read comes back decrement readcount and essientally go again
        sem_wait(&cs_sem);
        readcount--;
        printf("readcount decrements to: %i.\n", readcount);
        fflush(stdout);

        // Knows when to read again
        if (readcount == 0)
        {
            sem_post(&rw_sem);
        }

        //hold system for sleep so write can do its thing
        sem_post(&cs_sem);
        sleep(1); //1 second
    }

    // End when empty
    printf("reader %i is exiting ...\n", readerId);
    pthread_exit(0);
}

//The right key is sticky on my laptop, I need to fix it before our next assignment
// Error correcting was a big issue and commenting as well
// I cant spell anymore (there were a lot of spelling errors in this section)
int main(int argc, char *argv[])
{
    //self Explanitory
    int readerThreadsMade = 0;
    int writerThreadsMade = 0;
    int readerId[50];
    int writerId[50];

    //Get the data
    if (argc > 2 && atoi(argv[1]) > 0 && atoi(argv[2]) > 0)
    {
        readerThreadsMade = atoi(argv[1]);
        writerThreadsMade = atoi(argv[2]);
    }
    else //No one put in numbers
    {
        cout << "ERROR: No number of readers and or writers\n";
        exit(-1);
    }

    cout << "*** Reader-Writer Problem Simulation ***\n";
    cout << "Number of reader threads: " << readerThreadsMade << endl;
    cout << "Number of writer threads: " << writerThreadsMade << endl;

    pthread_attr_t threadAttributes;
    pthread_attr_init(&threadAttributes);

    // Error checking for initalizing, creation and joining failures
    if (sem_init(&rw_sem, 0, 1) != 0 || sem_init(&cs_sem, 0, 1) != 0)
    {
        cout << "ERROR: Failed to initialize rw_sem\n";
        exit(-1);
    }

    for (int count = 0; count < readerThreadsMade; count++)
    {
        readerId[count] = count;
        if (pthread_create(&readerThread[count], &threadAttributes, reader, (void *)&readerId[count]) != 0)
        {
            cout << "ERROR: Reader thread creation failure\n";
            exit(-1);
        }
    }

    sleep(1); // let readers start first

    for (int count = 0; count < writerThreadsMade; count++)
    {
        writerId[count] = count;
        if (pthread_create(&writerThread[count], &threadAttributes, writer, (void *)&writerId[count]) != 0)
        {
            cout << "ERROR: Writer thread creation failure\n";
            exit(-1);
        }
    }
    for (int count = 0; count < writerThreadsMade; count++)
    {
        if (pthread_join(writerThread[count], NULL) != 0)
        {
            cout << "ERROR: Writer thread join error\n";
            exit(-1);
        }
    }

    for (int count = 0; count < readerThreadsMade; count++)
    {
        if (pthread_join(readerThread[count], NULL) != 0)
        {
            cout << "ERROR: Reader thread join error\n";
            exit(-1);
        }
    }

    // Destroy when weverything is done and exit out
    sem_destroy(&cs_sem);
    sem_destroy(&rw_sem);

    cout << "All threads are done.\n";
    cout << "Resources cleaned up.\n";

    return 0;
}
