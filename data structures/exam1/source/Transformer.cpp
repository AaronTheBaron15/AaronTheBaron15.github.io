//Exam 1 practical portion, Transformer cpp file
//Aaron Borjas
//CS273-1
//Matt Bell
//this file implements the functions defined in Transformer.h

#include "../headers/Transformer.h"

string Transformer::describe_me() {

    //desc is a string that describes the transformer
    string desc = "The mighty "; 
    desc+= team; //adds the "team" of the transformer to the string
    desc+= " roars into battle!";

    return desc; //returns the description of the transformer
}

string Transformer::getTeam() {
    return team; //returns the team of the transformer
}

bool Transformer::transformed() {
    return isTransformed; //returns if the transformer is transformed or not
}