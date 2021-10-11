#include "location.h"
using namespace std;

//constructor for the Location class
//sets the default status to UNGUESSED and by default sets shipPresent to false;
//No inputs
//creates new Location object
Location::Location() {
    status = UNGUESSED; //sets status to UNGUESSED
    shipPresent = false; //sets shipPresent to false
}

//method to check if a location is hit
//No inputs
//outputs true or false depending on if the location is hit and if the location has a ship
bool Location::checkHit() {
    if((status == HIT) && (shipPresent)) { //if the location is hit and a ship is present
        return true; //return true
    }

    return false;//return false
}

//method to check if the there is a miss at a location
//no inputs
//outputs true or false depending on if a location is hit and if the location has a ship
bool Location::checkMiss() {  
    if((status == MISSED) && (!shipPresent)) { //if the status is MISSED and there is not a ship at the location
        return true; //return true
    }
    return false; //return false
}

//method to check if a location is unguessed
//no inputs
//returns true or false if a location is unguessed
bool Location::isUnguessed() {
    if(status == UNGUESSED) { //if status is UNGUESSED
        return true; //return true
    }
    return false; //return false
}

//method to change the status of a location to HIT
//no inputs
//no outputs (changes the status of the location though)
void Location::markHit() {
    setStatus(HIT); //sets the status to HIT
}

//method to change the status of a location to MISSED
//no inputs
//no outputs (changes the status of the location though)
void Location::markMiss() {
    setStatus(MISSED); //sets the status to MISSED
}

//method that checks if there is a ship at a location
//no inputs
//returns true or false depending on if there is a ship at the location
bool Location::hasShip() {
    if(shipPresent) { //if there is a ship present
        return true; //return true
    }
    return false; //return false
}

//method that sets the shipPresent status at the location to true or false
//Inputs - a true or false value representing if a ship is present at arbitrary location
//outputs - changes the value of the location's shipPresent to true or false
void Location::setShip(bool shipHere) {
    shipPresent = shipHere; //shipPresent is equal to shipHere, which is true or false
}

//method that sets the status (unguessed (0), hit (1), or missed (2)) of a location
//inputs - the new status of the location, which is either 0, 1, or 2
//outputs - changes the status of the location to newStatus
void Location::setStatus(int newStatus) {
    status = newStatus;
}

//gets the status (unguessed (0), hit (1), or missed (2)) of a location
//inputs - none
//outputs - gives you the status, which should be 0, 1 or 2
int Location::getStatus() {
    return status;
}