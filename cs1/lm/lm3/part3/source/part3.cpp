//part3.cpp
//CS171-1 CS1
//Aaron Borjas
//10/2/18
//rock paper scissors

#include <iostream>//cin and cout
#include <cstdlib> //rand and srand
#include <ctime> //time
using namespace std;

int main() {
    srand(time(NULL));//seeding rand at current time
    int userChoice, compChoice;//initiate userChoice and compChoice for later
    
    //tells user what to input
    cout << "Welcome to Rock, Paper, Scissors. What is your move? (1-Rock, 2-Paper, 3-Scissors)" << endl;
    cin >> userChoice; //user inputs their number into userChoice
    compChoice = (rand()%3)+1; //compChoice is assigned to a pseudo-random number from 1-3

    if(userChoice == 1) //user rock
    {
        cout << "The user chose rock!" << endl;
        if(compChoice == 1) //computer rock
        {
            cout << "The computer picked rock!" << endl << "Tie! Go again!" << endl; //say what computer picked and who won
        }
        else if(compChoice == 2) // computer paper
        {
            cout << "The computer picked paper!" << endl << "The computer won! Better luck next time!" << endl; //say what computer picked and who won
        }
        else if(compChoice == 3)//computer scissors
        {
            cout << "The computer picked scissors!" << endl << "You won! Good job!" << endl; //say what computer picked and who won

        }
    }
    else if(userChoice == 2) //paper
    {
        cout << "The user chose paper!" << endl;
        if(compChoice == 1) //computer rock
        {
            cout << "The computer picked rock!" << endl << "Tie! Go again!" << endl; //say what computer picked and who won
        }
        else if(compChoice == 2) // computer paper
        {
            cout << "The computer picked paper!" << endl << "The computer won! Better luck next time!" << endl; //say what computer picked and who won
        }
        else if(compChoice == 3)//computer scissors
        {
            cout << "The computer picked scissors!" << endl << "You won! Good job!" << endl; //say what computer picked and who won

        }
    }
    else if(userChoice == 3) //scissors
    {
        cout << "The user chose scissors" << endl;
        if(compChoice == 1) //computer rock
        {
            cout << "The computer picked rock!" << endl << "Tie! Go again!" << endl; //say what computer picked and who won
        }
        else if(compChoice == 2) // computer paper
        {
            cout << "The computer picked paper!" << endl << "The computer won! Better luck next time!" << endl; //say what computer picked and who won
        }
        else if(compChoice == 3)//computer scissors
        {
            cout << "The computer picked scissors!" << endl << "You won! Good job!" << endl; //say what computer picked and who won

        }
    }
    else //if the user didn't pick 1, 2, or 3
    {
        cout << "Invalid entry! Enter 1 for rock, 2 for paper, or 3 for scissors"; //asks user for valid number
    }

}