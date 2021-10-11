//part1.cpp
//CS171-1 CS1
//Aaron Borjas
//10/30/18
//this program prints all characters between two user-chosen values, and prints them out with a 
//user-chosen number of characters per line

#include <iostream>
using namespace std;


//function printChars
//printChars takes two chars, a starting value and an ending value, and then an integer. It then prints 
//all characters in between the two characters that are given
//Inputs - character ch1 (indicates starting position), character ch2 (indicates ending position), integer numPerLine (indicates the characters per line)
//Outputs - All characters between ch1 and ch2, with a new line after every numPerLine characters.
void printChars(char ch1, char ch2, int numPerLine) {
    int startRow = 0; //counter for number of characters in the line.

    //loop continues while start, which is ch1 as an int, is less than or equal to the int version of ch2. It increments by one each time the code runs
    for(int start = static_cast<int>(ch1); start <= static_cast<int>(ch2); start++) {
        if(startRow < numPerLine) {//if startRow is less than numPerLine
            cout << static_cast<char>(start) << " "; //cast start as a character and print char start with a space after it
            startRow++; //increment startRow by one
        }
        else { //if starRow is greater than or equal to numPerLine
            cout << endl; //new line
            startRow = 0;//put startRow down to 0;
        }
    }
}

int main() {
    char charStart = static_cast<char>(127), charFinish = static_cast<char>(0); // charStart is initialized as the 127th character on the ascii table and charFinish is initalized as the 1st character on the ascii table
    int numPerLine;

    cout << "Welcome to the character printer!" << endl; //tells the user what is going on.

    //tells user what to enter for charStart
    cout << "To start, enter the starting character (any character that doesn't have an ASCII value of 127): ";
    while(static_cast<int>(charStart) == 127) { //while charStart is equal to 127 (which should only run once, since charStart changes once the user gives input)
        cin >> charStart; //gets user input for charStart
        if(static_cast<int>(charStart) != 127) { //if charStart isn't equal to 127
            cout << "The starting character is " << charStart << endl; //print out charStart
        }
        else { //if charStart is equal to 127
            cout << "Enter a character without an ASCII value of 127!" << endl; //error message
        }
    }

    //tells user what to enter for charFinish
    cout << "Next enter the ending character (make sure it has an ASCII value greater than the starting character): ";
    while(static_cast<int>(charFinish) < static_cast<int>(charStart)) { //this code runs while charFinish is less than charStart (which if true gives an error message)
        cin >> charFinish; //get user input for charFinish
        if(static_cast<int>(charFinish) > static_cast<int>(charStart)) { //if charFinsih is greater than charStart
            cout << "The ending character is " << charStart << endl; 
        }
        else { //if charFinish is less than charStart
            cout << "Enter a character with an ASCII value greater than the starting character!" << endl; //error message
        }
    }

    //tells user what to enter for numPerLine
    cout << "Finally, enter the number of characters you want printed per line: ";
    cin >> numPerLine; //takes user input for numPerLine
    cout << "The number of characters to be printed per line is " << numPerLine << endl; //confirms what numPerLine is

    //says what will be printed
    cout << "Time to print all the characters between the first and last characters you entered: " << endl;

    printChars(charStart, charFinish, numPerLine); //calls the printChars function with the parameters charStart, charFinish, numPerLine
} 