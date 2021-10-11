//main.cpp
//CS172-1 CS2
//Aaron Borjas
//4/7/19
//uses types to create generic functions and classes, shows how those generic functions and classes can be used

#include <iostream>
using namespace std;
const int arrLength = 10;
const int arrLength2 = 4;

//this cup class references the billboard class from the folder for lm 7.2 in classdata
template <typename Type>
class Cup{
    private:
        int numItems; //number of items in the cup
        Type contents[arrLength2]; //creates a generic variable to hold content of type Type
    public:
        //Empty constructor
        //does not do anything to modify the member variables
        Cup() {
            numItems = 0;
        }
        
        //constructor for the cup class
        //takes in stuff of type Type (which is the general type of the class)
        //sets content at index 0 to stuff
        Cup(Type stuff) {
            contents[0] = stuff; //sets content at index 0 to stuff
            numItems = 1;
        }

        //addContent adds a generic item to the contents of the cup
        //takes in a generic item which has the same type as the instance of the cup
        //adds the item to the contents of the cup
        void addContent(Type item) {
            contents[numItems] = item; //sets contents at numItems to item
            numItems++; //increments numItems
        }

        //removeContent removes one of the generic contents of the cup
        //no inputs
        //removes an item from the contents of the cup by pretending it does not exist
        void removeContent() {
            numItems--; //decrements numItems
        }


        void print() {
            cout << "The cup contains: " << endl;
            for(int i = 0; i < arrLength2; i++) {
                cout << contents[i] << endl;
            }
            cout << endl;
        }
};

//THIS IS IMPLEMENTED FROM LM5.1
//binarySearch, which searches a sorted array of integers for a specific number and returns the index of the number. if the number does not exist, returns the negative index of where it should be
//inputs - an integer array, whose length is determinded by a start point and end point (indeces), and an integer desiredNum that is the number being searched for in the array
//outputs - returns the index of the desired number, but if the number is not in the array, prints where it would go
template <typename Type>
int binarySearch(Type arr[], int start, int end, Type desiredNum) {
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

//THIS IS IMPLEMENTED FROM LM5.1
//insertElement, which is a function that inserts a given number into a certain position of an array with a predetermined length
//inputs - three integers, pos is the index of where the value is to be placed (positive), value is the value to put into the array, and length is the length of the array. The last input is an array of integers called arr
//outputs - changes the values of the array and inserts the chosen value into the chosen position
template <typename Type>
void insertElement(int pos, Type value, Type arr[], int length) {
    for(int i = length-1; i > pos; i--) { //iterates through the array
        arr[i] = arr[i-1]; //sets the value of the array at index i to the value of the array at index i-1
        //cout << "arr[" << i << "] is: " << arr[i] << endl;
    }
    arr[pos] = value; //sets the value of array at index pos to value
}

//sortArray is a function that sorts an array using a binary search to figure out where each number goes
//inputs - an array of integers that is UNSORTED!!!! and length of the array that is a positive integer
//outputs - sorts the array of integers
template <typename Type>
void sortArr(Type* arr, int length) {
    // float sortedArr[length] = { 0 }; //creates a sorted array of length arrayLength, which is filled with zeros
    Type * sortedArr = new Type[length];
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

int main() {
    //==========================================================
    //TESTING TEMPLATE VERSION OF BINARY SORT WITH INTEGER ARRAY
    //==========================================================

    int intArr[arrLength] = { 10, 15, 1, 200, 321, 50, 79, 36, 99, 1000 }; //creating an integer array of length arrLength, with pre assigned values

    cout << "intArr before sorting..." << endl;
    for(int i = 0; i < arrLength; i++) { //iterating through the array
        cout << intArr[i] << " "; //prints the value of intArr at index i
    }
    cout << endl << endl;

    sortArr(intArr, arrLength); //sorts the integer array that has a length of arrLength

    cout << "intArr after sorting..." << endl;
    for(int i = 0; i < arrLength; i++) { //iterating through the array
        cout << intArr[i] << " "; //prints the value of intArr at index
    }
    cout << endl << endl;

    //=================================================================
    //TESTING TEMPLATE VERSION OF BINARY SORT WITH FLOATING POINT ARRAY
    //=================================================================

    float floatArr[arrLength] = { 10.15, 15.74, 1.33333, 200.01, 321.123, 50.05, 79.95, 36.63, 99.99, 1000.0001 }; //creating an integer array of length arrLength, with pre assigned values

    cout << "floatArr before sorting..." << endl;
    for(int i = 0; i < arrLength; i++) { //iterating through the array
        cout << floatArr[i] << " "; //prints the value of intArr at index i
    }
    cout << endl << endl;

    sortArr(floatArr, arrLength); //sorts the integer array that has a length of arrLength

    cout << "floatArr after sorting..." << endl;
    for(int i = 0; i < arrLength; i++) { //iterating through the array
        cout << floatArr[i] << " "; //prints the value of intArr at index
    }
    cout << endl << endl;

    //=================================================================
    //TESTING TEMPLATE VERSION OF BINARY SORT WITH STRING ARRAY
    //=================================================================

    string myString[] = {"hello there", "aaron", "scott"}; //creating an integer array of length arrLength, with pre assigned values
    //string* stringPoint = &myString;

    cout << "myString before sorting..." << endl;
    for(int i = 0; i < 3; i++) { //iterating through the array
        cout << myString[i] << " "; //prints the value of intArr at index i
    }
    cout << endl << endl;

    sortArr(myString, 3); //sorts the integer array that has a length of arrLength

    cout << "myString after sorting..." << endl;
    for(int i = 0; i < 3; i++) { //iterating through the array
        cout << myString[i] << " "; //prints the value of intArr at index
    }
    cout << endl << endl;


    Cup<int> cuppaInts(1); //creates a new cup that starts with a 1
    cuppaInts.print(); //prints the cup of ints

    cuppaInts.addContent(15);//adds some contents to the cup
    cuppaInts.addContent(277); //adds some contents to the cup
    cuppaInts.addContent(188);//adds some contents to the cup
    cuppaInts.print(); //prints the cup of ints
    
    cuppaInts.removeContent(); //removes an item from the contents
    cuppaInts.addContent(27); //"replaces" the item that was removed
    cuppaInts.print(); //prints the cup of ints

    cout << "WITH A STRING!!!!" << endl << endl;

    Cup<string> cupString("oh"); //creates a new cup that starts with a 1
    cupString.print(); //prints the cup of ints

    cupString.addContent("HellO");//adds some contents to the cup
    cupString.addContent("THERE"); //adds some contents to the cup
    cupString.addContent(":)");//adds some contents to the cup
    cupString.print(); //prints the cup of ints
    
    cupString.removeContent(); //removes an item from the contents
    cupString.addContent(":("); //"replaces" the item that was removed
    cupString.print(); //prints the cup of ints
    

}