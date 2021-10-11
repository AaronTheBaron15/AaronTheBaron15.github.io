//part3.cpp
//CS171-1 CS1
//Aaron Borjas
//10/9/18
//leaf scoreboard: uses a do while loop to get player name and score, and then compares the current score
//to the max score. If current score is greater than maxScore, a new maxName and maxScore are assigned based on
//the current players name and score.

#include <iostream>//cin and cout
#include <string> //strings
using namespace std;

int main() {
    string name, maxName;//name is current name, maxName is the current player with the max number of leaves
    int score, maxScore;//score is the current score, maxScore is the current top score


    do { //do all the following code before the while() loop
        cout << "What is the player's name? "; //tell the user what to input
        getline(cin, name); //this makes it so you can enter multiple words for a name. Ex: "Julio Jeffery Gonzalez III" would work as a name.

        if(name.compare("done") != 0) { //if the players name is not "done"
            cout << "How many leaves did the player collect? "; //tells the user what to input for score
            cin >> score; //just a cin instead of getline(cin, score) because score is an int and getline is for strings
            cin.ignore();//so the enter when entering score doesn't carry over to the getline() for name
            cout << name << "'s number of leaves is: " << score << endl; //tells the user what the information they entered was

            if(score > maxScore) //if the current score is greater than the maxScore
            {
                maxName = name; //sets the new holder of the most leaves(maxName) as name
                maxScore = score;//sets the new maxScore to score
            }
        }

        cout << endl; //adding a line between each player

    }
    while(name.compare("done") != 0); //while name is not equal to "done"

    cout << maxName << " had the most leaves with " << maxScore << " leaves" << endl; //tells the user who won
}