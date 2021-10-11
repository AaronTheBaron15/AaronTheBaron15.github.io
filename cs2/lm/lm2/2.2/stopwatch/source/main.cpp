//main.cpp
//CS172-1 CS2
//Aaron Borjas
//2/19/18
//implements stopwatch.cpp and stopwatch.h

#include <iostream>
#include <ctime>
#include "../headers/stopwatch.h"

int main() {
    Stopwatch watch1 = Stopwatch(); //creates a new stopwatch

    //this code didnt work because cin "pauses" clock cycles 
    // cout << "Press enter to start the stopwatch: ";
    // int number;
    // cin >> number;

    watch1.printWatch(); //prints the watch before anything is defined

    cout << endl;
    
    watch1.start(); //starts the watch

    watch1.printWatch(); //prints the watch after start has been defined

    //code that runs for about 10 seconds between starttime and endtime

    int total; //placeholder for total, which will be changed 
    for(int j = 0; j < 100000/3; j++) { //iterates through j by 1 from 0 to 100,000/3, or about 33,333
        for(int i = 0; i < 100000; i++) { //iterates through i by 1 from 0 to 100,000
            total += i^2; //total is total's previous value plus i^2
            // cout << total << " ";
        }
    }
    cout << endl;//prints a new line


    //this did not work because cin stops recording cycles
    // cout << "Press enter to stop the stopwatch: ";
    // cin >> number;
    
    watch1.stop(); //stops the stopwatch

    watch1.printWatch(); //prints watch after stop has been initialized
    
    //cout << "The elapsed time from start to stop is: " << watch1.getElapsedTime() << endl; //prints the elapsed time
    // cout << "Start is: " << watch1.getStartTime() << endl; //prints the start time
    // cout << "End is: " << watch1.getEndTime(); //prints the end time

    //==================================
    //following code was testing clock()
    //==================================

    // clock_t myClock;

    // myClock = clock();

    // cout << "myClock starts at: " << myClock << endl;

    // int total = 0;
    // for(int i = 0; i < 10000; i++) {
    //     total+=i^2;
    // }
    // cout << "total is: " << total << endl;

    // clock_t end = clock();

    // clock_t elapsedTime = (end - myClock);

    // cout << "myClock ended..." << endl << endl;

    // cout << "The difference from the start of myClock to the end of myClock is: " <<((float)elapsedTime/CLOCKS_PER_SEC) << " seconds" << endl;
}