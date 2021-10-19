//board.cs
//Aaron Borjas & Caleb Grode
//1/21/2020
//cs371
//Dr. Bell, Jude Battista
//this file contains information about a small exception handling class and then the mega big board class which basically controls the whole game

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;
using System.Windows.Forms;
using System.Windows.Ink;

namespace _2048WindowsAppsCS371
{
    //badPlacement: an exception handling class. thats it
    [Serializable]
    class badPlacement : ApplicationException
    {
        public badPlacement() { }
        public badPlacement(string message) : base(message) { }
        public badPlacement(string message, System.Exception inner) : base(message, inner) { }
        protected badPlacement(System.Runtime.Serialization.SerializationInfo info, System.Runtime.Serialization.StreamingContext context) : base(info, context) { }


    }

    //controls the whole game basically (score, has won vs has lost, tile class
    class Board
    {

        public int score { get; set; } //what the score of the game is, when two tiles are combined the resulting tile adds to the score
        public bool hasWon { get; set; } //if the board has won at all
        public bool hasLost { get; set; } //if the board has lost at all
        public Tile[,] board { get; set; } //creates a 2D array of tiles

        //default constructor, sets everything to desired default values
        public Board()
        {
            hasWon = false; //hasnt won 
            hasLost = false; //hasnt lost
            board = new Tile[4, 4]; //sets the values of the board to new tiles
            boardSetup(); //sets up the board
            score = 0;
        }

        //boardSetup sets the values colors and stuff of the board
        //inputs - none
        //outputs - makes the tiles of the board have colors and creates two new tiles to start the game off
        public void boardSetup()
        {
            for (int i = 0; i < 4; i++) //iterates through row
            {
                for (int j = 0; j < 4; j++) //iterates through column
                {

                    board[i, j] = new Tile(); //sets the tile at the row, col position to empty
                }
            }

            Random rand = new Random(); //new Random class instance for making new tiles 
            for (int i = 0; i < 2; i++) //iterates until two new tiles placed
            { 
                int row = rand.Next(4); //row is a random number 0-3
                int col = rand.Next(4); //col is a random number 0-3
                try
                {
                    if (board[row, col].color == Colors.DarkGray) //if the color of the random spot is "empty"
                    {
                        int randNum = rand.Next(10);
                        if (randNum % 2 == 1) //if row is even
                        {
                            board[row, col] = new Tile("2");
                        }
                        else if (randNum % 2 == 0)
                        {
                            board[row, col] = new Tile("4"); //create a new tile with a number 
                        }
                        //board[row, col] = new Tile("2"); //create a new tile with a number 
                    }
                    else //otherwise if there was a tile there
                    {
                        throw new badPlacement("Cannot place on top of another tile!"); //throw bad placement exception with message
                    }
                }
                catch (badPlacement b) //catch the bad placement exception
                {
                    Console.WriteLine("THERE WAS SOMETHING THERE. {0}", b.Message); //print the exception
                    i--; //decrement i
                }
            }
            //board[0, 0] = new Tile("1024");
            //board[0, 1] = new Tile("2");
            //board[0, 2] = new Tile("8");
            //board[0, 3] = new Tile("2");

            //board[1, 0] = new Tile("1024");
            //board[1, 1] = new Tile("4");
            //board[1, 2] = new Tile("2");
            //board[1, 3] = new Tile("4");

            //board[2, 0] = new Tile("16");
            //board[2, 1] = new Tile("2");
            //board[2, 2] = new Tile("4");
            //board[2, 3] = new Tile("2");

            //board[3, 0] = new Tile("2");
            //board[3, 1] = new Tile("4");
            //board[3, 2] = new Tile("2");
            //board[3, 3] = new Tile("4");

        }

        //bool win, checks if the tile is 2048, which means that there is a win
        //input - Tile t which has a value
        //output - returns true if the tile is 2048, false otherwise
        public bool win(Tile t)
        {
            if (t.value == "2048") //if the value of t is 2048
            {
                Console.WriteLine("You win!"); //say that you won
                hasWon = true; //make hasWon to true
                
                return true; //return true
            }
            
            return false; //didnt win :(
        }


