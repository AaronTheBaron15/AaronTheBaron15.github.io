//Exam 1 practical portion, Lego cpp file
//Aaron Borjas
//CS273-1
//Matt Bell
//this file implements the functions defined in Lego.h
#include "../headers/Lego.h"

string Lego::getSet() {
    return set; //returns the set the figure is from
}

string Lego::describe_me() {

    //describe is a string that describes the lego character and their weapon
    string describe =  "This lego figurine has a weapon with the name of ";
    describe+= weap.getName(); //gets the name of the weapon
    describe+= ". The weapon has a rarity of ";
    describe+= weap.getRarity(); //gets the rarity of the weapon
    describe+= " and is described like so: \"";
    describe += weap.getDescription(); //gets the description of the weapon
    describe+= ".\"\n";
    describe+= "This figurine is from the set \"";
    describe+= set; //gets the lego set the lego figurine is from
    describe+= "\"\n";

    return describe; //returns the description of the lego character
}