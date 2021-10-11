using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Input;
using MessageBox = System.Windows.MessageBox;

namespace _2048WindowsAppsCS371
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        Board board = new Board(); //creates a board available for the whole MainWindow partial class
        private bool alreadyWon = false; //makes a bool for if the board has been won

        //Window_KeyDown
        //inputs - takes in a sender object and a keyevent event argument
        //output - executes a turn on the board based on key input
        private void Window_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.Up) //if the key is up arrow
            {
                Console.WriteLine("You pressed up!");
                   
                board.turn("up"); //play a turn with "up" as the direction
            }
            if (e.Key == Key.Down) //if the key is down
            {
                Console.WriteLine("You pressed down!");
                board.turn("down");//play a turn with "down" as the direction
            }
            if (e.Key == Key.Right) //if the key is right
            {
                Console.WriteLine("You pressed right!");
                board.turn("right");//play a turn with "right" as the direction
            }
            if (e.Key == Key.Left) //if the key is left
            {
                Console.WriteLine("You pressed left!");
                board.turn("left");//play a turn with "left" as the direction
            }
            paintTiles(); //refresh tiles
            showWin(); //show a win if there is one
            showLoss(); //show a loss if there is one
        }

        //showLoss
        //input - no
        //output - shows the loss screen
        public void showLoss()
        {
            if (board.hasLost)
            {
                Lose.Opacity = 0.5;
                LoseRec.Opacity = 0.5;
                LoseBlock.Opacity = 1;
            }
        }

        //showWin
        //input - no
        //output - show win screen and continue button
        public void showWin()
        {
            if (board.hasWon && !alreadyWon)
            {
                alreadyWon = true;
                Win.Opacity = 0.5;
                WinRec.Opacity = 0.5;
                WinBlock.Opacity = 1;
                continueButtonName.Visibility = Visibility.Visible;
            }
        }

        //basically the main
        public MainWindow()
        {
            InitializeComponent(); //initializes components
            paintTiles(); //paints tiles
            alreadyWon = false; //sets alreadyWon to false

        }

        //paintTiles
        //input - no
        //output - refreshes the xaml based on the c# code stuff and property things
        void paintTiles()
        {
            scorebox.Text = board.score.ToString(); //sets the score

            SolidColorBrush brush = new SolidColorBrush(board.board[0, 0].color); //creates a new brush that takes in the color of the board at row,col
            r0c0.Fill = brush; //fills the rectangle at row, col with brush's color
            r0c0t.Text = board.board[0, 0].value; //sets the text of the tile to the value of the tile at row, col

            //the rest is doing the same as the previous three lines

            brush = new SolidColorBrush(board.board[1, 0].color);
            r1c0.Fill = brush;
            r1c0t.Text = board.board[1, 0].value;

            brush = new SolidColorBrush(board.board[2, 0].color);
            r2c0.Fill = brush;
            r2c0t.Text = board.board[2, 0].value;

            brush = new SolidColorBrush(board.board[3, 0].color);
            r3c0.Fill = brush;
            r3c0t.Text = board.board[3, 0].value;

            brush = new SolidColorBrush(board.board[0, 1].color);
            r0c1.Fill = brush;
            r0c1t.Text = board.board[0, 1].value;

            brush = new SolidColorBrush(board.board[1, 1].color);
            r1c1.Fill = brush;
            r1c1t.Text = board.board[1, 1].value;

            brush = new SolidColorBrush(board.board[2, 1].color);
            r2c1.Fill = brush;
            r2c1t.Text = board.board[2, 1].value;

            brush = new SolidColorBrush(board.board[3, 1].color);
            r3c1.Fill = brush;
            r3c1t.Text = board.board[3, 1].value;

            brush = new SolidColorBrush(board.board[0, 2].color);
            r0c2.Fill = brush;
            r0c2t.Text = board.board[0, 2].value;

            brush = new SolidColorBrush(board.board[1, 2].color);
            r1c2.Fill = brush;
            r1c2t.Text = board.board[1, 2].value;

            brush = new SolidColorBrush(board.board[2, 2].color);
            r2c2.Fill = brush;
            r2c2t.Text = board.board[2, 2].value;

            brush = new SolidColorBrush(board.board[3, 2].color);
            r3c2.Fill = brush;
            r3c2t.Text = board.board[3, 2].value;

            brush = new SolidColorBrush(board.board[0, 3].color);
            r0c3.Fill = brush;
            r0c3t.Text = board.board[0, 3].value;

            brush = new SolidColorBrush(board.board[1, 3].color);
            r1c3.Fill = brush;
            r1c3t.Text = board.board[1, 3].value;

            brush = new SolidColorBrush(board.board[2, 3].color);
            r2c3.Fill = brush;
            r2c3t.Text = board.board[2, 3].value;

            brush = new SolidColorBrush(board.board[3, 3].color);
            r3c3.Fill = brush;
            r3c3t.Text = board.board[3, 3].value;
        }

        //resetBoard
        //input - the sender button and a routedeventargs event
        //output - sets everything to defualt
        public void resetBoard(object sender, RoutedEventArgs e)
        {
            //sets everything back to the default values
            board.score = 0; 
            board.boardSetup();
            paintTiles();
            Lose.Opacity = 0;
            LoseRec.Opacity = 0;
            LoseBlock.Opacity = 0;
            Win.Opacity = 0;
            WinRec.Opacity = 0;
            WinBlock.Opacity = 0;
            board.hasLost = false;
            board.hasWon = false;
            
        }

        //continueButton
        //input - the sender button and a routedeventargs event
        //output - continue the game upon victory
        public void continueButton(object sender, RoutedEventArgs e)
        {
            //wipes victory screen away without resetting board
            Console.WriteLine("continue clicked");
            Win.Opacity = 0;
            WinRec.Opacity = 0;
            WinBlock.Opacity = 0;
            continueButtonName.Visibility = Visibility.Hidden;
        }

    }
}
