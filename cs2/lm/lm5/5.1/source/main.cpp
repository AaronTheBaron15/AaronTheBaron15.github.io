//main.cpp
//CS172-1 CS2
//Aaron Borjas
//3/6/19
//this file creates a binary search algorithm using recursion, then uses this to sort and fill an array of 100 terms
//this code also compares two integer arrays of the same length and sees if they are filled with the same exact integers
#include <iostream>
#include <array>
#include <ctime>
using namespace std;

const int arrayLength = 100;

//binarySearch, which searches a sorted array of integers for a specific number and returns the index of the number. if the number does not exist, returns the negative index of where it should be
//inputs - an integer array, whose length is determinded by a start point and end point (indeces), and an integer desiredNum that is the number being searched for in the array
//outputs - returns the index of the desired number, but if the number is not in the array, prints where it would go
int binarySearch(int arr[], int start, int end, int desiredNum) {
    int midIndex = ((end-start)/2)+start;//the middle index is equal to end index minus start index, divided by two, and then addings start index to that value
    if(end < start) {
        return -1*(start+1); //otherwise if the number is not in the array, return the "negative" index of the number (instead of 0 indexing, it indexes to -1. for example, the negative indeces of the array are -1, -2, -3, -4, etc.)
    }
    else if(arr[midIndex] < desiredNum) { //if the array at midIndex is less than desiredNum
        return binarySearch(arr, midIndex+1, end, desiredNum); //check the upper half of the array from midIndex+1 (since we already "searched" the mid index) to the end index
    }
    else if(arr[midIndex] > desiredNum) { //otherwise if the array at midIndex is greater than desired num, 
        return binarySearch(arr, start, midIndex-1, desiredNum); //check the lower half of the array from start to midIndex-1 (since we already checked the mid index)
    }
    else if(arr[midIndex] == desiredNum) { //otherwise, if array at midIndex is equal to the desired number
        return midIndex; //return the desired number
    }
    return 0;
}

//insertElement, which is a function that inserts a given number into a certain position of an array with a predetermined length
//inputs - three integers, pos is the index of where the value is to be placed (positive), value is the value to put into the array, and length is the length of the array. The last input is an array of integers called arr
//outputs - changes the values of the array and inserts the chosen value into the chosen position
void insertElement(int pos, int value, int arr[], int length) {
    for(int i = length-1; i > pos; i--) { //iterates through the array
        arr[i] = arr[i-1]; //sets the value of the array at index i to the value of the array at index i-1
        //cout << "arr[" << i << "] is: " << arr[i] << endl;
    }
    arr[pos] = value; //sets the value of array at index pos to value
}

//sortArray is a function that sorts an array using a binary search to figure out where each number goes
//inputs - an array of integers that is UNSORTED!!!! and length of the array that is a positive integer
void sortArr(int arr[], int length) {
    int sortedArr[arrayLength] = { 0 }; //creates a sorted array of length arrayLength, which is filled with zeros
    sortedArr[0] = arr[0];//the first value of sortedArr is set to the first value of arr
    //cout << "sorted arr[0] is: " << sortedArr[0] << endl; //bug testing
    int incrementor = 0; //an integer called incrementor which increments through the course of the function

    for(int i = 1; i < length; i++) { //iterates through first arr
        int index = binarySearch(sortedArr, 0, incrementor, arr[i]); //creates an integer called index, which is the index where the value of arr[i] goes inside a subsection of the sorted array, which is from 0 to incrementor
        //cout << "Index is: " << index << endl; //bug testing
        if(index < 0) { //if index is less than zero
            index = -1*(index+1);//changes index to an actual index of the array
            insertElement(index, arr[i], sortedArr, length); //inserts the value of arr[i] into the sorted array at index index
        }
        else { //if index is greater or equal to zero
            insertElement(index, arr[i], sortedArr, length); //inserts the value of arr[i] into the sorted array at index index
        }

        incrementor++; //increments the incrementor

        //bug testing
        // cout << "What does sorted arr look like?: " << endl; 
        // for(int i = 0; i < length; i++) {
        //     cout << sortedArr[i] << " ";
        // }
        // cout << endl;

    }
    for(int i = 0; i < length; i++) { //iterates through the arrays
        arr[i] = sortedArr[i]; //sets array at index i to the value of sorted array at index i
    }
}

//isSorted is a function that returns true or false depending on whether or not a given array is sorted
//inputs - an integer array called arr, which can be either unsorted or sorted. Along with that, an integer that is positive called length, which is the length of the array
//outputs - returns true or false depending on if the array is sorted
bool isSorted(int arr[], int length) {
    for(int i = 0; i < length-1; i++) { //iterates through the array, excluding the final index
        if(arr[i] > arr[i+1]) { //if the array at index i is greater than array at index i+1
            return false; //return false
        }
    }
    return true; //return true
}

//unSortCompare is a function that compares two unsorted arrays and returns true or false depending on if the arrays are not similar. also prints out the different numbers, if the arrays are not similar
//inputs - two integer arrays that are to be compared, both of which are filled with numbers and MUST BE UNSORTED. These two arrays must be the same size
//outputs - returns true or false depending on if they arrays are the same, but if the arrays are different it prints the numbers that are different
bool unSortCompare(int arr1[], int arr2[]) {
    bool check = true; //creates a boolean called check which is set to true by default

    cout << "Sorting the arrays to compare the numbers..." << endl;//says whats going to happen

    sortArr(arr1, arrayLength); //sorts the first array
    sortArr(arr2, arrayLength); //sorts the second array

    //bug testing
    // for(int i = 0; i < arrayLength; i++) { //iterates through the array
    //     cout << arr1[i] << " "; //prints the values of the array
    // }
    // cout << endl << endl;
    // for(int i = 0; i < arrayLength; i++) { //iterates through the array
    //     cout << arr2[i] << " "; //prints the values of the array
    // }

    for(int i = 0; i < arrayLength; i++) { //iterates through the array
        if(arr1[i] != arr2[i]) { //if array one at index  i is not equal to arr two at index i
            cout << arr1[i] << " is not the same as " << arr2[i] << endl; //prints the two numbers compared
            check = false;//sets check to false (so that the loop doesn't stop right then and there and all the numbers are printed)
        }
    }
    return check; //return check
}

