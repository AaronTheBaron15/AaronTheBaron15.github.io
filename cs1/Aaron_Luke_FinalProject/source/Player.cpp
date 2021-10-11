#include "grid.h"
#include "location.h"
#include "ship.h"
#include "player.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//default constructor for the player class
//Creates a new grid for both the player and their opponent, a new array for the player's ships, and sets numShips, totalHitsTaken, and totalHitsDelivered to 0
Player::Player() {
    Grid myGrid; //initializes a new grid called myGrid
    Grid opponentGrid; //initializes a new grid called OpponentGrid

    //myShips[NUM_SHIPS] = Ship(); //creates a new array with NUM_SHIPS values called myShips

    numShips = 0; //starts with 0 ships
    totalHitsTaken = 0; //has not been attacked
    totalHitsDelivered = 0; //has not attacked the opponent
}

//method computeMaxHits, gets the maximum number of times you need to hit enemy locations to achieve a victory
//inputs - none
//outputs - returns the total amount of times the player needs to hit the enemy for a win
// int Player::computeMaxHits() {
//     int sum = 0; //sum of total needed hits starts at 0

//     //loops through the SHIP_LENGTHS array from index 0 to the final index, incrementing by one each time it loops
//     for(int index = 0; index < NUM_SHIPS; index++) {
//         sum += SHIP_LENGTHS[index]; //adds the value of SHIP_LENGTHS at index to sum
//     }
//     return sum; //returns the total amount of hits needed to win
// }

//method allSpotsHit, which checks if all the location of a ship have been hit
//inputs - an initialized Ship object called ship
//outputs - true or false depending on if all the locations have been marked as "hit"
bool Player::allSpotsHit(Ship ship) {
    int length = ship.getLength(); //length is equal to the length of the ship object
        
    bool result = false; //placeholder for the answer, which starts off as false
        
    if(ship.getDirection() == 0) { //if the ship is horizonal
        int sumShipHits = 0;//int sumShipHits, which is the total number of hits on the ship
            int row = ship.getRow(); //row is the row of the leftmost value of the ship (since the ship is horizontal)

            //col starts at the column of the leftmost location of the ship and increments by one until it is equal to the column value of the leftmost location plus the length of the ship
            //this essentially goes from the left of the ship to the right of the ship, starting where the leftmost column value of the ship is located at
            for(int col = ship.getCol(); col < ship.getCol() + length; col++) {
                if(myGrid.getStatus(row,col) == 1) { //if the status of the grid at myGrid[row][col] is hit
                    sumShipHits++; //add one to sumShipHits
                }
            }
            
            if(sumShipHits == length) { //if sumShipHits is equal to the length of the ship
                result = true; //set result to true
            }
        }
        
    if(ship.getDirection() == 1) { //if the ship is vertical
        int sumShipHits = 0; //sumShipHits starts at 0 and is the total number of hits on the ship

        //int row starts at the top location of the ship (since the ship is vertical) and increments by one until it is equal to the value of row at the top plus length of the ship
        //this essentially goes from the top to bottom of the ship through a 2D array, where the row changes but the column stays the same. It starts where the topmost value of the ship is located
        for(int row = ship.getRow(); row < ship.getRow() + length; row++) { 
            int col = ship.getCol(); //colunm is equal to the column of the topmost value of the ship. col never changes, which is why it is declared here
                
            if(myGrid.getStatus(row,col) == 1) { //if the status of the grid at myGrid[row][col] is hit
                sumShipHits++; //add one to sumShipHits
            }
        }
            
        if(sumShipHits == length) { //if sumShipHits is equal to the length of the ship
            result = true; //set result to true
        }
    }
    return result; //return result, which is true or false
}

//method isDestroyed, which checks if a ship has been hit at all of its locations and returns true if true
//inputs - int shipNumber, which is a positive integer from 0 to 4 and represents the index of the ship in the array
//outputs - true or false depending on if all the locations of the ship have been hit
bool Player::isDestroyed(int shipNumber){
    if(allSpotsHit(myShips[shipNumber])) { //if all the spots of the ship at myShips[shipNumber] have been hit
        return true; //return true
    }

    return false; //return false
}

