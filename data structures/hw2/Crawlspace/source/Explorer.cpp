//This is the cpp file for the explorer class
//Aaron Borjas
//CS273-1
//10/6/2019
//This file provides code for the definitions of the explorer class

#include "../headers/Explorer.h"


Explorer::Explorer(Location& l) {
    currLocation = l;
}

void Explorer::getInventory() {
    for(int i = 0; i < inventory.size(); i++) {
        inventory.at(i).describeme();
    }
}

Location Explorer::getLoc() {
    return currLocation;
}

void Explorer::examine(string type) {
    if(type == "location") {
        currLocation.describe();
    }
    else {
        inventory[inventory.size()].describeme();
    }
}

void Explorer::take(Treasure& t) {
    inventory.push_back(t);
}

void Explorer::move(Location& l) {
    currLocation = l;
}