//main.cpp
//CS172-1 CS2
//Aaron Borjas
//4/6/19
//This program implements the dynamic class and shows how it can be used

#include <iostream>
#include "../headers/album.h"
using namespace std;

int main() {
    Album GSP = Album("Glory Sound Prep", "Jon Bellion", "Pop", 2018); //creates new album with all this information

    GSP.print(); //prints the information about the album before adding tracks

    //adds some tracks to the glory sound prep album
    GSP.addTrack("JT", 4.28); 
    GSP.addTrack("Blu", 3.03);
    GSP.addTrack("Cautionary Tales", 3.47);

    GSP.print(); //prints GSP after adding tracks

    Album newGSP = Album(GSP); //creates a new album using the copy constructor 

    newGSP.print(); //prints the new GSP album which was made based off of the previous GSP album (with a copy constructor)

    //adds two new tracks to newGSP
    newGSP.addTrack("Stupid Deep", 2.58); 
    newGSP.addTrack("Let's Begin", 5.41);

    newGSP.print(); //prints the newGSP album, which has two new tracks added to it

    GSP.print(); //prints the original GSP to see if any of the values changed (they should not change)

    //Testing empty constructors
    Album emptyAl;
    emptyAl.print();








}