        //void combine, combines two tiles to a row and col position
        //inputs - two tiles with values, two ints; one for row, one for col. row and col must be 0, 1, 2, or 3
        //output - combines to tiles to a certain position
        public void combine(Tile one, Tile two, int row, int col)
        {
            score += Int32.Parse(one.value) + int.Parse(two.value);
            Tile newTile = one + two; //makes a new tile with a value of one.value + two.value
            one.value = ""; //makes one.value empty 
            one.color = Colors.DarkGray; //makes the color empty

            two.value = ""; //makes two.value empty
            two.color = Colors.DarkGray; //makes the color empty

            
            newTile.row = row; //sets the row of newTile to input row
            newTile.col = col; //sets the col of newTile to input col
            newTile.combined = true; //sets combined to true so it isnt combined again
            board[row, col] = newTile; //sets the tile at the input row and col position on the board to newtile

            win(newTile); //check if the new tile is 2048 and therefore if the game is won
        }

        //void reset
        //inputs - none
        //outputs - makes it so all tiles can be combined
        public void reset()
        {
            for (int i = 0; i < 4; i++) //increments through row
            {
                for (int j = 0; j < 4; j++) //increments through col
                {
                    board[i, j].combined = false; //makes it so all tiles can be combined
                }
            }
        }

        //void turn
        //inputs - string holding the direction from key input
        //outcome - selects the correct movement function based off the direction and sets the board for the next turn
        public void turn(string direction)
        {
            switch (direction) //switch based off the direction
            {
                case "up":
                      moveUp();
                      break;
                case "down":
                    moveDown();                    
                    break;
                case "right":
                    moveRight();                    
                    break;
                case "left":
                    moveLeft();                    
                    break;
            }
            randTile(); //create a new random tile on the board
            checkLose(); //check if the user has lost
            reset(); //set each tile back to a mergeable state 
        }

        //bool canCombineOrMove
        //inputs - Tile to check, row, column
        public bool canCombineOrMove(Tile t, int i, int j)
        {

            if (j > 0) //if the tile to the left is not out of bounds
            {
                if (board[i, j].CompareTo(board[i, j - 1]) == 0) //if the tiles are the same (or one tile is empty indicating a possible move)
                {
                    return true; 
                }
            }

            if (i > 0)  //if the tile above is not out of bounds
            {
                if (board[i, j].CompareTo(board[i - 1, j]) == 0)
                {
                    return true;
                }
            }

            if (j < 3) //if the tile to the left is not out of bounds
            {
                if (board[i, j].CompareTo(board[i, j + 1]) == 0 )
                {
                    return true;
                }
            }
            if (i < 3) //if the tile below is not out of bounds
            {
                if (board[i, j].CompareTo(board[i + 1, j]) == 0)
                {
                    return true;
                }
            }

            return false; //if we reach this case, the tile cannot be combined or moved
        }

