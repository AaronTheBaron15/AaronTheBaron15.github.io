#ifndef GRID_h
#define GRID_h

#include "location.h"
#include "ship.h"
#include <string>
using namespace std;

const int GRID_SIZE = 10;
const string HEADER_COLS = "  1 2 3 4 5 6 7 8 9 10"; //headers for the columns
const string HEADER_ROWS = "ABCDEFGHIJ"; //headers for the rows
const string STATUS_STRING[3] = {"-", "X", "O"}; //string for the status, - being unguessed, O being missed, and X being hit

class Grid{
    private:
        const int UNSET = -1; //if something is not set, it is equal to -1 (eg if direction is not set off the bat, this would be: direction = UNSET)
        const int HORIZONTAL = 0; //horizontal is equal to 0
        const int VERTICAL = 1; //vertical is equal to 1
        Location grid[GRID_SIZE][GRID_SIZE]; //new grid of locations that has GRID_SIZE rows and GRID_SIZE elements in each row

    public: 
        //constructor for grid
        //makes a grid that is GRID_SIZE by GRID_SIZE
        //no inputs
        //no outputs
        Grid();
        
        //adds locations to all values on the grid
        //loops through the whole grid and adds a new location to each spot on the grid
        //Inputs: None
        //Outputs: none (updates the grid to be made up of locations though)
        void initializeBattleGrid();
        
        //adds a ship to the grid
        //Adds a ship object called ship to the grid by changing the shipPresent status of each desired location to true
        //Inputs: Ship object called ship
        //outputs: N/A (changes if a ship is present at certain locations on the grid though)
        void addShip(Ship& ship);

        //checks if a location at grid[row][col] is in the bounds of the 2d array
        //inputs - int row and int col, which are both positive and ranging from 0 to GRID_SIZE
        //outputs - true or false if the value at grid[row][col] is in bounds of the 2d array
        bool inBounds(int row, int col);

        //Checks if a ship can be placed in the desired path, using the length, row, column, and direction of the ship to figure this out
        //inputs - a Ship object called ship with a length less than GRID_SIZE and greater than 0
        //outputs - returns true if a ship can be placed at a spot
        bool checkIfShip(Ship ship);

        //marks a hit with an "X" on the grid
        //inputs - int row and int col, which are both positive integers from 0 to GRID_SIZE
        //outputs - none, but prints an "X" on the grid at the specified spot
        void markHit(int row, int col);

        //marks a miss with an "O" on the grid
        //inputs - int row and int col, which are both positive integers from 0 to GRID_SIZE
        //outputs - none, but prints an "O" on the grid at the specified spot
        void markMiss(int row, int col);

        //changes the status of the location at grid[row][col] to hit or missed
        //inputs - row and col, which are both positive integers from 0 to GRID_SIZE, and int status, which should be either 0, 1, or 2
        //outputs - nothing, but changes the status of the location at grid[row][col]
        void setStatus(int row, int col, int status);

        //gets the status (if a ship is present) at grid[row][col]
        //inputs - row and col, which are both positive integers from 0 to GRID_SIZE
        //outputs - gets the status of the location at grid[row][col]
        int getStatus(int row, int col);

        //true or false depending on if the location at grid[row][col] was already guessed
        //inputs - row and col, which are both positive integers from 0 to GRID_SIZE
        //outputs - true or false depending on if grid[row][col] was already guessed
        bool alreadyGuessed(int row, int col);

        //changes the shipPresent status of the location at grid[row][col] to true or false depending on what shipPresent is
        //inputs - row and col, which are both positive integers from 0 to GRID_SIZE, and a boolean value called shipPresent, which signifies what the status will change to
        //outputs - nothing, but changes the status at grid[row][col]
        void setShip(int row, int col, bool shipPresent);

        //prints if there is a ship at grid[col][row]
        //inputs - row and col, which are both positive integers from 0 to GRID_SIZE
        //outputs - true or false depending on if there is a ship at grid [row][col]
        bool hasShip(int row, int col);

        //returns the number of rows in the grid
        //inputs - none
        //outputs - returns the number of rows of the grid
        int numRows();

        //returns the number of columns in the grid
        //inputs - none
        //outputs - returns the number of columns in the grid
        int numCols();

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
        void printStatus();

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
        void printShips();

};

#endif