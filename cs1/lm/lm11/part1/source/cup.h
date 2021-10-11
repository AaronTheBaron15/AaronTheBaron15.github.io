//dice.h file (taken and modified from Scott Griffith)
//Aaron Borjas
//CS171-1 CS1
//12/13/18

//Cup Object
//Scott Griffith - Whitworth University - CS171
//11/28/2018
//
// Class to hold a bunch of dice (utilizes dice.h)
// Cup can roll all dice / Print all dice / Sum all dice

//These are both called pre-processor directives (i.e. something the compiler reads, but does not compile)
//This ensures that this file will not be compiled multiple times
//This could happen if it is referenced by multiple other files.
#ifndef CUP_H
#define CUP_H

#include "dice.h"

const int SIZE_OF_CUP = 10;

class Cup{
    private:
        //Array Holding all of the dice
        //Max size is SIZE_OF_CUP
        Dice setOfDice[SIZE_OF_CUP];
        
    public:
        //Number to help keep track of dice in cup (starts at zero)
        unsigned int numberOfDice;

        //Constructor for Cup class
        //Sets up numberOfDice to zero
        //Dice must be added individually
        //Input: NA
        //Output: Valid cup
        Cup();

        //Method to add dice to the cup
        //This copys dice, so they can go out of scope in the calling function
        //Input: die that will be added to the cup
        //Output: True if die was added, false if could not be added
        bool addDice(Dice die);

        //Rolls all of the dice in the cup
        //Input: NA
        //Output: New values on all dice
        void rollCup();

        //Sum up the value of all of the dice
        //Input: NA
        //Output: Total value showing on all dice
        unsigned int sumDice();

        //Print the current value of the dice to the screen
        //Input: NA
        //Output: Screen information
        void printDice();

        //gets the sum of the dice of category cat (so if there are 6 dice and 4 of them are rolled at a 4, it gets 16 because 4*4 is 16)
        //input - the chosen category, which is from 1 to the maximum number of sides the dice has
        //outputs - returns the sum of the specified category
        int getSum(int cat);

        //scores the a specific category
        //inputs - a category number that is from 1 to the maximum number of sides the dice has
        //outputs - returns an int for the score of the category
        int scoreCat(int cat);

        //checks if there are three of a kind of one number
        //inputs - none
        //outputs - outputs a number that there was a three of a kind of
        int threeOfAKind();

        //checks if there are four of a kind of one number
        //inputs - none
        //outputs - outputs a number that there was a four of a kind of
        int fourOfAKind();

        //locks a dice so that it isn't changed with a roll
        //inputs - a dice object called dice
        //outputs - locks the dice in place
        void lockDice(int diceNum);
};


#endif