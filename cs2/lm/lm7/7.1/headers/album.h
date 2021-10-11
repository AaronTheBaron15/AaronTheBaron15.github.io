//album.h
//CS172-1 CS2
//Aaron Borjas
//4/7/19
//This file holds the album class, which uses dynamic memory with a copy constructor and a destructor for an array of tracks
#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include "track.h"
using namespace std;

//This album class references some of the member variables and class functions from the album class in lm1.2
class Album{
    private: 
        string albumName;
        string artist;
        string genre;
        int releaseYear;
        int numTracks;
        Track* tracks; //creates a new track pointer called tracks (holds the different tracks of the album)
    public: 
        //empty constructor for album
        //initializes every member variable as empty, zero, or NULL
        Album() {
            albumName = "";
            artist = "";
            genre = "";
            releaseYear = 0;
            numTracks = 0;
            tracks = NULL;
        }

        //class constructor for album, which takes in a few inputs to change the member variables
        //inputs - strings for name, author, and agenre, and an integer for release year and an integer for trackNum, which is the number of tracks
        //no outputs
        Album(string name, string author, string aGenre, int release) {
            albumName = name;
            artist = author;
            genre = aGenre;
            releaseYear = release;
            numTracks = 0;
            tracks = NULL;
        }

        //copy constructor (referenced from sandwich.h from classdata folder for lm7.1)
        //copies another instance of album and sets it to the new instance of album
        //takes in another album that has already been defined
        //creates a brand new album class based on a previous album
        Album(const Album & other) {
            //Shallow copies, from other to this
            albumName = other.albumName;
            artist = other.artist;
            genre = other.genre;
            numTracks = other.numTracks;
            releaseYear = other.releaseYear;

            //Allocate a new place to put toppings in this
            tracks = new Track[numTracks];

            //Copy values from other's topping list into this' topping list
            //This is where the deep copy is happening
            for(int i = 0; i < numTracks; i++){
                tracks[i] = other.tracks[i];
            }

            //no deletes until destructor
        }

        //adds a new track into the album
        //inputs - the name of the track you are adding as a string, and the duration of the track as a float
        //outputs - adds a new track to the tracks of the album
        void addTrack(string trackName, float duration) {
            Track * newTracks = new Track[numTracks+1]; //creates a new dynamic array of tracks, with numTracks+1 tracks in it

            for(int i = 0; i < numTracks; i++) { //iterates through the newTracks array
                newTracks[i] = tracks[i]; //sets the value of newTracks at index i to the value of tracks at index i
            }

            delete [] tracks; //delete the old tracks array because it is not needed anymore

            tracks = newTracks; //set the tracks pointer to the memory location of the newTracks array

            tracks[numTracks] = Track(trackName, duration); //set tracks at index numTracks to be a new track using the input parameters on this function.

            numTracks++; //increments numTracks

        }

        //getName is a function that returns the name of the album
        //no inputs
        //returns the name of the album
        string getName() {
            return albumName;
        }

        //getArtist is a function that returns the name of the artist of the album
        //no inputs
        //returns the name of the artist of the album
        string getArtist() {
            return artist;
        }

        //getGenre is a function that returns the genre of the album
        //no inputs
        //returns the genre of the album
        string getGenre() {
            return genre;
        }

        //getNumTracks is a function that returns the number of tracks in the album
        //no inputs
        //returns the number of tracks in the album
        int getNumTracks() {
            return numTracks;
        }

        //getRelease is a function that returns the release year of the album
        //no inputs
        //returns the release year of the album
        int getRelease() {
            return releaseYear;
        }

        //print is a function that prints all the information about the album
        //inputs - none
        //outputs - prints the information about the function to the screen
        void print() {
            if(albumName != "") {
                cout << "The name of the album is: " << albumName << endl; //prints name of album
                cout << albumName << "'s artist is: " << artist << endl; //prints artist's name
                cout << albumName << "'s genre is: " << genre << endl; //prints albums genre
                cout << albumName << "'s release year was: " << releaseYear << endl; //prints the albums release year
                cout << albumName << " has " << numTracks << " tracks" << endl; //prints the number of tracks inside album

                if(numTracks < 1) {
                    cout << "There are no tracks added to the album yet :(" << endl;
                }
                else {
                    cout << "The tracks that are included with album are: " << endl;
                    for(int i = 0; i < numTracks; i++) {
                        cout << "Track " << i+1 << "'s name is: " << tracks[i].getName() << " and has a length of: " << tracks[i].getDuration() << " minutes." << endl;
                    }
                }
                cout << endl << endl;
            }
            else {
                cout << "The album does not have a name, which means that it also does not have any other facts about it :(" << endl << endl;
            }
        }
        
        //class deconstructor for Album
        //deletes all the dynamic memory used in the class, which is just the tracks dynamic array in this case
        ~Album() {
            cout << "Deleting the album!" << endl;
            delete [] tracks; //deletes the tracks array pointer for the class instance
        }


};

#endif