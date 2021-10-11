//Exam 1 practical portion, Figurine cpp file
//Aaron Borjas
//CS273-1
//Matt Bell
//this file implements the functions defined in Figurine.h

#include "../headers/Figurine.h"

bool Figurine::humanoid() {
    return isHumanoid; //returns if the figurine is humanoid
}

bool Figurine::weapon() {
    return hasWeapon; //returns if the figurine has a weapon
}

string Figurine::getGender() {
    switch(sex) { //switch statement for the sex of the figurine
        case(MALE) : //if the figurine is male
            return "male"; //return "male"
        case(FEMALE) : //if the figurine is female
            return "female"; //return "female"
        case(NONE) : //if the figurine is no gender
            return "none"; //return "none"
        case(OTHER) : //if the figurine has another gender that isn't mentioned
            return "other"; //return "other"
        default : //if none of the cases are fulfilled
            return "ERROR";  //return "ERROR"
    }
}