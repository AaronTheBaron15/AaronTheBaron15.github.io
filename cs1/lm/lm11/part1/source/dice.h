//dice.h file (taken and modified from Scott Griffith)
//Aaron Borjas
//CS171-1 CS1
//12/13/18

//Dice Object
//Scott Griffith - Whitworth University - CS171
//11/28/2018
//
// Class to hold a n-sided dice.
// Dice cannot change number of faces once initilized.
// Can be rolled and checked
// A six sided dice will return 1-6 values
// srand() needs to be set before using!

//These are both called pre-processor directives (i.e. something the compiler reads, but does not compile)
//This ensures that this file will not be compiled multiple times
//This could happen if it is referenced by multiple other files.
#ifndef DICE_H
#define DICE_H


class Dice{
    private:
        //Number of sides to the dice
        unsigned int numberOfSides;
        //Current value of the dice, set after a roll, persistant for checking
        unsigned int currentValue;

    public:
        //Default Constructor to make 6 sided dice
        //The output of roll will always be between 1 and sides / numberOfSides
        //Input: unsigned integer representing the number of sides of the die

        //if the dice is locked
        bool isItLocked;

        Dice();

        //Constructor that takes in sides to make a dice with sides number of sides
        //The output of roll will always be between 1 and sides / numberOfSides
        //Input: unsigned integer representing the number of sides of the die
        Dice(unsigned int sides);

        //Method to check the current value shown on the die
        //Input: NA
        //Output: some value between 1 and numberOfSides determined by a roll
        //        stays the same until a roll is made
        unsigned int checkFace();

        //Method to roll the die
        //Input: NA
        //Output: Die gets a new value, this changed what checkFace will return
        //        Also return that new value
        unsigned int roll();


};

#endif