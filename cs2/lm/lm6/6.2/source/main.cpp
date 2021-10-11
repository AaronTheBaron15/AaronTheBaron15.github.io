//main.cpp
//CS172-1 CS2
//Aaron Borjas
//4/1/19
//this is a program that makes a basic grade statistic program using dynamic memory. The average, median, mode, highest,
//and lowest values are all found. The median is found using binarySearch, insertElement, and sortArr from lm5.1

#include <iostream>
using namespace std;

const int arrayLength = 10;

//======================================================================================================================================
//binarySearch, sortArr, and insertElement are created by me and implemented from LM5.1. These are used for finding the median of grades
//======================================================================================================================================

//binarySearch, which searches a sorted array of integers for a specific number and returns the index of the number. if the number does not exist, returns the negative index of where it should be
//inputs - an integer array, whose length is determinded by a start point and end point (indeces), and an integer desiredNum that is the number being searched for in the array
//outputs - returns the index of the desired number, but if the number is not in the array, prints where it would go
int binarySearch(float arr[], int start, int end, float desiredNum) {
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
void insertElement(int pos, float value, float arr[], int length) {
    for(int i = length-1; i > pos; i--) { //iterates through the array
        arr[i] = arr[i-1]; //sets the value of the array at index i to the value of the array at index i-1
    }
    arr[pos] = value; //sets the value of array at index pos to value
}

//sortArray is a function that sorts an array using a binary search to figure out where each number goes
//inputs - an array of integers that is UNSORTED!!!! and length of the array that is a positive integer
//outputs - sorts the array of integers
void sortArr(float arr[], int length) {
    // float sortedArr[length] = { 0 }; //creates a sorted array of length arrayLength, which is filled with zeros
    float * sortedArr = new float[length];
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
    }
    for(int i = 0; i < length; i++) { //iterates through the arrays
        arr[i] = sortedArr[i]; //sets array at index i to the value of sorted array at index i
    }
    delete [] sortedArr;
}

