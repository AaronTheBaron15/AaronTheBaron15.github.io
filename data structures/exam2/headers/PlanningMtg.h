//PlanningMtg class
//Aaron Borjas
//11/17/2019
//CS273-1
//Dr. Bell
//This file implements the interface from Event.h

#include <iostream>
#include <list>
#include <iterator>
#include "Invite.h"
#include "PlanMtgInvite.h"
#include "Event.h"
#ifndef PLANNINGMTG_H
#define PLANNINGMTG_H

class PlanningMtg : public Event {
    private:
        std::list<std::string> room;
    public:
        PlanningMtg() {

        }

        Invite* add(std::string n) {
            room.push_back(n);

            std::list<std::string>::iterator temp = room.end();
            Event* party = this;
            Invite* invite = new PlanMtgInvite(party, temp);
            return invite;
        }

        void list() {
            std::list<std::string>::iterator temp = room.begin();
            while(temp != room.end()) {
                std::cout << *temp << std::endl;
                ++temp;
            }
        }

        std::list<std::string>::iterator getIt(std::string name) {
            std::list<std::string>::iterator temp = room.begin();
            while(*temp != name) {
                ++temp;
            }

            return temp;
        }

        void remove(std::list<std::string>::iterator &me) {

            std::list<std::string>::iterator temp = room.begin();
            while(temp != me) {
                temp = ++temp;
            }

            std::string tempString= *temp;
            //room.remove(tempString);
            room.erase(temp);
        }

        
};

#endif