//main.cpp
//CS172-1 CS2
//Aaron Borjas
//3/9/19
//towers of hanoi

#include <iostream> 
using namespace std;

//TH IS A RECURSIVE FUNCTION
//TH is an abbreviation for Towers of Hanoi, which is what this function is. Generally, there are three towers. ToH is a recursive problem where you must move all the rings (which all have different sizes) from one tower to another
//  The catch to this though, is that the larger rings cannot be put on top of smaller rings. 
//Inputs - takes in a disk, which is a positive integer greater than 0, and three characters: the source tower, the destination tower, and the auxilary tower
//outputs - prints out where each disk has to move so that the initial disk can move the the desired tower
void TH(int disk, char source, char dest, char aux) {
    if(disk == 1) { //base case, if the disk is the first disk
        cout << "Move disk " << disk << " from tower " << source << " to tower " << dest << endl; //moves the disk from tower source to tower destination
    }
    else { //if the disk is not the first disk
        TH(disk-1, source, aux, dest); //recursive call to TH being called on disk-1, moving from source to auxilary tower, with the destination tower being the auxilary tower in this call
        cout << "Move disk " << disk << " from tower " << source << " to tower " << dest << endl; //moves the disk from tower source to tower destination
        TH(disk-1, aux, dest, source); //recursive call to TH, being called on disk-1, moving the disk from auxilary to destination, with source being the auxilary tower
    }
}

int main() {
    int n = 0; //creates a new integer called n and sets it to zero
    //says what to input 
    cout << "We are trying to figure out the Towers of Hanoi recursive problem! \n\nEnter a number for the number of disks you want to use: ";
    cin >> n; //gets user input for n

    cout << "Solving Towers of Hanoi with " << n << " disks: " << endl << endl; //says what is going to print
    TH(n, 'A', 'C', 'B'); //solves towers of hanoi for n disks with column A as source, C as destination, and B as auxilary
}