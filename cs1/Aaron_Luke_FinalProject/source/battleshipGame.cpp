//battleshipGame.cpp
//CS171-1 CS1
//Aaron Borjas and Luke Orwig
//12/9/18
//makes a battleship game where a user can play battleship versus a computer or another player
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime> 
#include <cctype>

#include "ship.h"
#include "location.h"
#include "grid.h"
#include "player.h"

using namespace std;

//function getNumPlayers(), gets the total number of players (out of two) for access later
//inputs - asks for user input for the number of players playing, which is either 1 or 2
//outputs - returns the number of players, which should be one or two
int getNumPlayers() {
    int numPlayers = 1; // numPlayers defaults to just one player
    cout << "How many people are playing? One or two? (enter a number) "; //asks how many people are playing
    cin >> numPlayers; //gets a number for numPlayers

    return numPlayers; //returns the number of players that are playing
}

//function readDirection(), gets a number that is either 0 or 1 for the direction of a ship, 0 being horizontal and 1 being vertical
//inputs - gets user input for and integer that represents direction of the ship, 0 being horizontal and 1 being vertical
//outputs - outputs either 0 or 1 depending on what the user inputs
int readDirection() {
    int dir; //placeholder for direction 
    cout << "Enter a valid direction (0 = Horizontal, 1 = Vertical): ";
    cin >> dir; //gets user input for direction

    return dir; //returns direction of a ship
}

//function readCol(), gets a number from 0 to GRID_SIZE from the user, which represents the top (vertical) or leftmost (horizontal) value of the ship
//inputs - gets a number that represents the column from the user (the number is from 1 to GRID_SIZE+1)
//outputs - returns a number from 0 to GRID_SIZE
int readCol() {
    int col; //placeholder for col, which the user enters later
    cout << "Enter a column number between 1 and " << GRID_SIZE << ": "; //tells user to enter a number from 1 to GRID_SIZE
    cin >> col; //gets user input

    return col-1; //returns the number the user entered minus one because of zero indexing
}

//function readRow(), gets a character from the user from A to GRID_SIZE (as a character). This value is the row of the top(vertical) or leftmost (horizontal) row value of the ship
//inputs - gets user input for a character called row. 
//inputs - returns the character as a number
int readRow() {
    char row; //placeholder for row
    cout << "Enter a row letter between A and " << static_cast<char>(GRID_SIZE + 64) << ": "; //tells the user to enter a letter between A and GRID_SIZE as a character
    cin >> row; //gets user input

    row = toupper(row);

    return static_cast<int>(row - 'A'); //returns the row as an integer
}

//function initializeShipsFromInput, initializes all 5 ships of the player and makes sure they don't overlap
//inputs - A player class that has been initializes but the ships have not been set yet
//outputs - adds the ships at chosen locations on the player's board
void initializeShipsFromInput(Player& player) {
    srand(time(NULL));

    for(int addShips = 0; addShips < NUM_SHIPS; addShips++) { //addShips starts at 0 and goes up by one until it is greater than or equal to NUM_SHIPS
        
        cout << "Your current grid of ships: " << endl; 
        player.printMyShips(); //prints the empty board of the player so that they know where to put their ships

        cout << "Hit enter to place the next ship: ";
        cin.get();
            
        int length = player.SHIP_LENGTHS[addShips]; //int length is the length of the ship of SHIP_LENGTHS array at index addShips
        cout << "Now you need to place a ship of length " << length << endl; //says the length of the current ship
        int row = readRow(); //gets row from user input
        int col = readCol(); //gets col from user input
        int dir = readDirection(); //gets direction from user input
            
        Ship ship = Ship(length); //creates a new ship called ship with length length
        ship.setLocation(row, col); //sets the location of the top (vertical) or leftmost (horizontal) location of the ship
        ship.setDirection(dir); //sets the direction to dir
            
        if(player.isValidShip(ship, row, col, dir)) { //if the ship is valid on the grid
                player.chooseShipLocation(row, col, dir, ship); //puts the ship on the grid based on the row, column, and direction
        }
        else { //if the ship is not valid on the grid
            cout << "=====\n Invalid ship! \n=====" << endl; //error message
            addShips--; //decrement addShips
        }
    }
}

