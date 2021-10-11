//part1.cpp
//CS171-1 CS1
//Aaron Borjas
//11/9/18
//array manipulation

#include <iostream>
#include <cstdlib> //rand()
#include <time.h> //time for srand
using namespace std;
const int arrLength = 6;
const int arrLength2 = 4;

//function printArray
//prints all the values of an integer array
//Inputs - integer array and a positive integer that represents length of the array
//outputs - prints the values of the array on one line, with a space seperating each line
void printArray(int arr[], int length) {
    for(int i = 0; i < length; i++) { //starts at the first index of the array and increments by one until it is greater than or equal to length
        cout << arr[i] << " "; //prints the the element of arr at index i, along with a space.
    }
}

//function swap from LM8 part 2
//takes two values and switches them, passing by reference.
//inputs - two integer variables that are passed by reference
//outputs - nothing, but changes the value of the first variable to the second, and vice versa
void swap(int arr[], int& first, int& second) {
    int placeholder = arr[first]; //so that both the values aren't both the same
    arr[first] = second; //the first value becomes the second
    arr[second] = placeholder; //the second value becomes the first
}

//function reverse
//reverses an array, first element goes to last and vice versa, second to second last and vice versa, etc.
//Inputs - Takes an integer array with a length of arrLength (6 elements) 
//Outputs - prints the reversed elements of the array that was given
void reverse(int arr[]) {
    int endIndex = arrLength-1; //the index of the final element of the array
    for(int i = 0; i < arrLength/2; i++) { //starts at 0 and increments by one until greater than or equal to arrLength/2 (which is 3)
        
        swap(arr[i], arr[endIndex]); //swaps the values of arr[i] and the end index
        endIndex--; //decrements endIndex, so it would go from 5 to 4 and so on.
    }
    printArray(arr, arrLength); //prints the array 
}

//function replaceOdd
//replaces any numbers of an array that are odd with twice the odd value, which should be even
//Inputs - takes an integer array with a length of arrLength (6 elements)
//Outputs - no return values, but prints an array with no odd elements.
void replaceOdd(int arr[]) {
    for(int i = 0; i < arrLength; i++) { //starts at 0 and increments by one until it is greater than or equal to arrLength
        if((arr[i])%2 != 0) { //if the element of arr at i is not equal to 0 if you use modulus on it...
            arr[i] = arr[i]*2; //multiply the element by two and then assign that value to arr[i]
        }
    }
    printArray(arr, arrLength); //print the array
}

//function replace
//replaces an element of an array at a given index with a number chosen by the user and shifts the elements at and after the index to the right
//Inputs - an integer array of length arrLength2 (4 elements), a positive integer that represents the index, and an integer that represents the new number to replace the element at index
//Outputs - prints an array with the same elements before the chosen index, but the chosen index is a new number and every element, including the element previously at index, is shifted to the right.
void replace(int arr[], int index, int newNum) {
    int replaceArray[arrLength2] = {0, 0, 0, 0}; //creates a placeholder array to assign values to later on.

    for(int i = 0; i < arrLength2; i++) { //starts at 0 and increments by one until it is greater than or equal to arrLength2
        if(i < index) { //if i is less than index...
            replaceArray[i] = arr[i]; //replaceArray at index i is equal to arr at index i
        }
        else if(i == index) { //otherwise, if i is equal to index...
            replaceArray[index] = newNum; //replaceArray at index is equal to newNum
        }
        else if(i > index) { //otherwise, if i is greater than index...
            replaceArray[i] = arr[i-1]; //replaceArray at index i is equal to arr at index i-1
        }
    }
    printArray(replaceArray, arrLength2); //print replaceArray
}

//function remove
//removes an element at a chosen index from an array and shifts the array to the left after
//Inputs - an integer array with the length of arrLength(6) and an an integer that represents the index
//Outputs - no return values, but prints an array where the chosen index is removed and the indicies after that are moved to the left
void remove(int arr[], int index) {
    int replaceArray[arrLength] = {0, 0, 0, 0, 0, 0}; //placeholder array to be used later

    for(int i = 0; i < arrLength-1; i++) { //i starts at 0 and increments by one until it is greater than or equal to arrLength-1 (5)
        if(i < index) { //if i is less than index...
            replaceArray[i] = arr[i]; //replaceArray at index i is equal to arr at index i
        }
        else if(i >= index) { //otherwise, if is greater than or equal to index...
            replaceArray[i] = arr[i+1]; //replaceArray at index i is equal to arr at index i+1
        }
    }
    replaceArray[arrLength-1] = 0; //replaceArray at the final element is 0

    printArray(replaceArray, arrLength); //print the array
}