//fillArray is a function that fills an array of a given length with random numbers
//inputs - takes in an array of integers, an integer that is the length of that array, and an integer that suggests the "mode" used to fill the array
//outputs - mode 1: prints the numbers in the array, and fills the array with numbers. Mode 2: fills and prints array with numbers from 0 to arrayLength. Mode 3: fills and prints array with numbers from arrayLength to 0
void fillArray(int arr[], int length, int mode) {
    if(mode == 1) { //fills array randomly
        for(int i = 0; i < length; i++) { //iterates through myArr
            arr[i] = i + ((rand()%100) + 1); //sets the value of myArr to i+ a random number from 1 to 100
            cout << arr[i] << " "; //prints the value of myArr at index i
        }
        cout << endl << endl; //new line
    }
    else if(mode == 2) { //if mode is two (fills array from 0 to arrayLength)
        for(int i = 0; i < length; i++) { //iterates through testArrOne
            arr[i] = i; //sets the value of testArrOne at index i to i
            cout << arr[i] << " "; //prints the numbers
        }
        cout << endl << endl;
    }
    else if(mode == 3) { //fills and prints the array with numbers from arrayLength to zero
        for(int i = length; i > 0; i--) { //iterates through testArrTwo
            arr[i] = (length) - i; //sets the value of testArrTwo at index i to the max index minus i (which should create an array of numbers going down from arrayLength to zero)
            cout << arr[i] << " "; //prints the numbers
        }
        cout << endl << endl;
    }
}

//checkIfSorted is a function that is a helper function for isSorted
//inputs - takes in an integer array that has numbers in it and an integer that is the length of the array
//outputs - no returns, but prints prints if the array is sorted
void checkIfSorted(int arr[], int length) {
    cout << "Is the array sorted? Checking..." << endl;//says whats going on
    if(isSorted(arr, length)) { //if the array is sorted
        cout << "The array is sorted!" << endl; //say that the array is sorted
    } 
    else { //if the array is not sorted
        cout << "The array is not sorted :(" << endl; //says that the array is not sorted
    }
}

//printArr is a function that prints all the values of the array
//inputs - takes in an integer array that has numbers in it and an integer that is the length of the array
//outputs - prints the numbers in the array
void printArr(int arr[], int length) {
    for(int i = 0; i < length; i++) { //iterates through the array
        cout << arr[i] << " "; //prints the values of the array
    }
    cout << endl << endl; //makes two new lines
}

//checkUnsorted is a helper function for unSortCompare, and checks if two unsorted arrays are the same
//inputs - two different arrays of integers
//outputs - prints whether the two arrays are the same or not
void checkUnsort(int arr1[], int arr2[]) {
    if(unSortCompare(arr1, arr2)) {//checks if the arrays are similar
        cout << "The two arrays are the same!" << endl; //says that the arrays are the same
    } 
    else {
        cout << "The arrays are not the same!" << endl;//says that the arrays are not the same
    }
    cout << endl << endl;
}

int main() {
    srand(time(NULL));


    int myArr[arrayLength]; //creates a new array that is called myArr and has a length of arraylength 

    fillArray(myArr, arrayLength, 1); //fills the array and prints the numbers in it

    //==============================================
    //checking if the array is sorted and sorting it
    //==============================================

    checkIfSorted(myArr, arrayLength);
    
    printArr(myArr, arrayLength); //prints the array

    cout << endl << "The array is being sorted..." << endl; //says whats going on
    sortArr(myArr, arrayLength); //sorts the array
    
    printArr(myArr, arrayLength); //prints the array

    //checks if the array is sorted
    cout << "Is the array sorted? Checking..." << endl; //says whats going on
    checkIfSorted(myArr, arrayLength);

    cout << endl << endl;

    //============================================
    //checking if the unsorted arrays are the same
    //============================================


    int arrOne[arrayLength]; //creates a new array that is called myArr and has a length of arraylength 

    fillArray(arrOne, arrayLength, 1); //fills arrOne

    int arrTwo[arrayLength]; //creates a new array that is called myArr and has a length of arraylength 

    fillArray(arrTwo, arrayLength, 1); //fills arrTwo

    cout << "Are these two arrays the same? Checking..." << endl;
    checkUnsort(arrOne, arrTwo); //checks if the two unsorted arrays are the same

    //=========================================================
    //checking if two arrays with the same numbers are the same
    //=========================================================

    int testArrOne[arrayLength]; //creates a new integer array with length of arrayLength
    fillArray(testArrOne, arrayLength, 2); //fills testArrOne with mode 2 (zero to arrayLength)

    int testArrTwo[arrayLength];//creates a new integer array with length of arrayLength
    fillArray(testArrTwo, arrayLength, 3); //fills testArrTwo with mode 3 (arrayLength to zero)

    checkUnsort(testArrOne, testArrTwo); //checks if the unsorted arrays are the same

}