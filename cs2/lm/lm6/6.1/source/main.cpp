//main.cpp
//CS172-1, CS2
//Aaron Borjas
//3/25/19
//This program is messing around with pointers and many of the different things that can be done with them

#include <iostream>
using namespace std;

const int arrLength = 10;

//function recursiveSwitch, which reverses an integer array using pointers
//inputs - two integer pointers, one for the starting memory location of the array and one for the ending memory location of the array
//outputs - no returns, but changes the values of teh array
void recursiveSwitch(int* start, int* end) {
    if(start+1 == end) { //base case, if start+1 is equal to the end of the array
        int* holder = start; //placeholder for the "start" value
        *start = *end;//the start value changes to the end value
        *end = *holder; //the end value changes to the value of the holder, which is the original value of start
    }
    else if(start < end) { //otherwise if start is less than end
        int* holder = start; //placeholder for the "start" value
        *start = *end;//the start value changes to the end value
        *end = *holder; //the end value changes to the value of the holder, which is the original value of start
        recursiveSwitch(start+1, end-1); //call recursive switch on start+1 and end-1
    }
}

int main() {
    int num = 17;//create an integer and set it to 17
    int* numptr = &num; //makes a integer pointer called numptr that initializes to be the address of num

    //======= Changing initial num and dereference pointer with dereference operator=======
    cout << "num is " << num << endl; //prints what num is
    cout << "dereference of numptr is " << *numptr << endl; //prints the dereference of numptr (which is just num)

    cout << "Changing num with dereference operator..." << endl;
    (*numptr)+=10; //adding 10 to the dereference of numptr (adding 10 to num)

    cout << "num is " << num << endl; //prints what num is
    cout << "dereference of numptr is " << *numptr << endl;//prints the dereference of numptr (which is just num)

    cout << endl;

    //======= manipulating arrays with pointers =======

    int arr[arrLength];//creates array with length off arrLength
    //fills array
    for(int i = 0; i < arrLength; i++) { //iterates through the array
        arr[i] = i+1; //sets array at index i to i+1
        cout << arr[i] << " "; //prints array at index i
    }

    int* arrPoint = arr; //create a integer pointer which points to the arr, which itself is a pointer that points to the first element inside arr
    cout << endl;

    while(arrPoint != &arr[arrLength]) {//iterates through the array 
        (*arrPoint)*=10; //sets the value (not the memory space) that arrPoint points to equal to 10 times the current value
        cout << *arrPoint << " "; //prints array at index 
        arrPoint++; //increments arrPoint (goes to next element in the array)
    }
    cout << endl << endl; //two new lines

    //======= creating arrays next to each other =======
    int n1Arr[arrLength]; //creates an array of integers

    int n2Arr[arrLength]; //creates another array of integers
    
    //sets values to the arrays
    for(int i = 0; i < arrLength; i++) { //iterates through the first array
        n1Arr[i] = i+1; //sets array at index i to i+1
    }
    for(int i = 0; i < arrLength; i++) { //iterates through the first array
        n2Arr[i] = i+1; //sets array at index i to i+1
    }

    int* pointArr1 = n1Arr; //creates a pointer for the first array
    int* pointArr2 = n2Arr; //creates a pointer for the second array

    //this section of code was originally implemented further below by Scott
    //I tried his approach, and the indicies where the elements overlapped were the same
    cout << "Start of first pointer array   " << int64_t(&pointArr1[0]) << endl; //Start by figuring out which one is 'higher' in memory

    cout << "End   of first pointer array   " << int64_t(&pointArr1[arrLength-1]) << endl; //prints the ending memory space of the first array

    cout << "Start of second pointer array " << int64_t(&pointArr2[0]) << endl;// prints the memory space of the first element of the second array

    cout << "End   of second pointer array " << int64_t(&pointArr2[arrLength-1]) << endl;//prints the ending memory space of the second array

    cout << "     pointArr2[10] " << int64_t(&pointArr2[10]) << endl; //intArr comes 'after' floatArr, so positive floatArr index will bleed into intArr
    
    cout << "     pointArr2[11] " << int64_t(&pointArr2[11]) << endl;//guessing

    cout << "     pointArr2[12] " << int64_t(&pointArr2[12]) << endl; //This is equal to intArr[0]!

    cout << "     pointArr2[13] " << int64_t(&pointArr2[13]) << endl; //guessing

    cout << "     pointArr2[14] " << int64_t(&pointArr2[14]) << endl << endl;//guessing

    int* repointArr2 = &pointArr2[12]; //creates an integer pointer which points to the first element in the first array, but using the second array (since the second array comes "before" the first in memory)

    cout << "First arr: "; //says what will be printing next
    for(int i = 0; i < arrLength; i++) {//iterates through the first array
        cout << *pointArr1 << " "; //prints the value inside the memory location of pointArr1
        pointArr1++; //increments pointArr1
    }
    cout << endl << "Second arr: "; //makes a new line and says what is printing next

    for(int i = 0; i < arrLength; i++) {//iterates through the second array
        cout << *repointArr2 << " "; //prints the value inside the memory location of repointArr2
        repointArr2++;//increments repointArr2
    }
    cout << endl << endl; //makes a new line
    
    //======= checking stuff with the previous arrays =======

    //prints the last address in the array
    cout << "The address of the last index of pointArr1 is: " << int64_t(&pointArr1[9]) << endl;
    //prints the address of the first array at an index greater than the amount of indicies in the array
    cout << "The address of pointArr1[11] (the index is greater than expected): " << int64_t(&pointArr1[11]) << endl; 

    //prints the first address of the second array
    cout << "The address of pointArr2[0]: " << int64_t(&pointArr2[0]) << endl;
    //prints the address of the second array at an index less than what the first index is
    cout << "The address of pointArr2[-2] (the index is less than expected): " << int64_t(&pointArr2[-2]) << endl;

    //======= creating float array and int arrays next to each other =======
    cout << "====================\nFloat and Int Arrays\n====================\n" << endl;

    int intArr[arrLength]; //creates an integer array

    float floatArr[arrLength]; //creates a floating point array
    
    //sets values to the arrays
    for(int i = 0; i < arrLength; i++) { //iterates through the integer array
        intArr[i] = i+1; //sets array at index i to i+1
    }
    for(int i = 0; i < arrLength; i++) { //iterates through the floating point array
        float floatI = i+0.5; //creates a new floating point number that is equal to i+0.5
        floatArr[i] = floatI; //sets array at index i to i+1
    }

    int* pointIntArr = intArr; //creates a pointer for the first array
    float* pointFloatArr = floatArr; //creates a pointer for the second array

    // cout << "pointIntArr[9] is: " << int64_t(&pointIntArr[9]) << endl; //prints the memory space of the last index of the first array
    // cout << "pointFloatArr is: " << int64_t(pointFloatArr) << endl; //prints the memory space of the first index of the second array
    // //prints the difference between the end of the first array and the start of the second array
    // cout << "The difference between the two is " << int64_t(pointFloatArr) - int64_t(&pointIntArr[9]) << " bytes (4 bytes is the size of an integer)" << endl << endl;

    // //moves the initial memory space of the first array "down" by the (distance between the end of the first array 
    // //and the start of the second) minus four (because for me this number is negative, and I want the first array before the second), 
    // //then divided by negative four since there are 4 bytes per integer, and I want a positive number
    // (pointIntArr) -= ((int64_t(pointFloatArr) - int64_t(&pointIntArr[9]))-4)/(-4);
    // //(pointArr1)-=22; <---- this is the same as the above for me

    // cout << "pointIntArr[9] is: " << int64_t(&pointIntArr[9]) << endl; //prints the memory space of the last index of the first array
    // cout << "pointFloatArr is: " << int64_t(pointFloatArr) << endl; //prints the memory space of the first index of the second array
    // //prints the difference between the end of the first array and the start of the second array
    // cout << "The difference between the two is " << int64_t(pointFloatArr) - int64_t(&pointIntArr[9]) << " bytes (4 bytes is the size of an integer)" << endl << endl;

    //Scott Edit
    cout << "Start of intArr   " << int64_t(&intArr[0]) << endl; //Start by figuring out which one is 'higher' in memory
    cout << "End   of intArr   " << int64_t(&intArr[arrLength-1]) << endl;
    cout << "Start of floatArr " << int64_t(&floatArr[0]) << endl;
    cout << "End   of floatArr " << int64_t(&floatArr[arrLength-1]) << endl;
    cout << "     floatArr[10] " << int64_t(&floatArr[10]) << endl; //intArr comes 'after' floatArr, so positive floatArr index will bleed into intArr
    cout << "     floatArr[11] " << int64_t(&floatArr[11]) << endl;//guessing
    cout << "     floatArr[12] " << int64_t(&floatArr[12]) << endl; //This is equal to intArr[0]!
    cout << "     floatArr[13] " << int64_t(&floatArr[13]) << endl; //guessing
    cout << "     floatArr[14] " << int64_t(&floatArr[14]) << endl;//guessing

    float* falseIntArr = &floatArr[12]; //Experimentally found from above

    for(int i = 0; i < arrLength; i++){//iterates through the arrays
        cout << "intArr[" << i << "] as an int: " << intArr[i] << " as a float: " << falseIntArr[i] << endl; //prints the value of intArr at index i as an int and a float
    }

    int* falseFloatArray = &intArr[0]; //creates a integer pointer which points to the first index of the integer array

    //End Scott Edit
    for(int i = 0; i < arrLength; i++) { //iterates through the arrays
        cout << "floatArr[" << i << "] as a float: " << floatArr[i] << " as a int: " << falseFloatArray[i] << endl; //prints the value of floatArr at index as a float and an int
    }

    //==============================
    //recursive switch with pointers
    //==============================
    cout << endl << "============================\nRecrusive switch with pointers\n=============================" << endl << endl;

    int myArr[arrLength] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //makes an array with length of arrLength, prefilled with numbers from 1 through 10

    //prints the array
    for(int i = 0; i < arrLength; i++) { //iterates through the array
        cout << myArr[i] << " "; //prints the values of the array at index i
    }
    cout << endl;

    int* start = &myArr[0]; //creates an integer pointer which points to the memory location of the first index of myArr
    int* end = &myArr[arrLength-1]; //creates an integer pointer which points to the memory location of the last index of myArr

    cout << "start: " << *start << "    end: " << *end << endl; //prints the value inside the memory location of start and end
    recursiveSwitch(start, end); //recursively flips the array using the pointers start and end
    cout << "start: " << *start << "    end: " << *end << endl; //prints the value inside the memory location of start and end

    //prints the array
    for(int i = 0; i < arrLength; i++) { //iterates through the array
        cout << myArr[i] << " "; //prints myArr at index i
    }
    cout << endl; //new line
    
}