//lm4_2.cpp
//CS172-1 CS2
//Aaron Borjas
//3/2/19
//this file creates four different recursive functions and implements them. 
//The first recursive function takes a number n and a character and prints that character n number of times. 
//The second takes a number and returns the sum of the number's digits.
//the third takes a number n and an exponent e and computes n^e.
//The final takes in a number n and computes the fibonacci sequence for the first n numbers
#include <iostream>
using namespace std;

//charNumTimes, which calls itself to print a character, charToRepeat, repeatNum number of times
//inputs - int repeatNum, which is a positive integer greater than zero, and charToRepeat, a single character that can by typed
//outputs - prints charToRepeat repeatNum number of times. eg is repeatNum is 5 and charToRepeat is X, it prints "XXXXX"
void charNumTimes(int repeatNum, char charToRepeat) {
    if(repeatNum == 0) { //if repeatNum is equal to zero
        return; //exit the recursive function
    }
    else { //otherwise, if repeatNum is not equal to zero
        charNumTimes(repeatNum-1, charToRepeat); //recursively call charNumTime, but on repeatNum-1 and charToRepeat
        cout << charToRepeat; //prints out the character to repeat
    }
}

//sumDigits, recursively sums the digits of a number, numToSum.
//sumDigits(123)
//        ->3+sumDigits(12) = 3+2+1 = 3
//                ->2+sumDigits(1) = 2+1 = 3
//                      ->1+sumDigits(0) = 1 + 0
//inputs - numToSum, a positive integer that is greater than or equal to zero
//outputs - returns the sum of the digits of numToSum
int sumDigits(int numToSum) { 
    if(numToSum == 0) { //base case, if numToSum is equal to zero
        return 0;//return zero
    }
    else { //otherwise if numToSum is not equal to zero
        int digit = 0; //creates an integer called digit, holds a single digit from numToSum
        digit = numToSum%10; //sets digit to numToSum % 10, which grabs the last digit of numToSum and sets it to digit
        return digit+sumDigits(numToSum/10); //returns digit, the last digit of numToSum, plus a recursive call to sumDigits of numToSum/10. modifies numToSum so there is not a stack overflow error
    }
}

//rPower, which is a function that raises a base number to a certain power recursively
//inputs - two positive integers, the first of which is the base of the exponent, or the number that multiplies by itself, and the exponent, which is the number of times the base multiplies by itself
//outputs - returns the value of base to the power of exponent
int rPower(int base, int exponent) {
    if(exponent == 0) { //if the exponent is equal to zero
        return 1; //return 1 (because any number to the zeroth power is 1)
    }
    else { //otherwise if the exponent is not equal to zero
        return base*(rPower(base, exponent-1)); //returns base times a recursive call to rPower, using the default base as the new base and exponent-1 as the new exponent
    }
}

//fibonacci is a function that returns the value of the maxIndexth term of the fibonacci sequence. for example, if I entered 8, the value that would be returned is 13)
//inputs - maxIndex, the number that is the term of the desired max term of the fibonacci sequence
//outputs - prints out the of the fibonacci value of the maxIndexth term of the fibonacci sequence (eg for the sixth index the fibonacci value is 5 (the fifth index is 3, and the fourth is 2, 2+3 = 5)
int fibonacci(int maxIndex) {
    //cout << (fibonacci(maxIndex-1) + fibonacci(maxIndex-2)) << " ";
    if(maxIndex == 1) {//if maxIndex is equal to one (base case pt 1)
        return 1; //return one
    }
    else if(maxIndex == 0) { //otherwise if maxIndex is equal to zero (base case pt 2)
        return 0;
    }
    else {
        return fibonacci(maxIndex-1) + fibonacci(maxIndex-2); //the fibonacci number at any term greater than 2 is the fibonacci number of the previous term (maxIndex -1) plus the term two terms ago (maxIndex -2)
    }
}

int main() {

    charNumTimes(5, 'X');// prints out the character 'X' five times

    cout << endl << endl;

    int digits = 123; //makes a new integer to hold user input of digits
    // cout << "Enter a number to sum the digits of: "; //tells user what to enter
    // cin >> digits; //gets user input

    cout << "The sum of digits " << digits << " is: " << sumDigits(digits); //says what the sum of the digits input by the user is

    cout << endl << endl; //new line

    int exponent = 8; //makes a new integer to hold the exponent
    // cout << "Enter an exponent to be the exponent of 2^(exponent): "; //tells user what to enter
    // cin >> exponent; //gets user input

    
    cout << "2^(" << exponent << ") is: " << rPower(2, exponent) << endl; //says what 2^exponent is, calling rPower(int base, int exponent), a recursive function

    cout << endl; //new line

    int maxIndex; //creates an integer to hold the maxIndex for the fibonacci sequence
    cout << "Enter a number to compute the fibonacci sequence to: "; //tells user what to enter
    cin >> maxIndex; //gets user input

    //these next few lines print the fibonacci sequence
    int i = 0; //makes a new integer called i and sets it to zero, to be incremented 
    while(i < maxIndex) { //while i is less than maxIndex
        cout << fibonacci(i) << " "; //prints the fibonacci at index i
        i++; //increments i by one
    }
}