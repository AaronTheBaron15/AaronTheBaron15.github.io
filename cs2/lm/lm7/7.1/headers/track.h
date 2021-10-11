//track.h
//CS172-1 CS2
//Aaron Borjas
//4/7/19
//This file holds the track class, which is a basic class that holds information about a track that is contained on an album
#ifndef TRACK_H
#define TRACK_H

#include <iostream>
using namespace std;

class Track{
    private:
        string title;
        float duration;
    public:
        //empty constructor for the track class
        //does not change anything for the class
        Track() {}
        //constructor for the track class
        //takes in a string and float and assigns the class's member variables to them
        Track(string name, float length) {
            title = name;
            duration = length;
        }

        //getDuration is a function that gets the duration of a track
        //no inputs
        //returns the value of duration, which is how long the track is
        float getDuration() {
            return duration;
        }

        //getName is a function that gets the name of a track
        //no inputs 
        //returns the value of title, which is the name of the track
        string getName() {
            return title;
        }
};

#endif