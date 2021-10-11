//main.cpp
//CS172-1 CS2
//Aaron Borjas
//4/18/2019
//this program uses file input and file output to read and manipulate data from the most common baby 
//names for boys and girls from 2013 to 2017

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

//getPath is referenced from getInput() in LM8.2
//getPath is a function takes in user input of a file path
//inputs - none
//output - returns the file path that the user entered
string getPath() {
    string userInput; //creates a string called userInput
    cout << "Enter the path to the data file with babyNames: ";
    cin >> userInput; //gets user input for the string variable userInput

    //from here until input.close() is testing if the file directory is valid
    ifstream input; //creates a new instance of input stream
    input.open(userInput+"/babyNames2013.dat"); //opens userInput plus the first babyNames file (because input wants to open a file, not a folder)
    while(input.fail()) { //while the input file fails to open
        cout << "Enter the path to the data file with babyNames: "; 
        cin >> userInput; //gets user input for the string variable userInput
        input.open(userInput+"/babyNames2013.dat"); //opens userInput plus the first babyNames file (because input wnats to open a file, not a folder)
    }
    input.close(); //closes the input stream


    return userInput; //returns the user's file directory
}

//THIS IS IMPLEMENTED FROM LM7.2
//binarySearch, which searches a sorted array of integers for a specific number and returns the index of the number. if the number does not exist, returns the negative index of where it should be
//inputs - an integer array, whose length is determinded by a start point and end point (indeces), and an integer desiredNum that is the number being searched for in the array
//outputs - returns the index of the desired number, but if the number is not in the array, prints where it would go
template <typename Type>
int binarySearch(vector<Type> vect, int start, int end, Type desiredNum) {
    int midIndex = ((end-start)/2)+start;//the middle index is equal to end index minus start index, divided by two, and then addings start index to that value
    if(end < start) { //base case, if end is less than start
        return -1*(start+1); //otherwise if the number is not in the vector, return the "negative" index of the number (instead of 0 indexing, it indexes to -1. for example, the negative indeces of the vector are -1, -2, -3, -4, etc.)
    }
    else if(vect[midIndex] < desiredNum) { //if the vector at midIndex is less than desiredNum
        return binarySearch(vect, midIndex+1, end, desiredNum); //check the upper half of the vector from midIndex+1 (since we already "searched" the mid index) to the end index
    }
    else if(vect[midIndex] > desiredNum) { //otherwise if the vector at midIndex is greater than desired num, 
        return binarySearch(vect, start, midIndex-1, desiredNum); //check the lower half of the vector from start to midIndex-1 (since we already checked the mid index)
    }
    else if(vect[midIndex] == desiredNum) { //otherwise, if vector at midIndex is equal to the desired number
        return midIndex; //return the desired number
    }
    return 0;
}

//THIS IS IMPLEMENTED FROM LM7.2
//insertElement, which is a function that inserts a given value into a certain position of a vector
//inputs - two integers, pos is the index of where the value is to be placed (positive), value is the value to put into the vector. The last input is an vector of stuff called vect
//outputs - changes the values of the vector and inserts the chosen value into the chosen position
template <typename Type>
void insertElement(int pos, Type value, vector<Type> vect) {
    for(int i = vect.size(); i > pos; i--) { //iterates through the vector
        vect[i] = vect[i-1]; //sets the value of the vector at index i to the value of the vector at index i-1
    }
    vect[pos] = value; //sets the value of vector at index pos to value
}

//THIS IS IMPLEMENTED FROM LM7.2
//sortArray is a function that sorts a vect using a binary search to figure out where each element of type Type goes
//inputs - an array of stuff of type Type that is UNSORTED!!!!
//outputs - sorts the vector of stuff
template <typename Type>
void binarySort(vector<Type> vect) {
    int incrementor = 0; //an integer called incrementor which increments through the course of the function

    for(int i = 1; i < vect.size(); i++) { //iterates through first arr
        int index = binarySearch(vect, 0, incrementor, vect[i]); //creates an integer called index, which is the index where the value of arr[i] goes inside a subsection of the sorted array, which is from 0 to incrementor
        //cout << "Index is: " << index << endl; //bug testing
        if(index < 0) { //if index is less than zero
            index = -1*(index+1);//changes index to an actual index of the array
            insertElement(index, vect[i], vect); //inserts the value of arr[i] into the sorted array at index index
        }
        else { //if index is greater or equal to zero
            insertElement(index, vect[i], vect); //inserts the value of arr[i] into the sorted array at index index
        }

        incrementor++; //increments the incrementor
    }
}

