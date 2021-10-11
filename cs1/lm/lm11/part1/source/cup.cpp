//dice.h file (taken and modified from Scott Griffith)
//Aaron Borjas
//CS171-1 CS1
//12/13/18

//Implimentation of Cup Object
//Scott Griffith - Whitworth University - CS171
//11/28/2018
//
// Class to hold a bunch of dice (utilizes dice.h)
// Cup can roll all dice / Print all dice / Sum all dice

#include "cup.h"
#include "dice.h"
#include <iostream>
using namespace std;

//Constructor for Cup class
//Sets up numberOfDice to zero
//Dice must be added individually
//Input: NA
//Output: Valid cup
Cup::Cup(){
    numberOfDice = 0;
}

//Method to add dice to the cup
//This copys dice, so they can go out of scope in the calling function
//Input: die that will be added to the cup
//Output: True if die was added, false if could not be added
bool Cup::addDice(Dice die){
    if(numberOfDice == SIZE_OF_CUP){ //Check to see if we can add things to the cup
        cout << "CUP FULL!" << endl;
        return false; //Return false! Cup is full
    } else {
        setOfDice[numberOfDice] = die; //Copy in the die, if numberOfDice is zero first die will go in index 0!
        numberOfDice++; //Incrament! We just added a die
        return true; //Succeffully added that die
    }
}

//Rolls all of the dice in the cup
//Input: NA
//Output: New values on all dice
void Cup::rollCup(){
    for(int i = 0; i < numberOfDice; i++){ //Iterate through cup and roll each dice
        if(setOfDice[i].isItLocked) {
            cout << "Dice at space " << i+1 << " is locked!" << endl;
        }
        else {
            setOfDice[i].roll();
        }
    }
}

//Sum up the value of all of the dice
//Input: NA
//Output: Total value showing on all dice
unsigned int Cup::sumDice(){
    unsigned int sum = 0; //Summation value, starts at zero
    for(int i = 0; i < numberOfDice; i++){ //Iterate through all dice to get sum
        sum += setOfDice[i].checkFace(); //Add value of dice to sum
    }
    return sum;
}

//Print the current value of the dice to the screen
//Input: NA
//Output: Screen information
void Cup::printDice(){
    cout << "Current cup status: ";

    for(int i = 0; i < numberOfDice; i++){ //Iterate through setOfDice
        cout << " d" << i+1 << ": " << setOfDice[i].checkFace() << " "; 
    }
    cout << endl;
}

//gets the sum of the dice of category cat (so if there are 6 dice and 4 of them are rolled at a 4, it gets 16 because 4*4 is 16)
//input - the chosen category, which is from 1 to the maximum number of sides the dice has
//outputs - returns the sum of the specified category
int Cup::getSum(int cat) {
    int sum = 0; //sum starts off equaling 0
    for(int start = 0; start < numberOfDice; start++) { //start begins at 1 and goes up by one until it is greater than or equal to numberOfDice
        if(setOfDice[start].checkFace() == cat) { //if the dice number start in the setOfDice array is equal to category
            sum += setOfDice[start].checkFace(); //add that number to sum
        }
    }
    return sum; //return sum
}

//scores the a specific category
//inputs - a category number that is from 1 to the maximum number of sides the dice has
//outputs - returns an int for the score of the category
int Cup::scoreCat(int cat) {
    return getSum(cat);
}


void Cup::lockDice(int diceNum) {
    setOfDice[diceNum].isItLocked = true;
}

//returns true or false depending on if there was a three of a kind or four of a kind
//inputs - none
//outputs - true or false depending on if the setOfDice has a three of a kind or four of a kind
int Cup::threeOfAKind() {
    int recurNum = 1; //sets the number to check for three of a kind of to one
    for(int i = 0; i < numberOfDice; i++) { //i starts as 0 and goes up by one until it reaches the number of dice in the cup
        int howManyTimes = 0; //the number of times the number recurs
        if(setOfDice[i].checkFace() == recurNum) { //if the dice in the cup is equal to the recurring number
            howManyTimes++; //adds one to howManyTimes
        }

        if(howManyTimes > 3) { //if howManyTimes is greater than 3
            return recurNum; //return true
        }
        else if((numberOfDice/howManyTimes > numberOfDice/2) && howManyTimes > 3) { //if number of dice divided by howManyTimes is greater than numberOfDice over 2 and if howManyTimes is greater than 3
            i = -1; //sets i back to 0 (after the loop ends i increments back to 0)
            recurNum++; //adds one to recurNum to check the next number for recursion
        }
    }
    return -1;
}

//checks if there are four of a kind of one number
//inputs - none
//outputs - outputs a number that there was a four of a kind of
int Cup::fourOfAKind() {
    int recurNum = 1; //sets the number to check for three of a kind of to one
    for(int i = 0; i < numberOfDice; i++) { //i starts as 0 and goes up by one until it reaches the number of dice in the cup
        int howManyTimes = 0; //the number of times the number recurs
        if(setOfDice[i].checkFace() == recurNum) { //if the dice in the cup is equal to the recurring number
            howManyTimes++; //adds one to howManyTimes
        }

        if(howManyTimes > 4) { //if howManyTimes is greater than 3
            return recurNum; //return true
        }
        else if((numberOfDice/howManyTimes > numberOfDice/2) && howManyTimes > 4) { //if number of dice divided by howManyTimes is greater than numberOfDice over 2 and if howManyTimes is greater than 3
            i = -1; //sets i back to 0 (after the loop ends i increments back to 0)
            recurNum++; //adds one to recurNum to check the next number for recursion
        }
    }
    return -1;
}