int main(){
    //====================This section is from classdata (172/lm6/s1_dynamicArray)======================
    //comments were added as I went through, to make sure i understood it
    float grade; //User Input
    float * gradeArray = NULL; //creates a float pointer that is pointing to null, will be used to point to where the grade array is located
    float * oldArray = NULL;//creates a  float pointer that points to where the old array was located, since we only want two arrays at a time
    int sizeOfGA = 0;

    //Make gradeArray
    gradeArray = new float[0];//creates a dynamically allocated array of floats that starts with a size of zero

    //Take user input
    cout << "Enter a grade (or negative to exit): "; //tells user what to enter
    cin >> grade; //gets user input for the grade

    while(grade >= 0){ //Loop until user inputs negative grade
        //add element to array
        oldArray = gradeArray; //holds onto the previous array so it doesn't get lost
        gradeArray = new float[++sizeOfGA]; //creates a new grade array of floats with a size of one plus the previous size of gradeArray
 
        for(int i = 0; i < sizeOfGA-1 ; i++){ //iterates through gradeArray
            gradeArray[i] = oldArray[i]; //sets the value of gradeArray (the new one) to the value of oldArray(the old gradeArray)
        }

        gradeArray[sizeOfGA-1] = grade; //sets the last value of gradeArray to grade
        delete [] oldArray; //deletes oldArray because we do not need it anymore

        //print out new array / element
        cout << "Entered grade: " << grade << endl;
        
        //Take user input
        cout << "Enter a grade (or negative to exit): ";
        cin >> grade;
    }

    for(int i = 0; i < sizeOfGA; i++){ //iterates through gradeArray
        cout << "gradeArray[" << i << "] = " << gradeArray[i] << endl; //prints what gradeArray at index i is equal to
    }
    //====================end of section from classdata (172/lm6/s1_dynamicArray)======================

    //calculating statistics

    //average
    cout << endl << "=================================\nFinding the average of gradeArray\n=================================" << endl;

    float sum = 0;//new float called sum, holds onto the sum of the numbers of gradeArray
    for(int i = 0; i < sizeOfGA; i++) { //iterates through gradeArray
        sum += gradeArray[i]; //sets sum to the previous value of sum plus gradeArray at index i
        //cout << "Sum is: " << sum << endl; //making sure sum is right
    }

    cout << "The average of the " << sizeOfGA << " grades is: " << sum/sizeOfGA << endl; //prints the average of the gradeArray, which should be sum/sizeOfGA

    //median
    cout << endl << "================================\nFinding the median of gradeArray\n================================" << endl;

    sortArr(gradeArray, sizeOfGA);//sorts the grade array

    for(int i = 0; i < sizeOfGA; i++) {//iterates through the array
        cout << gradeArray[i] << " ";  //prints the gradeArray at index i with a space after
    }
    cout << endl; //new line

    if((sizeOfGA%2) == 0) { //if the array has an even number of elements
        //there are two medians if the array length is even
        float median1 = gradeArray[(sizeOfGA-1)/2]; //set the first median to the value of gradeArray at the left middle index 
        float median2 = gradeArray[(sizeOfGA+1)/2]; //set the second median to the value of gradeArray at the right middle index

        //prints the left and right medians, as well as the actual median that was calculated with the left and right medians
        cout << "The median is the average of " << median1 << " and " << median2 << ", which is: " << (median1+median2)/2 << endl;
    }
    else { //if the array has an odd number of elements
        cout << "The median is: " << gradeArray[(sizeOfGA)/2] << endl; //print the item of the grade array at the middle index
    }

    //mode - gets the lowest mode. if there are two numbers, say 60 and 100, that occur 6 times each, 60 will be printed as it is the lower of the two
    cout << endl << "==============================\nFinding the mode of gradeArray\n==============================" << endl;
    //the array is sorted from calculating the median, which makes this task easier

    int mostCommon = 1; //this is representing the mode of the grades
    int maxCount = 1; //the amount of times the mostCommon number has appeared
    int start = gradeArray[0]; //integer to represent the start of a series of a number, begins with zero
    int counter = 1; //counts the number of appearances of the current item in the array

    for(int i = 1; i < sizeOfGA; i++) { //iterates through the gradeArray
        if(gradeArray[i] == start) { //if the grade at i is equal to the grade at start
            counter++; //increment counter
        }
        else { //if the grade at i is not equal to start
            if(counter >= maxCount) { //if counter is greater than than maxCount
                maxCount = counter; //set maxCount to counter
                mostCommon = start; //set mostCommon (the mode) to the value that was being incremented
                // cout << "maxCount: " << maxCount << " mostCommon: " << mostCommon << endl;
            }
            counter = 1; //sets counter back to zero
            start = gradeArray[i]; //sets start to grade array at index i
        }
    }

    cout << "The mode of the grades is: " << mostCommon << " with " << maxCount << " occurrances" << endl;

    //highest grade
    cout << endl << "=======================================\nFinding the highest grade of gradeArray\n=======================================" << endl;
    int highestNum = 0;
    int highestIndex = 0;

    for(int i = 0; i < sizeOfGA; i++) { //iterates through the array
        if(gradeArray[i] >= highestNum) { //if gradeArray at index i is greater than or equal to highestNum
            highestNum = gradeArray[i]; //set highestNum to gradeArray at index i
            highestIndex = i;//set highestIndex to i;
        }
    }

    cout << "The highest grade is: " << highestNum << " which is at index " << highestIndex << endl;

    //lowest grade
    cout << endl << "=======================================\nFinding the lowest grade of gradeArray\n=======================================" << endl;
    int lowestNum = 10000; //sets lowest num to 10000 so that any grade should theoretically be lower
    int lowestIndex = 10000; //sets lowest index to 10000 so that any index under should theoretically be lower

    for(int i = 0; i < sizeOfGA; i++) { //iterates through the array
        if(gradeArray[i] <= lowestNum) { //if gradeArray at index i is less than or equal to lowestNum
            lowestNum = gradeArray[i]; //set lowestNum to gradeArray at index i
            lowestIndex = i;//set highestIndex to i;
        }
    }

    cout << "The lowest grade is: " << lowestNum << " which is at index " << lowestIndex << endl;


    delete [] gradeArray; //deletes gradeArray since it is not being used anymore 

}