//function randomNumGen from LM8 part 2
//creates a random number between a lower bound and higher bound
//inputs - two integers, the first lower than the second
//ouputs - a random integer between the lower bound and higher bound
int randomNumberGen(int lowerBound, int higherBound) {
    int randomNum; //placeholder for the random number

    randomNum = (rand() % (higherBound + 1)) + lowerBound; //randomNum is equal to a number between 0 and higherBound+1, plus Lowerbound 

    return randomNum; //return randomNum
}

int main() {
    srand(time(NULL));
    //========================================================================
    //REVERSING AN ARRAY (first element goes to last, last goes to first, etc)
    //========================================================================

    //makes a new array of length arrLength and gives it six random values between 0 and 25
    // int arr[arrLength] = {randomNumberGen(0, 25), randomNumberGen(0, 25), randomNumberGen(0, 25), randomNumberGen(0, 25), randomNumberGen(0, 25), randomNumberGen(0, 25)};

    // cout << "First array: " << endl; //says what is printing
    // printArray(arr); //prints the starting array
    // cout << endl << endl; //prints two new lines
    
    // cout << "Reversed Array: " << endl; //says what is printing
    // reverse(arr); //reverses the array and prints that

    //========================================================================
    //ENDS HERE
    //========================================================================


    //==========================================
    //DOUBLING EVERY ODD ELEMENT TO MAKE IT EVEN
    //==========================================

    //int oddTest[arrLength] = {1, 2, 3, 4, 5, 6}; //new array oddTest tests to test the function
    // cout << endl << endl; //two new lines

    // cout << "Turn odd incidies into even numbers twice their size" << endl; //says what is going on in this section
    // cout << "First array: " << endl;//says what will be printed
    // printArray(arr); //prints the starting array

    // cout << "replaced the odds: " << endl; //says what will be printed
    // replaceOdd(arr); //prints the array with no odd values
    //cout << endl << endl; //two new lines.
    //==========================================
    //ENDS HERE
    //==========================================

    //====================================================
    //REPLACE AT AN INDEX AND MOVE EVERYTHING TO THE RIGHT
    //====================================================
    // cout << "Replace at an index" << endl;

    // int rTwo[arrLength2] = {randomNumberGen(0, 25), randomNumberGen(0, 25), randomNumberGen(0, 25), randomNumberGen(0, 25)};
    // cout << "First array: " << endl;
    // printArray(rTwo, arrLength2);

    // int randIndex = randomNumberGen(0, 3);
    // int randNum = randomNumberGen(0, 25);
    // cout << endl << "Replacing arr[" << randIndex << "] (the " << randIndex+1 << " term) with " << randNum << " and moving stuff to the right: "  << endl;
    // replace(rTwo, randIndex, randNum);
    // cout << endl << endl;
    //====================================================
    //ENDS HERE
    //====================================================

    //========================================================
    //REMOVE ELEMENT AT INDEX AND MAKE REST OF ARRAY MOVE LEFT
    //========================================================
    cout << "Remove a random element of an array and shift the array to the left: " << endl;

    int randIndex = randomNumberGen(0, 5);

    int testArr[arrLength] = {randomNumberGen(0, 25), randomNumberGen(0, 25), randomNumberGen(0, 25), randomNumberGen(0, 25), randomNumberGen(0, 25), randomNumberGen(0, 25)};
    cout << "First array: " << endl;
    printArray(testArr, arrLength);
    cout << endl;

    cout << "Removing arr[" << randIndex << "] (the " << randIndex+1 << " element) from the array: " << endl;
    remove(testArr, randIndex);
    cout << endl << endl;

    //========================================================
    //ENDS HERE
    //========================================================

}