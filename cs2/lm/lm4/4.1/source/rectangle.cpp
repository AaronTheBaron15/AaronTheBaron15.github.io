//rectangle.cpp
//CS172-1 CS2
//Aaron Borjas
//3/2/19
//This is the cpp file for the rectangle class, creating the actual code for the rectangle functions and constructors
#include "../headers/rectangle.h"
using namespace std;

Rectangle::Rectangle() {
    cout << "I'm a new rectangle!" << endl;
}

Rectangle::Rectangle(int myBase, int myHeight) {
    base = myBase;
    height = myHeight;
}

int Rectangle::getArea() {
    return base*height;
}

int Rectangle::getPerimeter() {
    return (2*(base))+(2*(height));
}

int Rectangle::getHeight() {
    return height;
}

int Rectangle::getBase() {
    return base;
}

void Rectangle::setHeight(int newHeight) {
    height = newHeight;
}

void Rectangle::setBase(int newBase) {
    base = newBase;
}

void Rectangle::print() {
    //prints the information about the rectangle
    // cout << "The height of the rectangle is: " << height << endl;
    // cout << "The base of the rectangle is: " << base << endl;
    // cout << "The area of the rectangle is: " << height*base << endl;
    // cout << "The perimeter of the rectangle is: " << (2*base)+(2*height) << endl;

    //prints the rectangle
    for(int i = 0; i < height; i++) { //iterates through the height of the rectangle (the "rows")
        for(int j = 0; j < base; j++) { //iterates through the base of the rectangle (the "columns")
            if(i == 0 || i == height-1) { //if i is zero or the final possible value of i (the value of height-1)
                cout << "* "; //prints an asterisk with a space after it
            }
            else if(j == 0 || j == base-1) { //otherwise if j is zero or the final possible value of j (the value of base-1)
                cout << "* "; //prints an asterisk with a space after it
            }
            else { //otherwise if the value of j or i are not on the edge of the rectangle
                cout << "  "; //prints two spaces
            }
        }
        
        cout << endl; //makes a new line
    }
}