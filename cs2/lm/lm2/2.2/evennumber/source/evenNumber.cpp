//evennumber.cpp
//CS172-1 CS2
//Aaron Borjas
//2/18/19
//creates a class that represents only even numbers. Creates two of these numbers using the class, one that is 0 and another
//that is created based on user input. Then iterates from one to the next, printing all the even numbers from the first to second

#include <iostream>
#include "../headers/evennumber.h"
using namespace std;

//class constructor EvenNumber()
//creates an EvenNumber without input which starts at 0 and has a previous number of -2 and next number of 2
EvenNumber::EvenNumber() {
    currentNumber = 0;
    previousNumber = currentNumber-2;
    nextNumber = currentNumber+2;
}

//class constructor EvenNumber(int num)
//creates an EvenNumber with input of an even integer that has a previous number of num-2 and a 
//next number of num+2
EvenNumber::EvenNumber(int num) {
    while(!(num%2 == 0)) { //while num is not an even number
        cout << "Please enter an even number: "; //tells user what to enter
        cin >> num; //gets user input
    }
    currentNumber = num; //sets the current value of the EvenNumber to num
    previousNumber = currentNumber-2; //sets the previous value of the EvenNumber to num-2
    nextNumber = currentNumber+2; //sets the next value of the EvenNumber to num+2
}

//gets the value of the current number that is assigned to EvenNumber
//no inputs
//returns the current value of the EvenNumber
int EvenNumber::getValue() {
    return currentNumber;
}

//gets the value of the previous number relative to that which is assigned to EvenNumber
//no inputs
//returns the number preceding the current value of EvenNumber
int EvenNumber::getPrevious() {
    return previousNumber;
}

//gets the value of the next number relative to that which is assigned to EvenNumber
//no inputs
//returns the number after the current value of EvenNumber
int EvenNumber::getNextNumber() {
    return nextNumber;
}