//function setUpShips, sets up the ships of player one and player two depending on how many players are playing (1 real player or 2 real players)
//inputs - two different players which have both been initializes but have not been fully set up (ships not set), and an integer numPlayers which is either 1 or 2, for the number of real players
//outputs - no visible outputs, but adds ships to both players grids
void setUpShips(int numPlayers, Player& p1, Player& p2) {
    srand(time(NULL));
    if(numPlayers == 1) { //if there is only one real player
        cout << "Player One, choose your ships!" << endl;
        initializeShipsFromInput(p1); //initializes the player's ships

        //randomly initializing because I'm lazy
        // p1.initializeShipsRandomly();
        p1.printMyShips();

        cout << "Press enter for the Computer to choose their ships: ";
        cin.get();

        //lots of endl's so that the next player can't see your ships
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        p2.initializeShipsRandomly(); //initialize the ships randomly for the computer
        p2.printMyShips();
        cout << "The computer has chosen their ships." << endl;
    }
    else if(numPlayers == 2) { //if there are two real players
        cout << "Player One, choose your ships! Make sure the other Player cannot see this!" << endl;
        initializeShipsFromInput(p1); //initialize the first player's ships
        // p1.initializeShipsRandomly();
        p1.printMyShips();

        cout << "Press enter to place your ships: ";
        cin.get();

        //lots of endl's so that the second player can't see the first player's grid
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        cout << "Make sure the other Player cannot see this!" << endl;

        //randomly
        // p2.initializeShipsRandomly();

        cout << "Player Two, choose your ships! Make sure the other Player cannot see this!" << endl;
        initializeShipsFromInput(p2); //initialize the first player's ships
        p2.printMyShips();

        //initializeShipsFromInput(p2); //initialize the second player's ships
        cout << "Player Two has chosen their ships." << endl;
    }
}

//function computerTurn, gets random guesses for the computer player onto the human player 
//inputs - two players who have been initializes and have their ships set
//outputs - no visible, but prints which ships were destroyed and executes a turn of the computer player
void computerTurn(Player& human, Player& computer) {
    for(int turns = 0; turns < 1; turns++) { //turns starts at 0 and goes up by 1 until it reaches 1.
        int row = computer.getRandomRowGuess(); //row is a random number from 0 to GRID_SIZE
        int col = computer.getRandomRowGuess(); //col is a random number from 0 to GRID_SIZE
        cout << "Computer player guesses row " << (row+1) << " and column " << (col+1) << endl; 

        bool hit = computer.makeGuess(row, col, human); //hit is true if the guess is a hit on the enemy player, and false if its a miss

        if(hit) { //if hit is true
            cout << "Computer got a hit!" << endl;
            turns--; //subtract one from turns so that the player gets another turn
            if(computer.hasWon()) { //if the computer has one exit the loop
                turns+=200;
            }
        }
        else { //if the hit is false
            cout << "Computer got a miss!" << endl;
        }

        for(int shipLengths = 0; shipLengths < NUM_SHIPS; shipLengths++) { //shipLengths starts at 0 and goes up by one until it is greater than or equal to the NUM_SHIPS of a player
            if(human.isDestroyed(shipLengths)) { //if the ship with length of shipLengths of the actual player is destroyed
                cout << "The ship with length " << human.SHIP_LENGTHS[shipLengths] << " was destroyed!" << endl; //say which ship was destroyed
            }
        }
    }
}

