//This is the cpp file for the crawlspace class
//Aaron Borjas
//CS273-1
//10/6/2019
//This file provides code for the definitions of the crawlspace class

#include "../headers/Crawlspace.h"

void Crawlspace::addLocation(Location& l) {
    maze.push_back(l);
    size++;
}

void Crawlspace::updateLoc(Exit& e, int loc) {
    maze[loc].dig(e);
}

void Crawlspace::updateLoc(Treasure& t, int loc) {
    maze[loc].drop(t);
}