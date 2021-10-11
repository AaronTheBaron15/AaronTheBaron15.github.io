#ifndef PLAYER_H
#define PLAYER_H

#include "ship.h"
#include "grid.h"
#include "location.h"

static const int NUM_SHIPS = 5; //sets the max number of ships to 5

class Player{
    private: //private variables and methods
        static const int UNSET = -1; //unset direction is -1
        static const int HORIZONTAL = 0; //horizontal direction is 0
        static const int VERTICAL = 1; //vertical direction is 1

        Grid myGrid; //creates a new grid for the player
        Grid opponentGrid; //creates a new grid for the opponent
        Ship myShips[NUM_SHIPS]; //creates a new ship array of length NUM_SHIPS
        int numShips; //declares a variable for the current number of ships on the player's board
        int totalHitsTaken; //the total hits the player has taken from the opponent
        int totalHitsDelivered; //the total number of times the player has hit the opponent's ships
        int MAX_HITS = 17; //computes the maximum number of hits for length of ships in the SHIP_LENGTHS array


    public:    
        int SHIP_LENGTHS[NUM_SHIPS] = {2, 3, 3, 4, 5}; //a list of the lengths of the ships

        //default constructor for the player class
        //Creates a new grid for both the player and their opponent, a new array for the player's ships, and sets numShips, totalHitsTaken, and totalHitsDelivered to 0
        Player();

        // //method computeMaxHits, gets the maximum number of times you need to hit enemy locations to achieve a victory
        // //inputs - none
        // //outputs - returns the total amount of times the player needs to hit the enemy for a win
        // int computeMaxHits();

        //method allSpotsHit, which checks if all the location of a ship have been hit
        //inputs - an initialized Ship object called ship
        //outputs - true or false depending on if all the locations have been marked as "hit"
        bool allSpotsHit(Ship ship);

        //method isDestroyed, which checks if a ship has been hit at all of its locations and returns true if true
        //inputs - int shipNumber, which is a positive integer from 0 to 4 and represents the index of the ship in the array
        //outputs - true or false depending on if all the locations of the ship have been hit
        bool isDestroyed(int shipNumber);

        //method addShip, which adds a ship to the grid and array of ships if the number of ships counter is less than the constant variable for maximum number of ships
        //inputs - initialized Ship object called ship
        //outputs - nothing, but adds a new ship to the grid of the player and the array of ships of the player, while incrementing numShips so ships can't be added indefinitely
        void initializeShipsRandomly();

        //method addShip, which adds a ship to the grid and array of ships if the number of ships counter is less than the constant variable for maximum number of ships
        //inputs - initialized Ship object called ship
        //outputs - nothing, but adds a new ship to the grid of the player and the array of ships of the player, while incrementing numShips so ships can't be added indefinitely
        void addShip(Ship& ship);

        //method getRandomRowGuess, gets a random guess between 0 and GRID_SIZE
        //inputs - none
        //outputs - returns a random number between 0 and GRID_SIZE
        int getRandomRowGuess();

        //method getRandomColGuess, gets a random guess between 0 and GRID_SIZE
        //inputs - none
        //outputs - returns a random number between 0 and GRID_SIZE
        int getRandomColGuess();

        //method makeGuess, makes a guess for a player at a row and column on another player
        //inputs - positive integers row and col, which are both within bounds of the grid. Player other which is an initialized player object
        //outputs - returns true or false depending on if the guess was a hit
        bool makeGuess(int row, int col, Player& other);

        //method markGuess, which marks a location as hit if hitOrMiss is true, or as missed if hitOrMiss is false
        //inputs - positive integers row and col, which are both within bounds of the grid. hitOrMiss is a boolean value which is true if hit and false if missed
        //outputs - changes the status of locations on the grids
        void markGuess(int row, int col, bool shipPresent);

        //method recordOpponentGuess, marks a hit or miss on the board with the opponent's guesses on a player's board, returns true if there was a hit
        //inputs - positive integers row and col that are within the grid (row and col are greater than zero, row and col are less than GRID_SIZE)
        //Outputs - false if the spot was already guessed or if the guess was a miss, true if the guess was a hit. 
        bool recordOpponentGuess(int row, int col);

        //method printMyShips, prints the player's board, which is just where their ships are located
        //inputs - none
        //outputs - prints the board with the player's ships on them, which shows where their ships are located
        void printMyShips();

       //method printMyGuesses, prints the guesses a player has made on the opponent
        //inputs - none
        //outputs - prints the board with the player's misses and hits
        void printMyGuesses();

        //method printHitsDelivered, prints the total number of hits out of the maximum number of hits a player has hit
        //Inputs - none
        //outputs - none, but prints totalHitsDelivered out of maximum possible hits
        void printHitsDelivered();

        //method hasWon, returns whether a player has won or not based on if totalHitsDelivered is equal to the maximum possible hits
        //Inputs - none
        //outputs - true if a player has won, false if otherwise
        bool hasWon();

        //method chooseShipLocation, allows user to add a new ship, only if the ship is valid (inside the grid) 
        //Inputs - an initialized ship object, positive integers that are values inside the grid (for row and column), and an integer that is 0 or 1 for direction (0 is horizontal, 1 is vertical)
        //outputs - none, but adds a new ship to the grid of a player
        void chooseShipLocation(int row, int col, int direction, Ship& ship);

        //method isValidShip, checks if the ship object, which is located based on position at the left (horizontal) or top (vertical) and has a direction which is horizontal or vertical,
        //is valid on the grid (if it is in bounds)
        //Inputs - A Ship object that has been declared, a row and column which are integers and inside the grid, and a direction, which is either 0 or 1 (0 being horizontal and 1 being vertical)
        //outputs - true if the ship is inside the grid (if row and col are inside the grid and if GRID_SIZE - length of ship is greater than a row (if vertical) or a column (if horizontal). False otherwise
        bool isValidShip(Ship ship, int row, int col, int direction);


};

#endif