//Exam 1 practical portion, Weapon cpp file
//Aaron Borjas
//CS273-1
//Matt Bell
//this file implements the functions defined in Weapon.h

#include "../headers/Weapon.h"

string Weapon::getRarity() {
    string r; //rarity of the weapon as a string
    switch(rare) { //switch statement that takes in the rarity member variable
        case(COMMON) : //if the rarity is COMMON
            r = "common"; //set r to "common"
            break; //end
        case(UNCOMMON) : //if the rarity is UNCOMMON
            r = "uncommon"; //set r to "uncommon"
            break; //end
        case(RARE) : //if the rarity is RARE
            r = "rare"; //set r to "rare"
            break; //end
        case(EPIC) : //if the rarity is EPIC
            r = "epic"; //set r to "epic"
            break; //end
        case(LEGENDARY) : //if the rarity is LEGENDARY
            r = "legendary"; //set r to "legendary"
            break; //end
        default: //if none of the other cases are true
            r = "ERROR"; //set r to "ERROR"
    }

    return r; //return r
}

string Weapon::getName() {
    return name; //return the name of the weapon
}

string Weapon::getDescription() {
    return description; //return the description of the weapon
}