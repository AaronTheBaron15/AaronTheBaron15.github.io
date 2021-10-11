//stopwatch.cpp
//CS172-1 CS2
//Aaron Borjas
//2/16/19
//simulating a stopwatch with a start time, end time, and elapsed time.

#include <iostream>
#include <ctime>
#include "../headers/stopwatch.h"
using namespace std;

//empty constructor for stopwatch, makes it so that all the member variables of stopwatch are equal to -1
//-1 in this context will be equal to undefined
Stopwatch::Stopwatch() { 
    startTime = -1; //startTime is undefined
    endTime = -1; //endTime is undefined
    elapsedTime = -1; //elapsedTime is undefined
}

//a function called getStartTime, which returns the startTime of the stopwatch
//no inputs
//outputs the startTime as a clock_t variable
clock_t Stopwatch::getStartTime() { 
    return startTime;
}

//a function called getEndTime, which returns the end time of the stopwatch
//no inputs
//returns the endTime as a clock_t variable
clock_t Stopwatch::getEndTime() { 
    return endTime;
}

//function start(), which "starts" the stopwatch
//no inputs
//no visible outputs but changes startTime and elapsedTime to the current cycle of the computer
void Stopwatch::start() {
    startTime = clock();
    elapsedTime = clock();
}

//function stop, which "stops" the stopwatch
//no inputs
//no visible outputs, but changes endTime and elapsedTime.
void Stopwatch::stop() {
    endTime = clock();
            
    elapsedTime = static_cast<float>(endTime - startTime)/CLOCKS_PER_SEC;
}

//function getElapsedTime, which gives the current elapsed of the stopwatch
//no inputs
//returns the elapsedTime of the stopwatch in seconds
float Stopwatch::getElapsedTime() {
    return elapsedTime;
}


//function printWatch, prints the information of the watch if it has been defined
//no inputs
//prints out information about the watch
void Stopwatch::printWatch() {
    //start time print
    if(startTime == -1) { //if startTime is not defined
        cout << "Start time has not been set yet!" << endl; //say that start time has not been defined
    }
    else { //otherwise if startTime was defined
        cout << "Start time is: " << startTime << endl; //print out the startTime
    }
            
    //end time print
    if(endTime == -1) { //if endTime is not defined
        cout << "End time has not been set yet!" << endl; //tells user end time isnt defined
    }
    else { //if endtime is defined
        cout << "End time is: " << startTime << endl; //print out endtime
    }

    //elapsed time print
    if(elapsedTime == -1) { //if elapsed time is undefined
        cout << "Elapsed time has not been set yet since the timer has not started!" << endl; //tells user elapsed time is not defined
    }
    else if(endTime == -1) { //otherwise if there is no defined endtime
        clock_t currTime = clock(); //create a new pseudo-endtime that does elapsed time from start till currTime
        elapsedTime = static_cast<float>(currTime - startTime)/CLOCKS_PER_SEC; //sets elapsedTime to (current clocks - starting clocks) and divide it by clocks_per_sec

        cout << "Elapsed time right now is " << elapsedTime << endl; //says what current elapsed time is
    }
    else { //otherwise if elapsed time and endtime are defined
        cout << "Elapsed time right now is " << elapsedTime; //print out the total time from start to finish.
    }
}

