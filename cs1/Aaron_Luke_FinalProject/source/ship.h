#ifndef SHIP_H
#define SHIP_H
#include <string>
using namespace std;

class Ship{
    private:
        int row = -1; //row is the row of the top or left-most value of the ship. -1 means it is unset
        int col = -1; //col is the col of the top or left-most value of the ship. -1 means it is unset
        int length; //the length of the ship
        int direction = -1; //direction can be vertical or horizontal, but is unset at first

        //gets the direction of the ship and changes it to a string
        //inputs - none
        //outputs - the direction of the ship as a string
        string directionToString();

    public:
        static const int UNSET = -1;
        static const int HORIZONTAL = 0;
        static const int VERTICAL = 1;

        Ship();

        //constructor for ship class
        //sets the default length to shipLength
        //inputs - shipLength, which is a postive int and either 2, 3, 3, 4, or 5
        //outputs - creates a new ship object
        Ship(int length);

        //method to check if a location for ship is set or not
        //inputs - none
        //outputs true or false based on the row and column values
        bool isLocationSet();

        //method to check if a ship's direction is set or not
        //inputs - none
        //outputs true or false depending on what the variable direction equals for a ship object
        bool isDirectionSet();

        //method to set the leftmost (horizontal) or topmost (vertical) row and column for the ship
        //inputs - newRow and newCol, which is a row and column that are positive integers between 0 and GRID_SIZE
        //outputs - changes the values of row and col for the top or leftmost positions of the ship
        void setLocation(int newRow, int newCol);

        //method to set the direction of the ship to horizontal or vertical
        //inputs - newDirection, which a positive integer that is either 0 or 1, 0 representing HORIZONTAL and 1 representing VERTICAL
        //outputs - changes direction to newDirection
        void setDirection(int direction);

        //method that gets the row of the top or leftmost value of the ship
        //no inputs
        //returns row of the top or leftmost row of the ship
        int getRow();

        //method that gets the column of the top or leftmost value of the ship
        //no inputs
        //returns the top or leftmost column of the ship
        int getCol();

        //method that gets the length of a ship
        //inputs - none
        //outputs - returns the length of a ship
        int getLength();

        //method that gets the direction of a ship as an integer
        //inputs - none
        //outputs - returns the integer value of direction of a ship
        int getDirection();
};

#endif