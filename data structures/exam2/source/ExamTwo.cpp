//ExamTwo practical portion
//Aaron Borjas
//11/17/2019
//CS273-1 
//Dr. Bell
//implementing the design implemented from the documentation for exam2
#include <iostream>
#include "../headers/Event.h"
#include "../headers/Invite.h"
#include "../headers/PlanningMtg.h"
#include "../headers/PlanMtgInvite.h"

int main() {
    Event* danceParty = new PlanningMtg();

    //std::cout << "HI1" << std::endl;
    danceParty->add("Jennifer Lopez");
    danceParty->add("Pitbull");
    //std::cout << "HI2" << std::endl;
    danceParty->add("Drake");
    danceParty->add("Jon Bellion");

    danceParty->list();
    std::cout << std::endl;

    std::list<std::string>::iterator temp = danceParty->getIt("Drake");
    danceParty->remove(temp);

    danceParty->list();
    std::cout << std::endl;
}