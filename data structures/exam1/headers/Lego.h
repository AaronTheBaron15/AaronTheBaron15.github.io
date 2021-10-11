//Exam 1 practical portion, Lego header file
//Aaron Borjas
//CS273-1
//Matt Bell
//this file defines the Lego class and its member variables and functions

#include <iostream>
#include <string>
#include "../headers/Weapon.h"
#include "../headers/Figurine.h"
using namespace std;

#ifndef LEGO_H
#define LEGO_H

//Lego, which is a child class of Figurine (inherits from Figurine)
class Lego : public Figurine{
    private:
        string set; //string for the set the lego came from
        Weapon weap; //A weapon that the lego figure has
    public:

        //default constructor for lego
        //inputs - none
        //outputs - creates a lego figure from an unknown set
        Lego() {
            set = "???"; //sets the set to ??? because there is no set
        }

        //full constructor for Lego
        //inputs - bool human which is if the figure is humanoid, Sex s for the sex of the figure, bool weapon for if the figure has a weapon,
        //         weapon w for the weapon the figure is holding, and string legoSet for the set the figure is from
        Lego(bool human, Sex s, bool weapon, Weapon w, string legoSet) : Figurine(human, weapon, s){
            set = legoSet; //set the set to be the legoSet
            weap = w; //set weapon to w
        }

        //getSet is a function that gets the set of the lego figure
        //inputs - none
        //outputs - returns the set the lego figure is from
        string getSet();

        //describe_me was a virtual function from Figurine, which describes the lego figurine
        //inputs - none
        //outputs - returns a description of the lego figure
        string describe_me();
        
};

#endif
