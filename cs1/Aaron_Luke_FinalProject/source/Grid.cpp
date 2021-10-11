#include "grid.h"
#include "location.h"
#include "ship.h"
#include <iostream>

using namespace std;

Grid::Grid() {
    Location grid[GRID_SIZE][GRID_SIZE];
}

//adds a ship to the grid
//Adds a ship object called ship to the grid by changing the shipPresent status of each desired location to true
//Inputs: Ship object called ship
//outputs: N/A (changes if a ship is present at certain locations on the grid though)
void Grid::addShip(Ship& ship) {
    int row = ship.getRow(); 
    int col = ship.getCol();
    if(ship.getDirection() == VERTICAL) { //if the direction of the ship is vertical (goes down a column)
        //start begins at row (predetermined) and goes until (row + length of ship) while incrementing by one
        for(int start = row; start < row + ship.getLength(); start++) { 
            setShip(start, col, true); //sets the shipPresent status to true at row start and column col
        }
    }
    else { //if the direction is horizontal (goes across a row)
        //start begins at col (predetermined) and goes until (col + length of ship) while incrementing by one
        for(int start = col; start < col + ship.getLength(); start++) {
            setShip(row, start, true); //sets the shipPresentstatus to true at row row and column start 
        }
    }
}

//checks if a location at grid[row][col] is in the bounds of the 2d array
//inputs - int row and int col, which are both positive and ranging from 0 to GRID_SIZE
//outputs - true or false if the value at grid[row][col] is in bounds of the 2d array
bool Grid::inBounds(int row, int col) {
    //returns true if row is greater than or equal to 0 and less than numRows() and if col is greater than or equal to 0 and less than numCols() 
    return (row >= 0) && (row < numRows()) && (col >= 0) && (col < numCols());
}

//Checks if a ship can be placed in the desired path, using the length, row, column, and direction of the ship to figure this out
//inputs - a Ship object called ship with a length less than GRID_SIZE and greater than 0
//outputs - returns true if a ship can be placed at a spot
bool Grid::checkIfShip(Ship ship) {
    int row = ship.getRow();
    int col = ship.getCol();
    if(ship.getDirection() == VERTICAL) { //if the direction of the ship is vertical (goes down a column)
        //start begins at row (predetermined) and goes until (row + length of ship) while incrementing by one
        for(int start = row; start < row + ship.getLength(); start++) { 
            if(!inBounds(start, col) || hasShip(start, col)) { //if the location is not in bounds or has a shissp
                return false;
            }
        }
    }
    else { //if the direction is horizontal (goes across a row)
        //start begins at col (predetermined) and goes until (col + length of ship) while incrementing by one
        for(int start = col; start < col + ship.getLength(); start++) {
            if(!inBounds(row, start) || hasShip(start, col)) { //if the location is not in bounds or has a ship
                return false; //return false
            }
        }
    }
    return true;
}

//marks a hit with an "X" on the grid
//inputs - int row and int col, which are both positive integers from 0 to GRID_SIZE
//outputs - none, but prints an "X" on the grid at the specified spot
void Grid::markHit(int row, int col) {
    grid[row][col].markHit(); //marks the location as hit
    setStatus(row, col, 1); //changes the status of the location to HIT
}

//marks a miss with an "O" on the grid
//inputs - int row and int col, which are both positive integers from 0 to GRID_SIZE
//outputs - none, but prints an "O" on the grid at the specified spot
void Grid::markMiss(int row, int col) {
    grid[row][col].markMiss(); //marks the location as a miss
    setStatus(row, col, 2); //changes the status of the location to MISSED
    //cout << "status of grid[" << row << "][" << col << "] is " << grid[row][col].getStatus() << endl;
}

//changes the status of the location at grid[row][col] to hit or missed
//inputs - row and col, which are both positive integers from 0 to GRID_SIZE, and int status, which should be either 0, 1, or 2
//outputs - nothing, but changes the status of the location at grid[row][col]
void Grid::setStatus(int row, int col, int status) {
    grid[row][col].setStatus(status); //sets the status to status at grid[row][col]
}