//this function finds a boys name inside a string, assuming the input string is ordered like so: 
//      "x  boyName numOccurences   girlName numOccurences", with x being the line of the file and all spaces are tabs ('\t')
//inputs - a string ordered like the previous line states
//outputs - returns the boy's name of that line
string getBoyName(string str) {
    int first = str.find('\t', 0); //first is equal to the index of the first occurence of a tab character
    int second = str.find('\t', 2); //second is equal to the index of the second occurence of a tab character

    string name = str.substr(first+1, (second-first)); //sets name to be equal to a substring of string from the first occurence of a tab to the second occurence of a tab
    return name; //returns name
}


//this function finds a girl's name inside a string, assuming the input string is ordered like so: 
//      "x  boyName numOccurences   girlName numOccurences", with x being the line of the file and all spaces are tabs ('\t')
//inputs - a string ordered like the previous line states
//outputs - returns the girl's name on that line
string getGirlName(string str) {
    int first = str.find('\t', 0); //finds the first tab
    int second = str.find('\t', 2); //finds the second tab

    int i = 2; //int i, used as a starting index to look for a tab in third and fourth

    int third = str.find('\t', i); //third is equal to the first index of a tab starting at the ith character in the string (which is the same as second in this line)

    while(third <= second) { //while the third occurence of a tab occurs at the same or a lower index as the second tab
        i++; //increment i
        third = str.find('\t', i); //find the third occurence of a tab, starting the search from index i
    }

    int fourth = str.find('\t', third+1); //finds the fourth index of tab, assuming that the third was found 

    string name = str.substr(third+1, (fourth-third)); //sets the name string to be a substring of of str from the third occurrence of tab to the fourth occurence of tab
    return name; //returns name
}

//outputStuff outputs a vector of type Type to an outputFile
template <typename Type>
void outputStuff(vector<Type> vect, string path) {
    fstream outputFile;

    outputFile.open(path, ios::out);

    for(int i = 0; i < vect.size(); i++) {
        // cout << vect.at(i) << endl;
        outputFile << vect.at(i) << endl;
    }
    outputFile.close();
}

//sorts the contents of a babyData file
//inputs - takes in a string of the path to a babydata file
//outputs - should output the sorted names to their respective girlSorted and boySorted files
void sortStuff(string path) {
    vector<string> boys; //vector for boys names
    vector<string> girls; //vector for girl names

    fstream input; //input file from fstream
    // ifstream newInput;

    fstream output; //output file from fstream

    input.open(path, ios::in); //opens the input file as an input file stream

    if(input.fail()) { //if inputfile fails
        //say file failed and get new file input
        cout << "File open failed! Enter new path: " << endl; 
        string newPath = "";
        cin >> newPath;
        input.open(newPath, ios::in); //open the file again
    }

    string currLine; //currLine
    while(getline(input, currLine)) { //while there is still a line
        int i = 0; //incrementor for next while loop
        while(currLine[i] != '\0') { //
            boys.push_back(getBoyName(currLine));//pushes the boyName from the current line to the boys vector
            girls.push_back(getGirlName(currLine)); //pushes the girlName from the current line to the girls vector
        }
    }
    input.close(); //closes the input file

    binarySort(boys); //sorts the boys vector
    binarySort(girls); //sorts the girls vector

    outputStuff(boys, "x_boySorted"); //outputs the boys vector to x_boySorted
    outputStuff(girls, "x_girlSorted"); //outputs the girls vector to x_girlSorted

    
}




int main() {
    // string dataPath = getPath();

    // cout << "The path is: " << dataPath << endl;

    string path = "/Users/borjaaar017/Desktop/cpp/CS2/lm9/9.1/data/babyNames2013.dat";

    sortStuff(path);
}