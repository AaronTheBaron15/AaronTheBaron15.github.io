//This is the header file for the explorer class
//Aaron Borjas
//CS273-1
//10/6/2019
//This file defines the methods and member variables of the Explorer class

#include <iostream>
#include <string>
#include <vector>
#include "Treasure.h"
#include "Location.h"
using namespace std;

#pragma once

#ifndef EXPLORER_H
#define EXPLORER_H

class Explorer {
    private:
        vector<Treasure> inventory; //a vector of treasures that is the explorers current inventory
        Location currLocation;//the current location of the explorer
    public: 

        //constructor for the explorer
        //inputs - the location to start at
        //outputs - creates an explorer that has no inventory set but with a set start location
        Explorer(Location& l);

        //getInventory prints the inventory of the explorer
        //inputs - none
        //outputs - prints the inventory of the explorer
        void getInventory();

        //getLoc gets the current location of the explorer
        //inputs - none
        //outputs - returns the Location of the explorer
        Location getLoc();

        //examine takes a look at an input and prints a description of it
        //inputs - takes in a string of a desired input
        //output - returns a description of the input option
        void examine(string type);

        //adds a treasure to the explorers inventory
        //inputs - takes in a reference to a treasure object
        //outputs - adds a treasure object to the explorer's inventory
        void take(Treasure& t);

        //moves the explorer to a location
        //inputs - takes in a reference to a location object
        //output - moves the explorer to a location
        void move(Location& l);


};

#endif // !EXPLORER_H