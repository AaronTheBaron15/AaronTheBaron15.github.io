//Exam 1 practical portion, Figurine header file
//Aaron Borjas
//CS273-1
//Matt Bell
//this file defines the class abstract base class Figurine and its member variables and functions

#include <iostream> 
#include <string>
using namespace std;

#ifndef FIGURINE_H
#define FIGURINE_H

enum Sex {MALE, FEMALE, NONE, OTHER}; //enumerated type for sex of the figurine. Male, female, or none

class Figurine {
    private:
        bool isHumanoid; //boolean for if the figurine is humanoid 
        bool hasWeapon;//boolean for if the figurine has a weapon
        Sex sex;  //implementing the enumerated type

    public:
        //this is a default constructor, makes a figurine that is not humanoid and does not have a weapon
        //inputs - none
        //outputs - creates a figurine that is not a humanoid and does not have a weapon
        Figurine() : isHumanoid(false), hasWeapon(false) { 
            
        }

        //one parameter constructor for Figurine.
        //inputs - a boolean value for if the figurine is a humanoid
        //outputs - creates a figurine that is or isn't humanoid, is a male, and does not have a weapon
        Figurine(bool human) : isHumanoid(human) {
            sex = MALE; //sets sex to male
            hasWeapon = false; //sets hasWeapon to false
        }

        //two parameter constructor for Figurine.
        //inputs - boolean value for if the figurine is humanoid, and another boolean for if the figurine has a weapon
        //outputs - creates a figurine that is or isnt humanoid, does or doesn't have a weapon, and is male
        Figurine(bool human, bool weapon) : isHumanoid(human), hasWeapon(weapon) {
            sex = MALE; //sets sex to male
        }

        //full constructor for Figurine
        //inputs - boolean values for if the figurine is or isn't humanoid and if it has a weapon, and an enumerated type Sex 
        //outputs - creates a figurine that is totally customizable (at least if they are humanoid, have a weapon, and what sex they are)
        Figurine(bool human, bool weapon, Sex s) : isHumanoid(human), hasWeapon(weapon), sex(s) {

        }

        //this function says if the figurine is a humanoid
        //inputs - none
        //outputs - returns if the figurine is humanoid or not
        bool humanoid();

        //this function says if the figurine has a weapon 
        //inputs - none
        //outputs - returns if the figurine has a weapon
        bool weapon();

        //this function gets the gender of the figurine
        //inputs - none
        //outputs - returns the gender of the figurine as a string
        string getGender();

        //pure virtual method to describe the figurine
        //cannot be called on a figurine object, but on any children objects
        //inputs - none
        //outputs - describes the figurine (not for figurine objects but for children objects!!!)
        virtual string describe_me() = 0;
};


#endif