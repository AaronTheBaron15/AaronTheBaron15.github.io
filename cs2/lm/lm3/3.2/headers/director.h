#include <iostream>
#include <string>
using namespace std;

#ifndef DIRECTOR_H
#define DIRECTOR_H

class Director {
    private:
        string name;
        int age;
        string previousMovie;
    public:
        //empty class constructor
        Director();

        //class constructor for Director
        //creates a director with a name, age, and previous movie
        Director(string dirName, int dirAge, string dirPrevious);

        //function getName, gets the name of the director
        //no inputs
        //prints the name of the director to the screen
        string getName();

        //function getAge, gets the age of the director
        //no inputs
        //prints the age of the director to the screen
        int getAge();

        //function getPrevious, gets the name of the directors previous movie
        //no inputs
        //prints the name of the directors previous movie 
        string getPrevious();

        //function print, prints all the information about the director
        //no inputs
        //prints all the information about the director to the screen.
        void print();
};

#endif