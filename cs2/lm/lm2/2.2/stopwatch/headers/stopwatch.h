#ifndef STOPWATCH_h
#define STOPWATCH_h

#include <iostream>
#include <ctime>

using namespace std;

class Stopwatch {
    private:
        clock_t startTime;
        clock_t endTime;
        float elapsedTime;

    public:

        //empty constructor for stopwatch, makes it so that all the member variables of stopwatch are equal to -1
        //-1 in this context will be equal to undefined
        Stopwatch();

        //a function called getStartTime, which returns the startTime of the stopwatch
        //no inputs
        //outputs the startTime as a clock_t variable
        clock_t getStartTime();

        //a function called getEndTime, which returns the end time of the stopwatch
        //no inputs
        //returns the endTime as a clock_t variable
        clock_t getEndTime();

        //function start(), which "starts" the stopwatch
        //no inputs
        //no visible outputs but changes startTime and elapsedTime to the current cycle of the computer
        void start();

        //function stop, which "stops" the stopwatch
        //no inputs
        //no visible outputs, but changes endTime and elapsedTime.
        void stop();

        //function getElapsedTime, which gives the current elapsed of the stopwatch
        //no inputs
        //returns the elapsedTime of the stopwatch in seconds
        float getElapsedTime();


        //function printWatch, prints the information of the watch if it has been defined
        //no inputs
        //prints out information about the watch
        void printWatch();
};

#endif