//gets the status (if a ship is present) at grid[row][col]
//inputs - row and col, which are both positive integers from 0 to GRID_SIZE
//outputs - gets the status of the location at grid[row][col]
int Grid::getStatus(int row, int col) {
    return grid[row][col].getStatus();//gets the status at grid[row][col]
}

//true or false depending on if the location at grid[row][col] was already guessed
//inputs - row and col, which are both positive integers from 0 to GRID_SIZE
//outputs- true or false depending on if grid[row][col] was already guessed
bool Grid::alreadyGuessed(int row, int col) {
    return !grid[row][col].isUnguessed(); //true if grid[row][col] is not unguessed
}

//changes the shipPresent status of the location at grid[row][col] to true or false depending on what shipPresent is
//inputs - row and col, which are both positive integers from 0 to GRID_SIZE, and a boolean value called shipPresent, which signifies what the status will change to
//outputs - nothing, but changes the status at grid[row][col]
void Grid::setShip(int row, int col, bool shipPresent) {
    grid[row][col].setShip(shipPresent); //sets shipPresent to true at grid[row][col]
}

//prints if there is a ship at grid[col][row]
//inputs - row and col, which are both positive integers from 0 to GRID_SIZE
//outputs - true or false depending on if there is a ship at grid [row][col]
bool Grid::hasShip(int row, int col) {
    return grid[row][col].hasShip(); //returns if there is a ship at grid[row][col]
}

//returns the number of rows in the grid
//inputs - none
//outputs - returns the number of rows of the grid
int Grid::numRows() {
    return GRID_SIZE;
}

//returns the number of columns in the grid
//inputs - none
//outputs - returns the number of columns in the grid
int Grid::numCols() {
    return GRID_SIZE;
}

//prints the hits (X) and misses (O) (what the opponent would see) of a board
//no inputs
//prints out something like this:
//
//   1 2 3 4 5 6 7 8 9 10
// A - - - - - - - - - -
// B - - - - - - - - - -
// C - - - O - - - - - -
// D - O - - - - - - - -
// E - X - - - - - - - -
// F - X - - - - - - - -
// G - X - - - - - - - -
// H - O - - - - - - - -
// I - - - - - - - - - -
// J - - - - - - - - - -
void Grid::printStatus() { 
    cout << HEADER_COLS << endl; 
        for(int row = 0; row < GRID_SIZE; row++)
        {
            cout << HEADER_ROWS.at(row) << " ";

            for(int col = 0; col < GRID_SIZE; col++) {
                if(getStatus(row,col) == 2) { //if status of location at grid[row][col] is missed
                    cout << STATUS_STRING[2] << " ";
                }
                else if(getStatus(row,col) == 1) { //if status of location at grid[row][col] is hit
                    cout << STATUS_STRING[1] << " ";
                }
                else { //if status of location at grid[row][col] is unguessed or blank
                    cout << STATUS_STRING[0] << " "; 
                }
            }
            cout << endl;
        }
}

//print the ships on a grid. - are where there are no ships, and X's are ships
//no inputs
//looks something like this:
//
//   1 2 3 4 5 6 7 8 9 10
// A - - - - - - - - - -
// B - X - - - - - - - -
// C - X - - - - - - - -
// D - - - - - - - - - -
// E X X X - - - - - - -
// F - - - - - - - - - -
// G - - - - - - - - - -
// H - - - X X X X - X -
// I - - - - - - - - X -
// J - - - - - - - - X -
void Grid::printShips() {
    cout << HEADER_COLS << endl;
        for(int row = 0; row < GRID_SIZE; row++)
        {
            cout << HEADER_ROWS.at(row) << " ";

            for(int col = 0; col < GRID_SIZE; col++)
            {
                if(hasShip(row, col))
                {
                    cout << "X ";
                }
                else
                {
                    cout << "- ";
                }
            }
            cout << endl;
        }
}



