//dice.h file (taken and modified from Scott Griffith)
//Aaron Borjas
//CS171-1 CS1
//12/13/18

//CupDiceTest.cpp
//Scott Griffith - Whitworth University - CS171
//11/30/2018
//
// Testing function for the dice and cup object
// Interacts with the Cup and Dice objects to make sure they are working correctly

#include <iostream> //Needed for cout output and cin input
#include <ctime> //Needed to pull the current time for the random seed
#include <cstdlib> //Needed to access the srand() function to set the random seed
#include <string> //string functions and variable types
#include "dice.h" //Dice class definition
#include "cup.h" //Cup class definition

using namespace std;

int main (){
    //Set random see for the whole application. Based on the current time of execution
    srand(time(NULL));

    //START OF DICE TESTING
    //Initilize a 20 sided dice
    Dice myDice(20);

    cout << "Starting value of myDice: " << myDice.checkFace() << endl;
    cout << "Rolling myDice 10 times: " << endl << endl;

    for(int rollCt = 0; rollCt < 10; rollCt++){ //Loop 10 times. Roll myDice each time and print the new value
        cout << "Rolling myDice... ";
        myDice.roll();
        cout << " got a " << myDice.checkFace() << endl;
    }
    cout << endl;
    //END OF DICE TESTING

    //START OF CUP TESTING
    cout << "Starting to test the cup!" << endl;

    //Initilize our cup!
    //This will be an empty cup. We still need to fill it with dice
    Cup rollerCup;

    //Add 5x10 sided dice
    for(int diceCt = 0; diceCt < 5; diceCt++){
        rollerCup.addDice(Dice(6)); //Makes a new dice object, then imediately copies it into cup
    }

    cout << endl << "After filling cup, ";
    rollerCup.printDice();

    cout << "Mixing up the cup 10 times!" << endl;

    for(int cupCt = 0; cupCt < 3; cupCt++){ //Roll cup 10 times and show the result and the sum
        cout << "Shaking the cup... " << endl;
        rollerCup.rollCup();
        rollerCup.printDice();

        
        int lockDie; //placeholder for if you want to lock a die
        cout << "Do you want to lock a die? If yes, enter a number for the dice number. If not, then enter -1: ";
        cin >> lockDie; //gets user input
        rollerCup.lockDice(lockDie-1); //locking the die at lockDie-1
        while(lockDie >= 0) { //while user input is greater than or equal to 0
            cout << "Do you want to lock more? Enter the dice number if you want to lock more, or -1 if not: ";
            cin >> lockDie; //getting user input again
            rollerCup.lockDice(lockDie-1); //locking the die at lockDie-1
        }


        cout << "Current sum of cup: " << rollerCup.sumDice() << endl << endl; //sums the values of the cup
    }


    if(rollerCup.threeOfAKind() > 0) { //if there were three of a number
        cout << "You got three of a kind of " << rollerCup.threeOfAKind() << endl; //three of a kind of some number
        cout << "The total score for a three of a kind plus the extras is: " << rollerCup.sumDice(); //prints total
    }
    else if(rollerCup.fourOfAKind() > 0) { //if there were four of a number
        cout << "You got four of a kind of " << rollerCup.fourOfAKind() << endl; //four of a kind of some number
        cout << "The total score for a four of a kind of plus the extras is: " << rollerCup.sumDice();
    } 
    
    for(int i = 0; i < rollerCup.numberOfDice; i++) { //loops through the cup and asks if you want the score of the category of i
        int yesOrNo; //placeholder for user input
        cout << "Do you want to score the " << i+1 << " category? (1 for yes, -1 for no): ";  //asks if you want score of a category
        cin >> yesOrNo; //gets user input
        if(yesOrNo == 1) { //if user input is equal to 1
            rollerCup.scoreCat(i+1); //get the score of the category of i+1
        }
    }
    
    //END OF CUP TESTING   
}
