//PlanningMtg class
//Aaron Borjas
//11/17/2019
//CS273-1
//Dr. Bell
//This file implements the interface from Invite.h

#include <iostream>
#include <list>
#include "Invite.h"
#include "Event.h"
#ifndef PLANMTGINVITE_H
#define PLANMTGINVITE_H

class PlanMtgInvite : public Invite {
    private:
        Event* thisParty;
        std::list<std::string>::iterator me;
    public:
    //constructor for PlanMtgInvite
        //input - An event pointer called party
        //output - creates a new PlanMtgInvite with a set event
        PlanMtgInvite(Event* party, std::list<std::string>::iterator &m) {
            thisParty = party;
            me = m;
        }

        //set party changes the event that an invite is for
        //inputs - a event pointer called party, which is the event to change to
        //output - changes the event that the invite is for
        void setParty(Event* party) {
            thisParty = party; //changes the event
        }

        //setSpot sets the "spot" in the list for the invitee
        //inputs - a reference to an iterator of a list of strings for a certain spot in the list
        //outputs - sets the "spot" of the invitee.
        void setSpot(std::list<std::string>::iterator &spot) {
            me = spot;
        }

        //function for leaving the event. cannot be implemented here, but in derived classes
        //no inputs
        //outputs - leaves the event
        void leave() {
            
            thisParty->remove(me); //removes the invitee from the party
        }    
};

#endif