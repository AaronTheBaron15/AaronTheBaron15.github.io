#ifndef LOCATION_H
#define LOCATION_H

class Location{
    public:
        const int UNGUESSED = 0; //UNGUESSED location is 0
        const int HIT = 1;//HIT location is 1
        const int MISSED = 2; //MISSED location is 2;

        int status; //status (UNGUESSED, HIT, or MISSED)
        bool shipPresent; //true or false if there is a ship present or not

        //constructor for the Location class
        //sets the default status to UNGUESSED and by default sets shipPresent to false;
        //No inputs
        //creates new Location object
        Location();

        //method to check if a location is hit
        //No inputs
        //outputs true or false depending on if the location is hit and if the location has a ship
        bool checkHit();

        //method to check if the there is a miss at a location
        //no inputs
        //outputs true or false depending on if a location is hit and if the location has a ship
        bool checkMiss();

        //method to check if a location is unguessed
        //no inputs
        //returns true or false if a location is unguessed
        bool isUnguessed();

        //method to change the status of a location to HIT
        //no inputs
        //no outputs (changes the status of the location though)
        void markHit();

        //method to change the status of a location to MISSED
        //no inputs
        //no outputs (changes the status of the location though)
        void markMiss();

        //method that checks if there is a ship at a location
        //no inputs
        //returns true or false depending on if there is a ship at the location
        bool hasShip();

        //method that sets the shipPresent status at the location to true or false
        //Inputs - a true or false value representing if a ship is present at arbitrary location
        //outputs - changes the value of the location's shipPresent to true or false
        void setShip(bool shipHere);

        //method that sets the status (unguessed (0), hit (1), or missed (2)) of a location
        //inputs - the new status of the location, which is either 0, 1, or 2
        //outputs - changes the status of the location to newStatus
        void setStatus(int newStatus);

        //gets the status (unguessed (0), hit (1), or missed (2)) of a location
        //inputs - none
        //outputs - gives you the status, which should be 0, 1 or 2
        int getStatus();

};

#endif