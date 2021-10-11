#ifndef GIRAFFE_H
#define GIRAFFE_H
#include <iostream>
#include "animal.h"

using namespace std;

class Giraffe : public Animal{
    private: 
        float neckLength;  //neck length in feet
    public:
        //empty constructor
        //creates a giraffe with a neck length of 6 feet (the average neck length of a giraffe)
        Giraffe();
        
        //constructor for name
        //creates a giraffe with a name, an age of 0, and neck length of 6 feet
        Giraffe(string name);

        //constructor for name and age
        //creates a giraffe with a name, age of user selected amount, and neck length of 6 feet
        Giraffe(string name, int years);
        
        //constructor for neck length, age, and name
        //makes the giraffe's neck length a user chosen amount
        Giraffe(string name, int years, float neck);

        //takes the virtual method from animal and creates its own implementation for Giraffe
        //makeNoise makes a noise based on the animal that makes the noise
        //no inputs
        //prints out the noise the animal (giraffe) makes
        void makeNoise();

        //neckWhip is a method that makes the giraffe attack with it's neck
        //no inputs
        //prints out that the giraffe is neck whipping
        void neckWhip();

        //getWater is a method that makes the giraffe take a drink of water
        //no inputs
        //prints out that the giraffe is drinking water
        void getWater();

};

#endif