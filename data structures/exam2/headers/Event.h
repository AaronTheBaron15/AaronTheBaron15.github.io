//Event abstract class
//Aaron Borjas
//11/17/2019
//CS273-1
//Dr. Bell
//This file defines the basic functions that should be used in any derived event class

#include <iostream>
#include <list>
#include "Invite.h"

#ifndef Event_H
#define Event_H

//abstract base event class
//provides the basic requirements for any derived event class
class Event {
    private:

    public:
        //default constructor
        Event() {

        }

        //VIRTUAL METHOD - CANNOT BE IMPLEMENTED HERE
        //add is a function that adds a new guest to the list of people in the room
        //inputs - a string for the name of the new guest
        //outputs - returns the invite for the new guest
        virtual Invite * add(std::string name) = 0;

        //VIRTUAL METHOD - CANNOT BE IMPLEMENTED HERE
        //list is a function which lists all the members who are in the room that the event is occurring in
        //inputs - none
        //outputs - prints out the people in the room of the event
        virtual void list() = 0;

        //VIRTUAL METHOD - CANNOT BE IMPLEMENTED HERE
        //remove is a function that removes a specified person from the list of people in the room of the event
        //inputs - a reference to an iterator of a string list, which indicates the position of the person to remove
        //outputs - removes an element from the list
        virtual void remove(std::list<std::string>::iterator &me) = 0;

        virtual std::list<std::string>::iterator getIt(std::string name) = 0;
};

#endif