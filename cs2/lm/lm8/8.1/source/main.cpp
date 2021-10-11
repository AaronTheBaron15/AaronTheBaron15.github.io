//main.cpp
//CS172-1 CS2
//Aaron Borjas
//4/10/19
//this file messes around with vectors and stacks, showing how they can be used in different ways

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

//takeBook takes a the first occurance of a desired number from a stack of numbers and then restacks the removed numbers back onto the stack
//inputs - a non-empty stack of ints which passes by reference and an int that is wanted to be removed from the stack
//outputs - returns the stack with the first occurance (going from the top) of the desired int removed
stack<int> takeInt(stack<int>& numStack, int num) {
    
    stack<int> tempStackBottom = numStack; //creates a new stack which is set to be equal to numStack
    stack<int> tempStackTop; //creates an empty stack 

    while(!(tempStackBottom.top() == num)) { //while the top value of tempStackBottom is not num
        tempStackTop.push(tempStackBottom.top()); //pushes the top value of tempStackBottom to tempStackTop
        tempStackBottom.pop(); //removes the top value of tempStackBottom
    }
    if(tempStackBottom.top() == num) { //if tempStackBottom's top value is num
        tempStackBottom.pop(); //remove that number from tempstackBottom
    }
    
    while(!tempStackTop.empty()) { //while tempStackTop is not empty
        tempStackBottom.push(tempStackTop.top()); //push the value from the top of tempStackTop to the top of tempStackBottom
        tempStackTop.pop(); //removes the top value of tempStackTop
    }    

    return tempStackBottom; //return the tempStackBottom stack
}

int main() {
    stack<int> numStack; //makes new stack with ints called numstack

    numStack.push(1); //pushes the number 1 to the stack
    numStack.push(2); //pushes the number 2 to the stack
    numStack.push(3); //pushes the number 3 to the stack
    numStack.push(4); //pushes the number 4 to the stack

    //prints the stack

    stack<int> tempStack = numStack;
    //you cannot access random indices of a stack because the only available element and index to modify is the last or "top" index

    cout << "Printing numStack..." << endl;
    while(!tempStack.empty()) { //while the stack of numbers is not empty
        cout << tempStack.top() << " "; //print the top (or last) number with a space afterwards
        tempStack.pop(); //drop the top number from the stack
    }

    cout << endl << endl; //two new lines

    vector<int> intVector; //makes new stack with ints called numstack

    intVector.push_back(5); //appends "5" to the end of the vector
    intVector.push_back(6); //appends "6" to the end of the vector
    intVector.push_back(7); //appends "7" to the end of the vector
    intVector.push_back(8); //appends "8" to the end of the vector

    //prints the vector
    //any random index of the vector can be accessed, as long as an element exists at that index
    cout << "Printing intVector..." << endl;
    for(int i = 0; i < intVector.size(); i++){
        cout << intVector.at(i) << " "; //prints the item at index i of the vector
    }
    
    cout << endl << endl;

    //==============================================================
    //creating a stack of ints and accessing an int inside the stack
    //==============================================================
    cout << "Doing something cool with stacks:" << endl;

    stack<int> intStack; //creates a stack called intStack

    //adds 0-9 to the stack
    for(int i = 0; i < 10; i++) { //iterates through the stack and assigns 10 values
        intStack.push(i); //pushes i to the end of the stack
    }

    stack<int> tempStack2 = intStack; //creates a temporary stack equal to intStack

    cout << "The stack starts off looking like this: " << endl;
    //you cannot access random indices of a stack because the only available element and index to modify is the last or "top" index
    while(!tempStack2.empty()) { //while the stack of numbers is not empty
        cout << tempStack2.top() << " "; //print the top (or last) number with a space afterwards
        tempStack2.pop(); //drop the top number from the stack
    }

    int userInput; //holds user input
    cout << "\nEnter a number to remove from the stack: ";
    cin >> userInput; //gets user input

    intStack = takeInt(intStack, userInput); //removes the first instance (from the top) of the number 5 from the stack

    stack<int> tempStack3 = intStack; //creates a new temporary stack equal to intStack

    cout << "\nTaking " << userInput << " from the the stack: " << endl;

    //you cannot access random indices of a stack because the only available element and index to modify is the last or "top" index
    while(!tempStack3.empty()) { //while the stack of numbers is not empty
        cout << tempStack3.top() << " "; //print the top (or last) number with a space afterwards
        tempStack3.pop(); //drop the top number from the stack
    }


    //=================================================================================================
    //THE FOLLOWING GRADE STATISTIC PROGRAM WAS TAKEN AND REVISED FROM MY LM6.2 GRADE STATISTIC PROGRAM
    //=================================================================================================

    cout << "\n\n===================" << endl;
    cout << "Grades with vectors" << endl;
    cout << "===================" << endl;
    float grade; //User Input

    //Make gradeArray
    vector<float> gradeArray;//creates a vector to contain the grades

    //Take user input
    cout << "\n\nEnter a grade (or negative to exit): "; //tells user what to enter
    cin >> grade; //gets user input for the grade

    while(grade >= 0){ //Loop until user inputs negative grade
        //add element to array
        gradeArray.push_back(grade); //pushes the new grade to the back of gradeArray

        //print out new array / element
        cout << "Entered grade: " << grade << endl;
        
        //Take user input
        cout << "Enter a grade (or negative to exit): ";
        cin >> grade;
    }

    for(int i = 0; i < gradeArray.size(); i++){ //iterates through gradeArray
        cout << "gradeArray[" << i << "] = " << gradeArray.at(i) << endl; //prints what gradeArray at index i is equal to
    }
}