//method intializeShipsRandomly, which randomly creates and adds NUM_SHIPS ships to a grid with random row and column values, but only if a ship can be placed
//input - none
//output - adds randomly placed ships to a grid, but checks to make sure the ships are inside the grid and not overlapping each other
void Player::initializeShipsRandomly() {
    srand(time(NULL));
    for(int arrayIndex = 0; arrayIndex < NUM_SHIPS; arrayIndex++){ //arrayIndex starts at 0, goes until greater than or equal to NUM_SHIPS and increments by one
        int length = SHIP_LENGTHS[arrayIndex];
        int dir;
        int row;
        int col; //int length is SHIP_LENGTHS at index arrayIndex, int dir, row, and col are placeholders for direction, row and column
        Ship ship = Ship(length); //makes a new ship of with length of SHIP_LENGTHS at index arrayIndex (2, 3, 3, 4, or 5)

        do { //do while loop that declares what direction, row, and column are equal to, then loops until those values give a ship that can be placed
            dir = rand() % 2; //direction is a random value from 0 to 1 (0 is horizontal and 1 is vertical)
            row = rand() % GRID_SIZE; //row is a random value from 0 to GRID_SIZE - 1
            col = rand() % GRID_SIZE; //col is a random value from 0 to GRID_SIZE - 1
            ship.setLocation(row, col); //sets the top/leftmost location of the ship to grid[row][col]
            ship.setDirection(dir); //sets the direction of the ship to dir
        }
        while (!myGrid.checkIfShip(ship)); //if the ship is not a valid ship on myGrid, go throug the do section again
    
        addShip(ship); //adds a ship to the grid
    }
}

//method addShip, which adds a ship to the grid and array of ships if the number of ships counter is less than the constant variable for maximum number of ships
//inputs - initialized Ship object called ship
//outputs - nothing, but adds a new ship to the grid of the player and the array of ships of the player, while incrementing numShips so ships can't be added indefinitely
void Player::addShip(Ship& ship) {
    if(numShips < NUM_SHIPS) { //if numShips (counter for current number of ships) is less than NUM_SHIPS (which is a constant variable for max number of ships)
        myGrid.addShip(ship); //adds the ship object to the player's grid
        myShips[numShips] = ship; //adds the ship object to the myShips array at index numShips
        numShips++; //adds one to numShips
    }
}

//method getRandomRowGuess, gets a random guess between 0 and GRID_SIZE
//inputs - none
//outputs - returns a random number between 0 and GRID_SIZE
int Player::getRandomRowGuess() {
    return rand() % GRID_SIZE;
}

//method getRandomColGuess, gets a random guess between 0 and GRID_SIZE
//inputs - none
//outputs - returns a random number between 0 and GRID_SIZE
int Player::getRandomColGuess() {
    return rand() % GRID_SIZE;
}

//method markGuess, which marks a location as hit if hitOrMiss is true, or as missed if hitOrMiss is false
//inputs - positive integers row and col, which are both within bounds of the grid. hitOrMiss is a boolean value which is true if hit and false if missed
//outputs - changes the status of locations on the grids
void Player::markGuess(int row, int col, bool hitOrMiss) {
    if(hitOrMiss) { //if hitOrMiss evaluates to true (there was a hit)
        opponentGrid.markHit(row, col); //mark a hit
        totalHitsDelivered++; //adds one to totalHitsDelivered
        
    }
    else { //if hitOrMiss evaluates to false (there was a miss)
        opponentGrid.markMiss(row, col); //marks a miss
    }
}

//method makeGuess, makes a guess for a player at a row and column on another player
//inputs - positive integers row and col, which are both within bounds of the grid. Player other which is an initialized player object
//outputs - returns true or false depending on if the guess was a hit
bool Player::makeGuess(int row, int col, Player& other) { 
    bool hit = other.recordOpponentGuess(row, col); //hit is if the enemy missed or hit at grid[row][col]
    markGuess(row, col, hit); //marks the guess as hit or missed based on if the boolean value "hit" is true or false
    return hit; //return hit, which is true or false based on if the guess was a hit
}

