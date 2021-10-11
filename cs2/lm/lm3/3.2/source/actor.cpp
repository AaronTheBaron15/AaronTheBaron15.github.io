#include "../headers/actor.h"
using namespace std;

Actor::Actor() {
    
}

Actor::Actor(string actorName, int actorAge, string actorCharacter, bool hasAward) {
    name = actorName;
    age = actorAge;
    characterName = actorCharacter;
    awardWinning = hasAward;
}

string Actor::getName() {
    return name;
}

int Actor::getAge() {
    return age;
}

string Actor::getCharacter() {
    return characterName;
}

bool Actor::getAward() {
    return awardWinning;
}

void Actor::print() {
    cout << "The actor's name is: " << name << endl;
    cout << name << " is " << age << " years old." << endl;
    cout << name << " plays " << characterName << " in this movie." << endl;
    if(awardWinning) {
        cout << name << " is an award-winning actor/actress." << endl;
    }
    else {
        cout << name << " is not an award-winning actor/actress." << endl;

    }
}