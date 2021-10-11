#ifndef ELEPHANT_H
#define ELEPHANT_H
#include <iostream>
#include "animal.h"

using namespace std;

class Elephant : public Animal{
    private: 
        float trunkLength;  //trunk length in feet
        string item; //the item being help by the elephant
    public:
        //empty constructor
        //creates an elephant with a trunk length of 6 feet (the average length of an elephant trunk is around 6 feet)
        //no name and age of 0
        Elephant();

        //constructor for age
        //creates an elephant with a user selected name, age of 0, and trunk length of 6
        Elephant(string name);

        //constructor for name and age
        //creates an elephant with a name and age, with a trunk length of 6 feet
        Elephant(string name, int years);

        //constructor for name, age, and trunk length
        //creates an elephant with a name, age, and trunk length
        Elephant(string name, int years, float trunk);

        //takes the virtual method from animal and creates its own implementation for Elephant
        //makeNoise makes a noise based on the animal that makes the noise
        //no inputs
        //prints out the noise the animal (elephant) makes
        void makeNoise();

        //grabStuff is a method that makes the elephant grab something with its trunk
        //input - takes in an item for the elephant to pick up
        //prints out that the elephant is picking something up
        void grabStuff(string stuff);

        //dropStuff is a method that makes the elephant drop something held in its trunk
        //input - takes in an item for the elephant to pick up
        //prints out that the elephant is dropping an item in its trunk
        void drop();

        //says the item the elephant is currently holding
        //no inputs
        //prints out the item the elephant is holding
        string getItem();

};

#endif