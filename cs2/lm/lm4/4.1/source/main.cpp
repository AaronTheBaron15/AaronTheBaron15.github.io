//main.cpp
//CS172-1 CS2
//Aaron Borjas
//3/2/19
//this implements the rectangle class and creates an array of 10 rectangles, comparing them in different ways after creating the array
#include "../headers/rectangle.h"
#include <cstdlib>
#include <ctime>
using namespace std;

const int arrayLength = 10;

//printAllAreas is a function that prints the areas of all the rectangles in an array
//inputs - an array of rectangles that has a length of arrayLength. The rectangles must have values assigned to them
//outputs - prints out the area of every single rectangle in the rectangle array
void printAllAreas(Rectangle array[]) {
    for(int i = 1; i <= arrayLength; i++) { //iterates through the array
        //prints the area of a rectangle and says how the area as found
        cout << "Area of rectangle " << i << " is: " << array[i-1].getBase() << " * " << array[i-1].getHeight() << " = " << array[i-1].getArea() << endl;
    }
}

//getLongRect, finds the longest rectangle(s) of a rectangle array
//inputs - an array of rectangles that has a length of arrayLength. The rectangles must have values assigned to them.
//outputs - prints the rectangles with the largest lengths. This means that if there is a tie, the tied rectangles print
void getLongRect(Rectangle array[]) {
    int longestArr[arrayLength]; //array to hold the information of the heighest rectangles
    int longestLong = 0; //placeholder for longest length of rectangle. none of the rectangles can have a length of 0 so this is a "safe" number

    //cout << "HEY!" << endl;
    //finds length value of length in the list of rectangles
    for(int  i = 0; i < arrayLength; i++) {//itereates through the array
        if(array[i].getBase() > array[longestLong].getBase()) { //if the length of the current rectangle is greater than the length of the current longest rectangle
            longestLong = i; //set longestLong to the new index of the tallest rectangle
        }
    }
    //cout << "longest length is: " << array[longestLong].getBase() << endl;
    
    //finds lengths that equal the longest length (if there are other ones) and prints all of the rectangles that have the same length as longestLong
    for(int i = 0; i < arrayLength; i++) { //iterates through the array
        if(array[i].getBase() == array[longestLong].getBase()) { //if the length of the current rectangle is equal to the length of the longest rectangle
            longestArr[i] = i; //the index of the rectangle with the same length as the tallest length is set to longestArr[i]
        }
        else if(array[i].getBase() != array[longestLong].getBase()) { //otherwise if the length is not tied
            longestArr[i] = 0; //set longestArr at index i to 0
        }

        //prints the rectangle(s) with the longest length(s) (ties included)
        if(longestArr[i] != 0) { //if the longestArr at index i is not equal to 0
            array[longestArr[i]].print(); //prints the rectangles that have a length equal to the longest length (ties)
        }
    }
}

//getTallRect, finds the tallest rectangle(s) of a rectangle array
//inputs - an array of rectangles that has a length of arrayLength. The rectangles must have values assigned to them.
//outputs - prints the rectangles with the largest heights. This means that if there is a tie, the tied rectangles print
void getTallRect(Rectangle array[]) {
    int longestArr[arrayLength]; //array to hold the information of the heighest rectangles
    int tallestTall = 0; //placeholder for longest height of rectangle. none of the rectangles can have a height of 0 so this is a "safe" number

    //cout << "HEY!" << endl;
    //finds heighest value of height in the list of rectangles
    for(int  i = 0; i < arrayLength; i++) {//itereates through the array
        if(array[i].getHeight() > array[tallestTall].getHeight()) { //if the height of the current rectangle is greater than the height of the current tallest rectangle
            tallestTall = i; //set tallestTall to the new index of the tallest rectangle
        }
    }
    
    //finds heights that equal the longest height (if there are other ones) and prints all of the rectangles that have the same height as tallestTall
    for(int i = 0; i < arrayLength; i++) { //iterates through the array
        if(array[i].getHeight() == array[tallestTall].getHeight()) { //if the height of the current rectangle is equal to the height of the heighest rectangle
            longestArr[i] = i; //the index of the rectangle with the same height as the tallest height is set to longestArr[i]
        }
        else if(array[i].getHeight() != array[tallestTall].getHeight()) { //otherwise if the height is not tied
            longestArr[i] = 0; //set longestArr at index i to 0
        }

        //prints the rectangle(s) with the heighest height(s) (ties included)
        if(longestArr[i] != 0) { //if the longestArr at index i is not equal to 0
            array[longestArr[i]].print(); //prints the rectangles that have a height equal to the heighest height (ties)
        }
    }
}

//getBigArea, finds the rectangle(s) of a rectangle array with the largest area(s) 
//inputs - an array of rectangles that has a length of arrayLength. The rectangles must have values assigned to them.
//outputs - prints the rectangles with the largest areas. This means that if there is a tie, the tied rectangles print
void getBigArea(Rectangle array[]) {
    int longestAreas[arrayLength]; //array to hold index information of the rectangles with the largest areas
    int largestArea = 0; //the index of the rectangle with the largest area
    for(int i = 0; i < arrayLength; i++) { //iterate through the rectangle array
        if(array[i].getArea() > array[largestArea].getArea()) { //if the current rectangle has an area larger than the current largest area
            largestArea = i; //set the largest area index to the current index
        }
    }

    for(int i = 0; i < arrayLength; i++) { //iterate through the rectangle array
        if(array[i].getArea() == array[largestArea].getArea()) { //if the current rectangle has an area equal to the largest area
            longestAreas[i] = i; //makes the value of longestAreas at index i is equal to i
        }
        else if(array[i].getArea() != array[largestArea].getArea()) { //if the current rectangle has an area not equal to the largest area
            longestAreas[i] = 0; //set the value of longestAreas at index i to 0
        }

        if(longestAreas[i] != 0) { //if the current index of longestAreas is not equal to zero
            array[longestAreas[i]].print(); //print the rectangle
        }
    }
}


int main() {
    srand(time(NULL));

    Rectangle rectangleArray[arrayLength]; //creates an array that is made up of arrayLength number of rectangles

    for(int i = 0; i < arrayLength; i++) { //iterates through the array
        rectangleArray[i].setHeight((rand()%15)+1); //sets the height of the ith rectangle to a random number from 1 to 15
        rectangleArray[i].setBase((rand()%15)+1); //sets the base length of the ith rectangle to a random number from 1 to 15

        rectangleArray[i].print(); //prints the ith rectangle
    }
    cout << endl; //new line

    printAllAreas(rectangleArray); //prints the areas of all the rectangles

    cout << endl; //new line

    cout << "Longest rectangle(s): " << endl; //says whats printing
    getLongRect(rectangleArray); //prints the longest rectangle(s)

    cout << endl; //new line

    cout << "Tallest rectangle(s): " << endl; //says whats printing
    getTallRect(rectangleArray); //prints the tallest rectangle(s)

    cout << "Rectangle(s) with the largest area(s): " << endl; //says whats printing
    getBigArea(rectangleArray); //prints the rectangle(s) with the largest area(s)
}