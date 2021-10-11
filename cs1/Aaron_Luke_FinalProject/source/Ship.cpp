#include "ship.h"
using namespace std;


//constructor for ship class
//sets the default length to shipLength
//inputs - shipLength, which is a postive int and either 2, 3, 3, 4, or 5
//outputs - creates a new ship object
Ship::Ship(int shipLength) {
    length = shipLength; //sets length to shipLength
}

Ship::Ship(){
    
}

//method to check if a location for ship is set or not
//inputs - none
//outputs true or false based on the row and column values
bool Ship::isLocationSet() {
    if((row != UNSET) && (col != UNSET)) { //if row and col are not equal to -1 (UNSET)
        return true; //return true
    }
    return false; //return false
}

//method to check if a ship's direction is set or not
//inputs - none
//outputs true or false depending on what the variable direction equals for a ship object
bool Ship::isDirectionSet() {
    if(direction != UNSET) { //if direction is not UNSET (-1)
        return true; //returns true
    }
    return false; //returns false
} 

//method to set the leftmost (horizontal) or topmost (vertical) row and column for the ship
//inputs - newRow and newCol, which is a row and column that are positive integers between 0 and GRID_SIZE
//outputs - changes the values of row and col for the top or leftmost positions of the ship
void Ship::setLocation(int newRow, int newCol) {
    row = newRow; //row is equal to newRow
    col = newCol;//col is equal to newCol)
}

//method to set the direction of the ship to horizontal or vertical
//inputs - newDirection, which a positive integer that is either 0 or 1, 0 representing HORIZONTAL and 1 representing VERTICAL
//outputs - changes direction to newDirection
void Ship::setDirection(int newDirection) {
    direction = newDirection; //direction is equal to newDirection
}

//method that gets the row of the top or leftmost value of the ship
//no inputs
//returns row of the top or leftmost row of the ship
int Ship::getRow() {
    return row; //return the value of row
}

//method that gets the column of the top or leftmost value of the ship
//no inputs
//returns the top or leftmost column of the ship
int Ship::getCol() {
    return col; //return the value of col
}

//method that gets the length of a ship
//inputs - none
//outputs - returns the length of a ship
int Ship::getLength() {
    return length; //return the value of length
}

//method that gets the direction of a ship as an integer
//inputs - none
//outputs - returns the integer value of direction of a ship
int Ship::getDirection() {
    return direction; //return the value of direction
}

//gets the direction of the ship and changes it to a string
//inputs - none
//outputs - the direction of the ship as a string
string Ship::directionToString() {
    if(direction == HORIZONTAL) {
        return "HORIZONTAL";
    }
    else if(direction == VERTICAL) {
        return "VERTICAL";
    }
    else {
        return "UNSET DIRECTION";
    }
}


