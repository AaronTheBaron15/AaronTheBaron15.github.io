//lm1_2.cpp
//CS 172-1, CS2
//Aaron Borjas
//2/11/18
//creates a class called Album which represents a music album and implements methods to get 
//information from and manipulate the album

#include <iostream>
#include <string>
#include <array>
#include <iomanip>
using namespace std;

const int totalTracks = 10;


class Album {
    private: 
        string albumName;
        string artist;
        string genre;
        int releaseYear;
        string publisher;
        string trackTitles[totalTracks];
        float trackLengths[totalTracks];

    public:
        //constructor that takes a name, year, and publisher and assigns those values to the album object
        Album(string name, int year, string publish) {
            albumName = name;
            releaseYear = year;
            publisher = publish;

            for(int i = 0; i < totalTracks; i++) { //i starts at 0 and goes up by one until it is equal to totalTracks
                trackLengths[i] = -1; //set trackLengths at index i to -1
            }
        }

        //function getName, prints the name of the album
        //no inputs
        //prints the album name 
        void getName() {
            cout << "The album name is: " << albumName << endl;
        }

        //function getArtist, prints the name of the artist
        //no inputs
        //prints the artist name
        void getArtist() {
            cout << "The artist is: " << artist << endl;
        }

        //function setArtist, sets the artist of the album
        //inputs - a string which is the name of the album's artist
        //no outputs
        void setArtist(string artistName) {
            artist = artistName;
        }

        //function getGenre, prints the genre of the album
        //no inputs
        //prints the name of the genre
        void getGenre() {
            cout << "The genre is: " << genre << endl;
        }

        //function setGenre, sets the genre of the album
        //inputs - a string which is the genre of the album
        //no outputs
        void setGenre(string newGenre) {
            genre = newGenre;
        }

        //function getRelease, prints the release date of the album
        //no inputs
        //prints the year of the albums release
        void getRelease() {
            cout << "The release year is: " << releaseYear << endl;
        }

        //function getPublisher, prints the name of the publisher
        //no inputs
        //prints the name of the publisher
        void getPublisher() {
            cout << "The publisher is: " << publisher << endl;
        }

        

        //function addTrack, adds a new song, including duration of the song, to the album
        //inputs - string trackName, the name of the song, and float duration, the duration of the song in minutes (ex: 3.33 is 3 minutes and 33 seconds)
        //outputs - none, but adds a song and duration to the album
        void addTrack(string trackName, float duration) {
            for(int i = 0; i < totalTracks; i++) { //i starts at 0 and goes up by one until it reaches totalTracks
                if(trackLengths[i] == -1) { //if trackLengths at index i is -1
                    trackTitles[i] = trackName; //set index i of trackTitles to trackName
                    trackLengths[i] = duration; //set index i of trackLengths is duration
                    i += (totalTracks+1); //make i greater than totalTracks to exit the loop
                }
            }
        }

        //function getTotalTracks, gets the number of tracks in the album based on how many items are input in the trackLengths array
        //inputs - none
        //outputs - returns the number of tracks in the album
        int getTotalTracks() {
            int tracks = 0; //creates a new integer called tracks, assigns 0 to it
            for(int i = 0; i < totalTracks; i++){ //i starts at 0 and increments up by one until it is equal to the totalTracks variable
                if(!(trackLengths[i] == -1)) { //if trackLengths[i] is not -1 (they are set to -1 by default)
                    tracks++; //add one to tracks
                }
            }

            return tracks; //return tracks
        }

        //function getTrack, prints the information about a track
        //inputs - a number that represents the track, must be from 0 to totalTracks
        //outputs - prints the information on track trackNumber
        void getTrack(int trackNumber) {
            cout << "Track name: " << trackTitles[trackNumber-1] << endl <<  "    "; //prints the name of the track 
            cout << "Track duration (in minutes) is " << trackLengths[trackNumber-1] << " or " << trackLengths[trackNumber -1]*60 << " seconds\n\n"; //prints the length of the track in seconds
        }

        //function totalDuration, gets the total duration of the album
        //inputs - none
        //outputs - returns the total length of the album in seconds
        float totalDuration() { 
            int totalLength = 0; //total length starts at 0
            for(int i = 0; i < totalTracks; i++) { //i starts at 0 and goes up by one until it reaches the max amount of tracks
                totalLength += (trackLengths[i]*60); //totalLength adds the trackLength at index i (in seconds) to its previous value
            }
            return totalLength; //returns the total length of the tracks
        }

        //function getInfo, prints all the information about the album
        //no inputs
        //outputs all the information about the album to the console.
        void getInfo() {
            getName(); //prints the name of the album
            getArtist(); //prints the name of the artist of the album
            getGenre(); //prints the genre of the album
            getRelease(); //prints the release year of the album
            getPublisher(); //prints the name of the publisher of the album

            for(int i = 1; i < totalTracks+1; i++) { //i starts at 0 and goes up by one until it is equal to totalTracks
                getTrack(i); //calls the function getTrack with the parameter being i
            }
        }
};

int main() {
    Album album1 = Album("Glory Sound Prep", 2018, "Capitol Records"); //makes new album named glory sound prep, released 2018 and produced by capitol records


    album1.setGenre("Pop"); //sets genre to pop
    album1.setArtist("Jon Bellion");//sets artist to jon bellion

    album1.addTrack("Stupid Deep", 2.48); //track 1
    album1.addTrack("Cautionary Tales", 3.47); //track 2
    album1.addTrack("Conversations with my Wife", 3.26); //track 3
    album1.addTrack("JT", 4.28); //track 4
    album1.addTrack("Let's Begin", 5.40); //track 5
    album1.addTrack("The Internet", 3.09); //track 6
    album1.addTrack("Blu", 3.03); //track 7
    album1.addTrack("Adult Swim", 5.13); //track 8
    album1.addTrack("Couples Retreat", 3.28); //track 9 
    album1.addTrack("Mah's Joint", 8.01); //track 10

    album1.getTrack(10); //gets the 10th track
    cout << endl;

    cout << "The album's total duration is " << album1.totalDuration()/60 << " minutes" << endl; //prints the total duration of the album

    cout << endl;

    album1.getInfo(); //prints all the information related to album1

    Album album2 = Album("Evolve", 2017, "Alex da Kid"); //makes a new album named Evolve that was released in 2017 and produced by Alex da Kid

    album2.setGenre("Pop rock"); //sets genre to pop rock
    album2.setArtist("Imagine Dragons"); //sets artist to Imagine Dragons

    album2.addTrack("I Don't Know Why", 3.10); //track 1
    album2.addTrack("Whatever it Takes", 3.21); //track 2
    album2.addTrack("Believer", 3.24); //track 3
    album2.addTrack("Walking the Wire", 3.52); //track 4
    album2.addTrack("Rise Up", 3.51); //track 5
    album2.addTrack("I'll Make It Up to You", 4.22); //track 6
    album2.addTrack("Yesterday", 3.25); //track 7
    album2.addTrack("Mouth of the River", 3.41); //track 8
    album2.addTrack("Thunder", 3.07); //track 9
    album2.addTrack("Start Over", 3.06); //track 10

    album2.getTrack(10); //prints information about track 10
    cout << endl;

    cout << "The album's total duration is " << album2.totalDuration()/60 << " minutes" << endl << endl; //gets total duration of the album

    album2.getInfo(); //prints all the information about the album
 
}