//function playerTurn, gets a guess of a row and column from user input from player one to player two (p1 and p2 being relative to player)
//inputs - two players who have been initializes and have their ships set
//outputs - no visible, but prints which ships were destroyed and executes a turn of the a human player
void playerTurn(Player& p1, Player& p2) {
    for(int turns = 0; turns < 1; turns++) { //turns starts at 0 and goes up by 1 until it reaches 1.
        cout << "The enemy's grid: " << endl;
        p1.printMyGuesses(); //prints the current guesses so that the player can choose based on what they've previously guessed

        cout << "Enter a guess: " << endl;

        int row = readRow(); //gets a user guess for a row
        int col = readCol(); //gets a user guess for a column

        cout << "Player guesses row " << (row+1) << " and column " << (col+1) << endl;

        //p2.printMyShips();
        bool hit = p1.makeGuess(row, col, p2); //hit is true if player 1's guess on player 2 at a row and column is a hit, false if it is a miss

        if(hit) { //if hit is true
            cout << "Player got a hit!" << endl << endl;
            turns--; //subtract one from turns to give the player another turn
            
            if(p1.hasWon()) { //if the player has won
                turns+=200; //exit the loop
            }
        }
        else { //if hit is false
            cout << "Player got a miss!" << endl;
        }

        for(int shipLengths = 0; shipLengths < NUM_SHIPS; shipLengths++) { //shipLengths starts at 0 and goes up by one until it is greater than or equal to the NUM_SHIPS of a player
            if(p2.isDestroyed(shipLengths)) { //if the ship with length of shipLengths of the actual player is destroyed
                cout << "The ship with length " << p2.SHIP_LENGTHS[shipLengths] << " was destroyed!" << endl; //say which ship was destroyed
            }
        }
    }
}

//function playRound, plays around by having a player take their turn, then the next player taking their turn
//inputs - two seperate fully initialized players (with ships set as well), and an integer that is either 1 or 2 for the number of players
//outputs - true or false depending on if any of the two players has won
bool playRound(int numPlayers, Player& p1, Player& p2) {
    if(numPlayers == 1){ //if there is only one real player
        playerTurn(p1, p2); //plays a player turn, with player one being the player that is taking their turn

        if(p1.hasWon()){ //if player 1 has won
        //cout << "hey whats up HOME SLICE" << endl;
            return true; //return true if player one has won
        }

        computerTurn(p1, p2); //play a turn for the computer
        return p2.hasWon(); //return true or false if player 2 has won
    }
    else if(numPlayers == 2) { //if there are two real players
        //lots of endl's so that the second player can't see the first player's grid
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cin.get();

        playerTurn(p1, p2); //play a turn for player one

        if(p1.hasWon()){ //if player one has won
            return true; //return true
        }
        
        //lots of endl's so that the second player can't see the first player's grid
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cin.get(); 

        playerTurn(p2, p1); //play a turn for player two

        return p2.hasWon(); //return is player two has won or not
    }

}

int main() {
    //srand(time(NULL));
    cout <<"=======================\nWelcome to Battle Ship\n=======================" << endl;
    
    int numPlayers = getNumPlayers(); //numPlayers gets user input for the number of players playing

    Player p1 = Player(); //creates a new player object called p1
    Player p2 = Player(); //creates a new player object called p2

    cin.get();

    setUpShips(numPlayers, p1, p2); //set up the ships for both players, and if there is only one real player, then p2 is set up as a computer
    
    cout << "Hit enter for next turn: ";
    cin.get();
    
    bool gameOver = false; //the game does not start off as over
        
    while(!gameOver) { //while the game is not over
        gameOver = playRound(numPlayers, p1, p2); //assign gameOver to true or false depending on if a player won a turn or not
    }
    
    if(p1.hasWon()) { //if player 1 has won
        cout << "Player 1 has won!" << endl; //say who won
    }
    else { //otherwise player 2 won
        cout << "Player 2 has won!" << endl; //say who won
    }
        
    cout << "Thanks for playing!";
}