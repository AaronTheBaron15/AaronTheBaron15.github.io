//dice.h file (taken and modified from Scott Griffith)
//Aaron Borjas
//CS171-1 CS1
//12/13/18

//Implimentation of Dice Object
//Scott Griffith - Whitworth University - CS171
//11/28/2018
//
// Class to hold a n-sided dice.
// Dice cannot change number of faces once initilized.
// Can be rolled and checked
// A six sided dice will return 1-6 values

#include "dice.h"

#include <iostream>
#include <cstdlib> //Random()

using namespace std;

//Default Constructor to make 6 sided dice
//The output of roll will always be between 1 and sides / numberOfSides
//Input: unsigned integer representing the number of sides of the die
Dice::Dice(){
    numberOfSides = 6; //Grab number of sides.
    roll(); //Make sure the value is a new one
}

//Constructor that takes in sides to make a dice with sides number of sides
//The output of roll will always be between 1 and sides / numberOfSides
//Input: unsigned integer representing the number of sides of the die
Dice::Dice(unsigned int sides){
    cout << "Making a new dice! With " << sides << " sides" << endl;
    numberOfSides = sides; //Grab number of sides.

    roll(); //Make sure the value is a new one

}

//Method to check the current value shown on the die
//Input: NA
//Output: some value between 1 and numberOfSides determined by a roll
//        stays the same until a roll is made
unsigned int Dice::checkFace(){
    return currentValue; //Just pass the value back
}

//Method to roll the die
//Input: NA
//Output: Die gets a new value, this changed what checkFace will return
//        Also return that new value
unsigned int Dice::roll(){
    if(isItLocked) { //if the dice is locked
        return currentValue; //return the current value
    }
    else { //otherwise
        currentValue = (rand()%numberOfSides) + 1;   //Offsetting so the value is always 1 to number not 0 to 1-number
    }
    return currentValue;
}