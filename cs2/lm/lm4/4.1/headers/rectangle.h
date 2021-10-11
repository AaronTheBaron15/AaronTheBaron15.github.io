//rectangle.h
//CS172-1 CS2
//Aaron Borjas
//3/2/19
//This is the header file for the rectangle class, defining all the functions relating to a rectangle object
#include <iostream>
using namespace std;

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
    private:
        int base; //the base length of a rectangle, should be a positive integer greater than 0
        int height;//the height length of a rectangle, should be a positive integer greater than 0
    public: 
        //empty constructor for rectangle, does not initialize anything
        Rectangle();

        //class constructor for rectangle
        //sets the values of base and heigh based on values passed into the constructor
        Rectangle(int myBase, int myHeight);

        //getArea is a function that gets the area of a rectangle that has defined base and height
        //no inputs - takes the base and height that are already defined for the rectangle
        //ouputs - returns the area of the rectangle;
        int getArea();

        //getPerimeter is a function that gets the perimeter of a rectangle that has a defined base and height
        //no inputs 
        //outputs - returns the perimeter of the rectangle as an integer
        int getPerimeter();

        //getHeight is a function that gets the height of the rectangle
        //no inputs
        //outputs - returns the height of the rectangle
        int getHeight();

        //getBase is a function that gets the base length of the rectangle
        //no inputs
        //outputs - returns the base length of the rectangle as an integer
        int getBase();

        //setHeight is a function that sets the height of the rectangle
        //inputs - expects a positive integer as an input. this should represent the desired height of the rectangle
        //no outputs
        void setHeight(int newHeight);

        //setBase is a function that sets the base of the rectangle
        //inputs - expects a positive integer as an input. this should represent the desired base of the rectangle
        //no outputs
        void setBase(int newBase);

        //print is a function that prints all the information about the rectangle, eg base, height, perimeter, and area, along with the rectangle itself
        //no inputs
        //prints the information about the rectangle, and the rectangle to the screen
        void print();

};

#endif