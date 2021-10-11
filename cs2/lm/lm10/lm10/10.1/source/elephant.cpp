#include "../headers/elephant.h"

Elephant::Elephant() : Animal() {
    trunkLength = 6;
}

Elephant::Elephant(string name) : Animal(name) {
    trunkLength = 6;
}

Elephant::Elephant(string name, int years) : Animal(name, years) {
    trunkLength = 6;
}

Elephant::Elephant(string name, int years, float trunk) : Animal(name, years) {
    trunkLength = trunk;
}

void Elephant::makeNoise() {
    cout << "" << endl;
}

void Elephant::grabStuff(string stuff) {
    cout << "The elephant grabs " << stuff << endl;
    item = stuff; //holds onto the item 
}

void Elephant::drop() {
    cout << "The elephant drops " << item << endl;
    item = ""; //sets the item to nothing
}

string Elephant::getItem() {
    return item;
}