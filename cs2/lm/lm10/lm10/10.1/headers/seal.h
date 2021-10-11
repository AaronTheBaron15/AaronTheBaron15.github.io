#ifndef SEAL_H
#define SEAL_H
#include <iostream>
#include "animal.h"

using namespace std;

class Seal : public Animal{
    private: 
        string color;
    public:
        //empty constructor
        //creates a grey-colored seal with no name and an age of 0
        Seal();

        //constructor for name
        //makes a new seal with a name, age set to zero, and color set to grey
        Seal(string n);

        //constructor for name and age
        //makes a new seal with a name and custom age, with a color of grey
        Seal(string n, int years);

        //constructor for name, age, and color
        //makes a new seal with a name, age, and color
        Seal(string name, int years, string c);

        //takes the virtual method from animal and creates its own implementation for Seal
        //makeNoise makes a noise based on the animal that makes the noise
        //no inputs
        //prints out the noise the animal makes
        void makeNoise();

        //clap is a method that makes the seal clap
        //no inputs
        //prints out that the seal is clapping
        void clap();

        //swim is a method that makes the seal swim
        //no inputs
        //prints out that the seal is swimming
        void swim();

};

#endif