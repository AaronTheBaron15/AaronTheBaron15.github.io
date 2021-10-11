//part2.cpp
//CS171-1 CS1
//Aaron Borjas
//11/14/18
//Phone number translator

#include <iostream>
#include <string>
using namespace std;

//function charToNum
//Takes a character and turns it into a number
//Inputs - any character that is a letter
//Outputs - a number that corresponds with a letter on a phone's keypad
char charToNum(char ch) {

    //if the character is a b or c
    if( ((65 <= static_cast<int>(ch)) && (static_cast<int>(ch) <= 67)) || ((97 <= static_cast<int>(ch)) && (static_cast<int>(ch) <= 99)) ) {
        return '2'; //return 2
    }
    //if the character is d e or f
    else if( ((68 <= static_cast<int>(ch)) && (static_cast<int>(ch) <= 70)) || ((100 <= static_cast<int>(ch)) && (static_cast<int>(ch) <= 102)) ) {
        return '3'; //return 3
    }
    //if the character is g h or i
    else if( ((71 <= static_cast<int>(ch)) && (static_cast<int>(ch) <= 73)) || ((103 <= static_cast<int>(ch)) && (static_cast<int>(ch) <= 105)) ) {
        return '4'; //return 4
    }
    //if the character is j k or l
    else if( ((74 <= static_cast<int>(ch)) && (static_cast<int>(ch) <= 76)) || ((106 <= static_cast<int>(ch)) && (static_cast<int>(ch) <= 108)) ) {
        return '5'; //return 5
    }
    //if the character is m n or o
    else if( ((77 <= static_cast<int>(ch)) && (static_cast<int>(ch) <= 79)) || ((109 <= static_cast<int>(ch)) && (static_cast<int>(ch) <= 111)) ) {
        return '6'; //return 6
    }
    //if the character is p q r or s
    else if( ((80 <= static_cast<int>(ch)) && (static_cast<int>(ch) <= 83)) || ((112 <= static_cast<int>(ch)) && (static_cast<int>(ch) <= 115)) ) {
        return '7'; //return 7
    }
    //if the character is t u or v
    else if( ((84 <= static_cast<int>(ch)) && (static_cast<int>(ch) <= 86)) || ((116 <= static_cast<int>(ch)) && (static_cast<int>(ch) <= 118)) ) {
        return '8'; //return 8 
    }
    //if the character is w x y or z
    else if( ((87 <= static_cast<int>(ch)) && (static_cast<int>(ch) <= 90)) || ((119 <= static_cast<int>(ch)) && (static_cast<int>(ch) <= 122)) ) {
        return '9'; //return 9
    }
    return '0';
}

//function printString
//prints a string to the console
//Inputs - a string of any length
//Outputs - prints the string to the console
void printString(string str) {
    for(int i = 0; i < str.size(); i++) { //starts at 0 and increments by one until it reaches the final index of the string
        cout << str[i]; //prints the element of string at index i
    }
}

//function stringToPhoneNumber
//This function takes a text-based phone number and converts it to a number-based phone number (eg 1-800-WHITWORTH turns to 18009448967)
//Inputs - a word or string of any length 
//Outputs - an 11 digit number starting with 1800 ending with the number form of the string entered
void stringToPhoneNumber(string input_st, string output_st) {
    output_st = output_st + "_______"; //output_st is output_st + 7 other values.
    for(int start = 0; start < 7; start++) { //starts at 0 and increments by one until greater than or equal to 7
        output_st[start+4] = charToNum(input_st[start]); //output_st at index start+4 (after the 1800 part) is equal to charToNum of input_st at index start
        //cout << output_st << endl;
    }

    printString(output_st); //print the string
}

int main() {
    string textNumber, firstFour; //placeholder for the value the user enters

    cout << "Enter the four numbers for the distance (for example, 1800): "; //asks for the first four digits
    cin >> firstFour; //gets the first four digits

    cout << "Enter a word to be converted to a number: "; //tells user what to enter
    cin >> textNumber; //gets the user's value for textNumber

    cout << endl << endl << "The number version of the text number 1-800-" << textNumber << " is: " << endl; //tells the user what the output should be like
    stringToPhoneNumber(textNumber, firstFour); //prints the whole phone number
}
