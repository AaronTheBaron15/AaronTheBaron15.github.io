//Invite class
//Aaron Borjas
//11/17/2019
//CS273-1
//Dr. Bell
//This file provides the basic requirements for any derived invite classes.
#include <iostream>
#ifndef INVITE_H
#define INVITE_H

class Invite {
    private:

    public:
        //virtual function for leaving the event. cannot be implemented here, but in derived classes
        //no inputs
        //outputs - leaves the event
        virtual void leave() = 0;
};

#endif