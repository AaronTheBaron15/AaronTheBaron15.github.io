#ifndef PENGUIN_H
#define PENGUIN_H
#include <iostream>
#include "animal.h"

using namespace std;

class Penguin : public Animal{
    private: 
        string type;
    public:
        //empty constructor
        //creates an emperor penguin
        Penguin();

        //constructor for name
        //creates a new emperor penguin with a name and an age set to zero
        Penguin(string name);

        //constructor for name and age
        //creates a new emperor penguin with a name and age
        Penguin(string name, int years);

        //constructor for name
        //creates a new penguin with a name, age, and of a certain species
        Penguin(string name, int age, string species);

        //takes the virtual method from animal and creates its own implementation for penguin
        //makeNoise makes a noise based on the animal that makes the noise
        //no inputs
        //prints out the noise the animal (penguin) makes
        void makeNoise();

        //huddle is a method that makes the penguin huddle for warmth
        //no inputs
        //prints out that the penguin is huddling
        void huddle();

        //swim is a method that makes the penguin swim
        //no inputs
        //prints out that the penguin is swimming
        void swim();

};

#endif