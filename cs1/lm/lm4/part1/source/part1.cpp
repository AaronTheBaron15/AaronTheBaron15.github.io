//part1.cpp
//CS171-1 CS1
//Aaron Borjas
//10/5/18
//ask for user input, based on that input tell the user if their character is a:
// lowercase letter, uppercase letter, number, special character, unprintable/whitespace

#include <iostream> //cin, cout
#include <cctype> //
using namespace std;

int main() {
    char userAns; //the variable for the user's input to be assigned to
    cout << "What is your character? "; //asking the user what they want
    cin.get(userAns); //assigning user input to userAns

    //uppercase letters
    //if the integer version of userAns is greater than or equal to 65 and less than or equal to 90...
    if( (65 <= static_cast<int>(userAns) ) && (static_cast<int>(userAns)<=90) ) {
        cout << "The ASCII value of " << userAns << " is " << static_cast<int>(userAns) << endl; //print the ASCII value of the answer (userAns as an int)
        cout << userAns << " is a uppercase letter!" << endl; //Print out userChar and what type of character it is.
    }
    //lowercase letters
    //otherwise, if the integer version of userAns is greater than or equal to 97 and less than or equal to 122...
    else if( (97 <= static_cast<int>(userAns) ) && (static_cast<int>(userAns)<=122) ) {
        cout << "The ASCII value of " << userAns << " is " << static_cast<int>(userAns) << endl;//print the ASCII value of the answer (userAns as an int)
        cout << userAns << " is a lowercase letter!" << endl;//Print out userChar and what type of character it is.
    }
    //numbers
    //otherwise, if the integer version of userAns is greater than or equal to 48 and less than or equal to 57...
    else if( (48 <= static_cast<int>(userAns) ) && (static_cast<int>(userAns)<=57) ) {
        cout << "The ASCII value of " << userAns << " is " << static_cast<int>(userAns) << endl;
        cout << userAns << " is a number!" << endl;//Print out userChar and what type of character it is.
    }
    //special characters
    //otherwise, if (33<=userAns as an int<=47), (58<=userAns as an int<=64), (91<=userAns as an int<=96), or (123<=userAns as an int<=126)...
    else if( ((33 <= static_cast<int>(userAns) ) && (static_cast<int>(userAns)<=47)) ||
    ((58 <= static_cast<int>(userAns) ) && (static_cast<int>(userAns)<=64)) ||
    ((91 <= static_cast<int>(userAns) ) && (static_cast<int>(userAns)<=96)) ||
    ((123 <= static_cast<int>(userAns) ) && (static_cast<int>(userAns)<=126)) ) {
        cout << "The ASCII value of " << userAns << " is " << static_cast<int>(userAns) << endl;//print the ASCII value of the answer (userAns as an int)
        cout << userAns << " is a special character!" << endl;//Print out userChar and what type of character it is.
    } 
    //unprintable/whitespace characters
    else if( ((0 <= static_cast<int>(userAns) ) && (static_cast<int>(userAns)<=32)) || 
    ( 127 == static_cast<int>(userAns)) ) {
        cout << "The ASCII value of " << userAns << " is " << static_cast<int>(userAns) << endl;//print the ASCII value of the answer (userAns as an int)
        cout << userAns << " is an unprintable or whitespace character!" << endl;//Print out userChar and what type of character it is.
    }
    //otherwise if none of the conditions are met...
    else {
        cout << "Enter a valid character!" << endl;
    }
}