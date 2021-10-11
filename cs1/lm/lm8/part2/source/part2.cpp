//part2.cpp
//CS171-1 CS1
//Aaron Borjas
//11/7/18
//sorts numbers with an array by passing by reference.

#include <iostream> //cout
#include <cstdlib> //rand()
#include <time.h> //time for srand()
using namespace std;

const int arrLength = 4; //the length of the array is 4 elements.

//function printArray
//prints the values of an array of length arrLength in one line
//inputs - an integer array with length of arrLength (int arr[arrLength])
//outputs - prints each element of the array with a space after it (no return value)
void printArray(int arr[]) {
    for(int i = 0; i < arrLength; i++) { //starts at element 0 in the array and increments by one until the end of the array
        cout << arr[i] << " "; //print out the element of the array at i, plus a space
    }
}

//function highestNum
//finds the highest number of an array and returns that number
//inputs - an integer array with length of arrLength (int arr[arrLength])
//outputs - the highest value inside the array (integer)
int highestNum(int arr[]) {
    int highestValue = 0; //placeholder for highest value in the array
    for(int i = 0; i < arrLength; i++) { //loops over all the elements in the array starting at zero and incrementing by one until arrLength
        if(arr[i] > highestValue) { //if the value of array at index i is greater than highestValue...
            highestValue = arr[i]; //the highest value is assigned to the element at the current index
        }
    }
    return highestValue; //return the highest value of the array
}

//function lowNum
//finds the lowest number of an array with a length of arrLength
//inputs - integer array of length arrLength (int arr[arrLength])
//outputs - the lowest number of the array (integer)
int lowNum(int arr[]) {
    int lowestCounter = highestNum(arr); //the lowestNumber, from what is already known, is the highestNumber of the array
    for(int i = 0; i < arrLength; i++) { //starts at 0 and increments by one until arrLength
        if(arr[i] < lowestCounter) {  //if the element of arr at i is less than the current lowest number...
            lowestCounter = arr[i]; //the new lowest number is the element of the array at i
        }
    }
    return lowestCounter; //returns the lowest number of the array
}

//function swap
//takes two values and switches them, passing by reference.
//inputs - two integer variables that are passed by reference
//outputs - nothing, but changes the value of the first variable to the second, and vice versa
void swap(int& first, int& second) {
    int placeholder = first; //so that both the values aren't both the same
    first = second; //the first value becomes the second
    second = placeholder; //the second value becomes the first
}

//function sortNumber
//takes four integer values, passed by reference, and sorts them in ascending order
//inputs - four integers, all passed by reference. The highest number must be positive
//outputs - no return value, but prints the array of the sorted values and changes each input to its corresponding element in 
//the array (for example, num1 = count[0] ... num4 = count[3])
void sortNumber(int& num1, int& num2, int& num3, int& num4) {

    int count[arrLength] = {num1, num2, num3, num4}; //makes an array with each value equaling one of the inputs

    int lowestNum = lowNum(count); //lowNum is equal to the function lowNum() with the array count as a parameter

    int maxNum = highestNum(count); //maxNum is equal to the function highestNum() with the array count as a parameter

    for(int i = 0; i < arrLength; i++) { //the index starts at 0 and increments by one until it reaches arrLength

        if(count[i] == maxNum) { //if the value of count at index i is equal to the maxNum of count...
            swap(count[i], count[arrLength-1]); //swap the values of count at index i with count at the final index (the highest number goes to the end)
            if(i == 0) { //if the maxNum was at 0...
                i--; //decrement i (so that the new value at count[0] can be changed based on its relation to the other numbers)
            }

            //testing how this step works
            // cout << "first if curret configuration: ";
            // printArray(count);
            // cout << endl;
        }
        else if(count[i] == lowestNum) { //if the count at index i is equal to the lowestNum of count...
            swap(count[i], count[0]); //swap the values of count at index i with count at index 0 (the lowest number should be at index 0)

            //testing how this step works
            // cout << "second if curret configuration: ";
            // printArray(count);
            // cout << endl;
        }
        else if(count[i] > count[i+1]) { //if the count at index i is greater than the count at index i+1...
            swap(count[i], count[i+1]); //swap the value of count at index i with the value of count at index i+1
            i--; //decrement i (so that the new value at count [i] can be evaluated relating to the other numbers)

            //testing how this step works
            // cout << "third if curret configuration: ";
            // printArray(count);
            // cout << endl;
        }
        else if(count[i+1] > count[i+2]) { //if the count at index i+1 is greater than the count at index i+2...
            swap(count[i+1], count[i+2]); //swap the count at index i+1 with the count at index i+2
            i--; //decrement i (so that the new value at count[i] can be evaluated relating to the other numbers)
            
            //testing how this step works
            // cout << "fourth if curret configuration: ";
            // printArray(count);
            // cout << endl;
        }
    }
    //i shouldn't need this if swap changes the values correctly
    num1 = count[0];
    num2 = count[1];
    num3 = count[2];
    num4 = count[3];
    
    int finalArr[arrLength] = {num1, num2, num3, num4}; 
    printArray(finalArr);
}

//function randomNumGen
//creates a random number between a lower bound and higher bound
//inputs - two integers, the first lower than the second
//ouputs - a random integer between the lower bound and higher bound
int randomNumberGen(int lowerBound, int higherBound) {
    int randomNum; //placeholder for the random number

    randomNum = (rand() % (higherBound + 1)) + lowerBound; //randomNum is equal to a number between 0 and higherBound+1, plus Lowerbound 

    return randomNum; //return randomNum
}

int main() {
    srand(time(NULL)); //setting the seed for rand()

    //four random numbers
    int randomNum1 = randomNumberGen(50,100);
    int randomNum2 = randomNumberGen(200, 350);
    int randomNum3 = randomNumberGen(-50, 0);
    int randomNum4 = randomNumberGen(-20, 50);

    int count[arrLength] = {randomNum1, randomNum2, randomNum3, randomNum4}; //making a new array containing each randomNum

    //cout << "Lowest num of count is: " << lowNum(count) << endl;
    cout << "The initial array: " << endl; //lets the user know what is being printed
    printArray(count); //prints the initial array
    cout << endl << endl; //makes two new lines

    cout << "The sorted array: " << endl; //tells the user what is being printed
    sortNumber(randomNum1, randomNum2, randomNum3, randomNum4); //sorts the four random numbers
    cout << endl << endl; //makes two new lines.

    cout << "the randomNums have been reassigned in ascending order..." << endl; //saying what is being printed

    //confirming that each randomNum had its value reassigned
    cout << "randomNum1: " << randomNum1 << endl;
    cout << "randomNum2: " << randomNum2 << endl;
    cout << "randomNum3: " << randomNum3 << endl;
    cout << "randomNum4: " << randomNum4 << endl;
}