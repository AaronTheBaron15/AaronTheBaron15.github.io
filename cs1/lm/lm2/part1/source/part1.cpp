// part1.cpp
// CS171-1, CS1
// Aaron Borjas
// 9/21/2018
// description of project

#include <iostream> //Import cin, cout
using namespace std;

int main () {
    float firstNum; //initialize the floating point variable for the first number
    float secondNum; //initialize the floating point variable for the second number
   
    cout << "CS1 Super Calculator!" << endl; //print out "CS1 Super Calculator!" in the terminal.

    //this set of code asks for the first number and prints the value once it has been entered
    cout << "What is the first number? (press enter when done): "; //tells user what to enter
    cin >> firstNum; //gives the user a textbox to enter a value for firstNum and then applies that value to firstNum
    cout << "*user inputs " << firstNum << "*" << endl; //prints out what the value of firstNum is for future reference

    //this set of code asks for the second number and prints the value once it has been entered
    cout << "What is the second number? (press enter when done): "; //tells the user what to enter
    cin >> secondNum;//gives the user a textbox to enter a value for secondNum and then applies that value to secondNum
    cout << "*user inputs " << secondNum << "*" << endl; //prints out what the value of SecondNum is for future reference.

    //this statement adds firstNum and secondNum and prints out the solution
    cout << "The summation of " << firstNum << " and " << secondNum << " is " << firstNum+secondNum << endl; 

    //this statement subtracts secondNum from firstNum and prints out the result
    cout << "The difference of " << firstNum << " and " << secondNum << " is " << firstNum-secondNum << endl;
    
}