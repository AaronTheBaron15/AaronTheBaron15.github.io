#include <iostream>
#include <string>
using namespace std;

#ifndef ACTOR_H
#define ACTOR_H

class Actor {
    private:
        string name;
        int age;
        string characterName;
        bool awardWinning;
    public:
        //empty constructor for actor
        Actor();

        //class constructor, 
        //creates an actor with a name, age, character, and if they have won an award
        Actor(string actorName, int actorAge, string actorCharacter, bool hasAward);

        //function getName, gets the name of the actor
        //no inputs
        //prints the name of the actor to the screen
        string getName();

        //function getAge, gets the age of the actor
        //no inputs
        //prints the age of the actor to the screen
        int getAge();

        //function getCharacter, gets the name of the actor
        //no inputs
        //prints the character the actor played to the screen
        string getCharacter();

        //function getAward, gets whether or not the actor has an award
        //no inputs
        //prints whether or not the actor has an award
        bool getAward();

        //function print, prints all the information about the actor
        //no inputs
        //prints all the information about the actor to the screen.
        void print();
};

#endif