        //bool checkLose
        //inputs - none
        //output - true or false value of if the user has lost the game
        public bool checkLose()
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (canCombineOrMove(board[i, j], i, j)) //looping through each tile on the board, if it can be combined
                    {
                        return false; //then the user has not lost yet
                        
                    }
                }
            }

            //if we reach this case the user has lost
            Console.WriteLine("You loSTTTTTTTTTTTTTTTTTTTTTTTTTTTT");
            hasLost = true; //set lost value to true
            return true; 
        }

        //public isFull
        //inputs - none
        //output - bool value of if the board is full of tiles
        public bool isFull()
        {
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (board[i, j].value == "") //loop through each tile on the board. if we find an epty tile return false
                    {
                        return false;
                    }
                }
            }
            //if we made it through every tile
            return true; //the board is full
        }

        public void randTile()
        {
            if (!isFull()) //as long as the board is not full
            {
                Random r = new Random(); //create a new random object
                for (int i = 0; i < 1; i++) //go until a tile has been created
                {
                    //create random values from 0 to 3 for the row and column
                    int row = r.Next(4); 
                    int col = r.Next(4);
                    try
                    {
                        if (board[row, col].color == Colors.DarkGray) //if the location at the random row and column is empty
                        {
                            int randNum = r.Next(10); //create a new random value for if the new tile is a 2 or 4
                            if (randNum == 9) //create a 4 10% of the time
                            {
                                board[row, col].value = "4";
                                board[row, col].color = Colors.Tan;
                            }
                            else //the other 90% create a 2
                            {
                                board[row, col].value = "2";
                                board[row, col].color = Colors.LightGray;
                            }
                        }
                        else //if the location on the board at the random row and column is not empty
                        {
                            throw new badPlacement("Cannot place on top of another tile!"); //throw a badPlacement exception
                        }
                    }
                    catch (badPlacement b) //catch the exception
                    {
                        Console.WriteLine("There was something there :'(. {0}", b.Message); //write the message from the exception
                        i--; //decrease the value of i to restart the process and force new values for row and col
                    }
                }
            }
        }

        //void moveUp
        //inputs - none
        //ouputs - moves all tiles upwards in their respective columns, begins combining process
        private void moveUp() // - and j,i
        {
            int numOpen = 0; //the current number of open spaces on one row/col
            
            for(int i = 0; i < 4; i++) //increments through the row
            {
                for(int j = 0; j < 4; j++) //increments through the column
                {
                    Console.WriteLine("i: {0}, j: {1}", i, j);
                    if (board[j, i].value == "") //if the value of the current tile is empty
                    {
                        numOpen++; //increment numopen
                        
                    }
                    else //if the current tile is not empty
                    {
                        //prevents checking out of bounds, prevents trying to combine with something that doesnt exist, makes sure the two values "next" to each other are the same
                        //and makes sure the two tiles have not been combined
                        if (j - numOpen - 1 >= 0  && j != 0 && board[j, i].value == board[j - numOpen - 1, i].value && !board[j, i].combined && !board[j - numOpen - 1, i].combined) 
                        {
                            combine(board[j, i], board[j - numOpen - 1, i], j-numOpen-1,i); //combine the two tiles to the position of the second tile
                            j = j - numOpen - 1; //sets j to the location of where the combined tile was placed
                        }
                        else //otherwise,
                        {
                            if (j != 0 && board[j - 1, i].value == "") //if the tile is not touching the left wall and the there is not another tile blocking the way
                            {
                                board[j - numOpen, i].color = board[j, i].color; //move tile up the number of open spaces
                                board[j - numOpen, i].value = board[j, i].value;
                                Console.WriteLine("Num open: " + numOpen);
                                Console.WriteLine("Moving tie {0},{1} to {2},{3}", j, i, j - numOpen, i);
                                board[j, i].color = Colors.DarkGray; //"delete" old tile
                                board[j, i].value = "";
                                j = j - numOpen; //sets us back to tile that was just moved

                            }
                        }
                        numOpen = 0; //sets numopen back to 0
                    }                    
                }
                numOpen = 0; //sets numopen back to zero
            }
        }

        //void movedown
        //inputs - none
        //ouputs - moves all tiles down in their respective columns, begins combining process
        void moveDown() // + and j,i
        {
            int numOpen = 0; //number of open spaces
            for (int i = 0; i < 4; i++) //increments through rows
            {
                for (int j = 3; j >= 0; j--) //decrements columns
                {
                    Console.WriteLine("i: {0}, j: {1}", i, j);
                    Console.WriteLine("numOpen: {0}", numOpen);
                    if (board[j, i].value == "")
                    {
                        numOpen++;

                    }
                    else
                    {
                        //prevents checking out of bounds, prevents trying to combine with something that doesnt exist, makes sure the two values "next" to each other are the same
                        //and makes sure the two tiles have not been combined
                        if (j+numOpen+1 < 4 && j != 3 && board[j, i].value == board[j + numOpen + 1, i].value && !board[j, i].combined && !board[j + numOpen + 1, i].combined) //j is not 3 (protects out of bounds) and checks if the tile we want to move can combine with the tile AFTER the position it would move to
                        {
                            combine(board[j, i], board[j + numOpen + 1, i], j + numOpen + 1, i);
                            j = j + numOpen + 1;
                        }
                        else
                        {
                            if (j != 3 && board[j + 1, i].value == "") //if the tile is not touching the bottom wall and the there is not another tile blocking the way
                            {
                                board[j + numOpen, i].color =
                                    board[j, i].color; //move tile up the number of open spaces
                                board[j + numOpen, i].value = board[j, i].value;
                                Console.WriteLine("Num open: " + numOpen);
                                Console.WriteLine("Moving tie {0},{1} to {2},{3}", j, i, j + numOpen, i);
                                board[j, i].color = Colors.DarkGray; //"delete" old tile
                                board[j, i].value = "";
                                j = j + numOpen; //sets us back to tile that was just moved

                            }
                        }
                        numOpen = 0;
                    }
                }
                numOpen = 0;
            }

        }

        //void moveRight
        //inputs - none
        //ouputs - moves all tiles right in their respective columns, begins combining process
        void moveRight() // + and i,j
        {
            int numOpen = 0;
            for (int i = 0; i < 4; i++)
            {
                for (int j = 3; j >= 0; j--)
                {
                    Console.WriteLine("i: {0}, j: {1}", i, j);
                    Console.WriteLine("numOpen: {0}", numOpen);
                    if (board[i, j].value == "")
                    {
                        numOpen++;

                    }
                    else
                    {
                        //prevents checking out of bounds, prevents trying to combine with something that doesnt exist, makes sure the two values "next" to each other are the same
                        //and makes sure the two tiles have not been combined
                        if (j + numOpen + 1 < 4 && j != 3 && board[i, j].value == board[i, j + numOpen + 1].value && !board[i, j].combined && !board[i, j + numOpen + 1].combined) //j is not 3 (protects out of bounds) and checks if the tile we want to move can combine with the tile AFTER the position it would move to
                        {
                            Console.WriteLine("Combining tile {0},{1} with tile {2},{3}", i, j, i, j+ numOpen +1);
                            combine(board[i, j], board[i, j + numOpen + 1],i, j + numOpen + 1);
                            j = j + numOpen + 1;//sets us back to tile that was just moved

                        }
                        else
                        {
                            if (j != 3 && board[i, j + 1].value == "") //if the tile is not touching the right wall and the there is not another tile blocking the way
                            {
                                board[i, j + numOpen].color = board[i, j].color; //move tile up the number of open spaces
                                board[i, j + numOpen].value = board[i, j].value;
                                Console.WriteLine("Num open: " + numOpen);
                                Console.WriteLine("Moving tie {0},{1} to {2},{3}", i, j, i, j + numOpen);
                                board[i, j].color = Colors.DarkGray; //"delete" old tile
                                board[i, j].value = "";
                                j = j + numOpen;//sets us back to tile that was just moved

                            }
                        }
                        numOpen = 0;
                    }                    
                }
                numOpen = 0;
            }

        }

        //void moveLeft
        //inputs - none
        //ouputs - moves all tiles left in their respective columns, begins combining process
        void moveLeft() //- and i,j
        {
            int numOpen = 0;

            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    Console.WriteLine("i: {0}, j: {1}", i, j);
                    Console.WriteLine("numOpen: {0}", numOpen);
                    if (board[i, j].value == "")
                    {
                        numOpen++;

                    }
                    else
                    {
                        //prevents checking out of bounds, prevents trying to combine with something that doesnt exist, makes sure the two values "next" to each other are the same
                        //and makes sure the two tiles have not been combined
                        if (j - numOpen - 1 >= 0 && j != 0 && board[i, j].value == board[i, j - numOpen - 1].value && !board[i, j].combined && !board[i, j - numOpen - 1].combined ) //j is not 0 (protects out of bounds) and checks if the tile we want to move can combine with the tile AFTER the position it would move to
                        {
                            combine(board[i, j], board[i, j - numOpen - 1], i, j - numOpen - 1);
                            j = j - numOpen - 1;//sets us back to tile that was just moved
                        }
                        else
                        {
                            if (j != 0 && board[i, j - 1].value == "") //if the tile is not touching the left wall and the there is not another tile blocking the way
                            {
                                board[i, j - numOpen].color =
                                    board[i, j].color; //move tile up the number of open spaces
                                board[i, j - numOpen].value = board[i, j].value;
                                Console.WriteLine("Num open: " + numOpen);
                                Console.WriteLine("Moving tie {0},{1} to {2},{3}", i, j, i, j - numOpen);
                                board[i, j].color = Colors.DarkGray; //"delete" old tile
                                board[i, j].value = "";
                                j = j - numOpen;//sets us back to tile that was just moved

                            }
                        }
                        numOpen = 0;
                    }
                }
                numOpen = 0;
            }
        }

    }
}
