//Exam 1 practical portion, Transformer header file
//Aaron Borjas
//CS273-1
//Matt Bell
//this file defines the Transformer class and its member variables and functions

#include <iostream>
#include <string>
#include "../headers/Figurine.h"
using namespace std;

#ifndef TRANSFORMER_H
#define TRANSFORMER_H


//transformer class, which is a child class of the Figurine class
class Transformer : public Figurine {
    private:
        string team; //string team, the team the transformer is on (autobot or decepticon)
        bool isTransformed; //whether the not the transformer is transformed
    public:

        //default constructor for transformer
        //inputs - none
        //outputs - creates a transformer that has no team, is not transformed, is not humanoid, has no weapon, and has a sex of NONE
        Transformer() : Figurine(false, false, NONE) {
            team = "???"; //sets team to ???
            isTransformed = false; //is not transformed
        }

        //full constructor for transformer
        //inputs - a string t for the team of the transformer, and a bool for if the transformer has transformed or not
        //outputs - sets the team, if the transformer is transformed, not humanoid, no weapon, and no sex
        Transformer(string t, bool transform) : Figurine(false, false, NONE){
            team = t;
            isTransformed = transform;
        }

        //describe_me() describes the transformer (this function was inherited from the virtual function of Figurine)
        //inputs - none
        //outputs - returns a description of the transformer as a string
        string describe_me();

        //getTeam gets the team of the transformer
        //inputs - none
        //outputs - a string for the team of the transformer
        string getTeam();

        //transformed gets whether or not the transformer is transformed
        //inputs-  none
        //outputs - true or false depending on if the transformer is transformed or not
        bool transformed();
};

#endif