//method recordOpponentGuess, marks a hit or miss on the board with the opponent's guesses on a player's board, returns true if there was a hit
//inputs - positive integers row and col that are within the grid (row and col are greater than zero, row and col are less than GRID_SIZE)
//Outputs - false if the spot was already guessed or if the guess was a miss, true if the guess was a hit. 
bool Player::recordOpponentGuess(int row, int col) {
    if(myGrid.alreadyGuessed(row, col)) { //if the location at grid[row][col] is already guessed
        return false; //return false
    }
    if (myGrid.hasShip(row, col)) { //if the location has a ship at grid[row][col]
        myGrid.markHit(row, col); //mark the hit
        totalHitsTaken++;//add one to totalHitsTaken
        return myGrid.hasShip(row, col);
    }
    else if(!myGrid.hasShip(row, col)) { //if the location does not have a ship

        myGrid.markMiss(row, col); //mark a miss
        return myGrid.hasShip(row, col);
    }
    return myGrid.hasShip(row, col); //return a value based on if there is a ship at grid[row][col]
}

//method printMyShips, prints the player's board, which is just where their ships are located
//inputs - none
//outputs - prints the board with the player's ships on them, which shows where their ships are located
void Player::printMyShips() {
    myGrid.printShips();
}

//method printMyGuesses, prints the guesses a player has made on the opponent
//inputs - none
//outputs - prints the board with the player's misses and hits
void Player::printMyGuesses() {
    opponentGrid.printStatus();
}

//method printHitsDelivered, prints the total number of hits out of the maximum number of hits a player has hit
//Inputs - none
//outputs - none, but prints totalHitsDelivered out of maximum possible hits
void Player::printHitsDelivered() {
    cout << "Total hits is " << totalHitsDelivered << "/" << MAX_HITS;
}

//method hasWon, returns whether a player has won or not based on if totalHitsDelivered is equal to the maximum possible hits
//Inputs - none
//outputs - true if a player has won, false if otherwise
bool Player::hasWon() {
    //cout << "checking this totalHitsDelivered thing " << totalHitsDelivered << "/" << MAX_HITS << endl;
    return totalHitsDelivered == MAX_HITS; //returns true if totalHitsDelivered is equal to the maximum possible hits
}

//method chooseShipLocation, allows user to add a new ship, only if the ship is valid (inside the grid) 
//Inputs - an initialized ship object, positive integers that are values inside the grid (for row and column), and an integer that is 0 or 1 for direction (0 is horizontal, 1 is vertical)
//outputs - none, but adds a new ship to the grid of a player
void Player::chooseShipLocation(int row, int col, int direction, Ship& ship) {
    if(isValidShip(ship, row, col, direction)) { //if the ship is a valid ship
        ship.setLocation(row, col); //set the top/leftmost locaiton of the ship to row, col
        ship.setDirection(direction); //sets the direction of the ship to direction (which is horizontal or vertical)
        myGrid.addShip(ship); //adds the ship to the player's grid
        myShips[numShips] = ship; //adds the ship to the myShips array at index numShips
        numShips++; //adds one to numShips (so that new ships arent added indefinitely)
    }
    else { //otherwise if the ship is not valid
        cout << "Invalid ship!" << endl; //tell the user the ship is not valid
    }
}

//method isValidShip, checks if the ship object, which is located based on position at the left (horizontal) or top (vertical) and has a direction which is horizontal or vertical,
//is valid on the grid (if it is in bounds)
//Inputs - A Ship object that has been declared, a row and column which are integers and inside the grid, and a direction, which is either 0 or 1 (0 being horizontal and 1 being vertical)
//outputs - true if the ship is inside the grid (if row and col are inside the grid and if GRID_SIZE - length of ship is greater than a row (if vertical) or a column (if horizontal). False otherwise
bool Player::isValidShip(Ship ship, int row, int col, int direction) {
    //if the row number is greater than the maximum row value or less than zero, or if col is greater than the maximum column value or less than 0
    if((row > myGrid.numRows() || col > myGrid.numCols()) || (row < 0 || col < 0)) {
        //if row is greater than GRID_SIZE - length of ship and the ship is vertical, or if the column is greater than GRID_SIZE - length of ship and the ship is horizontal
        if((row > GRID_SIZE-ship.getLength() && direction == VERTICAL) || (col > GRID_SIZE-ship.getLength() && direction == HORIZONTAL) ) {
            return false; //return false
        }
    }
    return true; //return true
}




