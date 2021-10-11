//main.cpp
//CS172-1 CS2
//Aaron Borjas
//4/13/19
//this program experiments with file input and output

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void processInput(ifstream& input, int countArr[]) {
    string currLine; //creates a new string called currLine
    while(getline(input, currLine)) { //while the current line is not at the end of the file
        int i = 0; //creates a new integer called i, set to zero

        while(currLine[i] != '\0') { //while currLine at index i is not at the end of the line
            if(isalpha(currLine[i])) {//if the character at index i of currLine is a letter
                countArr[tolower(currLine[i])-'a']++; //increments (by one) countArr at the corresponding index of the letter (as a lowercase) that currLine is at index i 
            }
            i++; //increments i so that the while loop eventually ends
        }
    }
}

//getInput is a function that opens a file for input
//inputs - a parameter that is an ifstream instance takes in a user entered string which is the desired input file location
//output - none
void getInput(ifstream& input) {
    string userInput; //creates a string called userInput
    cout << "Enter a file to access: ";
    cin >> userInput; //gets user input for the string variable userInput

    input.open(userInput); //uses the input stream file to open the file chosen by the user in userInput

    while(input.fail()) { //while the input stream cannot open the userInput file
        cout << "Cannot access that location! Enter a file to access: "; //tells user that there was an error, and asks for input again
        cin >> userInput; //gets user input for the userInput variable
        input.open(userInput); //uses the input stream file to open the file chosen by the user in userInput
    }
}

//getOutput is a function that opens a file for output
//inputs - none
//outputs - creates a file for output.
void reportOutput(int countArr[], ofstream& file) {
    //opens a file called output_data.txt for the output
    file.open("output_data.txt"); //do not need to check if it works, since the input will be from getInput and will be a working 

    //prints the times each character appears in the file
    for(int i = 0; i < 26; i++) { //iterates through countArr
        file << char(i+'a') << ": " << countArr[i] << endl; //prints the character, with the number of times that character has appeared in the file
    }

    file.close(); //closes the file
}


int main() {
    ofstream outputFile;
    ifstream inputFile;
    int arrayOfCounts[26]; //Hold counts of every occurance of letter (0 = A, 25 = z)
    //initilize output file initOutput(outputFile)
    getInput(inputFile);

    //process input (inputFile, arrayOfCounts)
    processInput(inputFile, arrayOfCounts);

    //report output reportOutput(arrayOfCounts,outputFile)
    reportOutput(arrayOfCounts, outputFile);

}