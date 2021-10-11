//Exam 1 practical portion, Weapon header file
//Aaron Borjas
//CS273-1
//Matt Bell
//this file defines the class Weapon and its member variables and functions

#include <iostream>
#include <string>
using namespace std;

#ifndef WEAPON_H
#define WEAPON_H

//enumerated type for the rarity of the weapon
enum rarity {COMMON, UNCOMMON, RARE, EPIC, LEGENDARY};

//weapon class, which is included as a member variable in the Lego class
class Weapon { 
    private:
        string name; //name of the weapon
        string description; //description of the weapon
        rarity rare; //enumerated type of rarity called rare
    public: 
        //default constructor for weapon, sets the rarity to common
        Weapon() : rare(COMMON) {

        }

        //rarity constructor for weapon
        //inputs - takes in an enumerated type r
        //outputs - sets rare to the input rarity
        Weapon(rarity r) : rare(r) {

        }

        //full constructor for weapon
        //inputs - takes in two strings, one for name and one for description, and an enumerated type for rarity
        //outputs - sets the name, description, and rarity of the weapon 
        Weapon(string n, string d, rarity r) : rare(r) {
            name = n; //sets the name of the weapon to n
            description = d; //sets the description of the weapon to d
        }

        //getRarity gets the rarity of the weapon
        //inputs - none
        //outputs - returns the rarity of the weapon as a string
        string getRarity();

        //getName gets the name of the weapon
        //inputs - none
        //outputs - returns the name of the weapon as a string
        string getName();

        //getDescription gets the description of the weapon
        //inputs - none
        //outputs - returns the description of the weapon as a string
        string getDescription();

};

#endif