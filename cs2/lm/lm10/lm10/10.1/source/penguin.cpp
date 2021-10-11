#include "../headers/penguin.h"

Penguin::Penguin() : Animal() {
    type = "Emperor Penguin";
}

Penguin::Penguin(string n) : Animal(n, 0) {
    type = "Emperor Penguin";
}

Penguin::Penguin(string n, int years) : Animal(n, years) {
    type = "Emperor Penguin";
}

Penguin::Penguin(string n, int years, string species) : Animal(n, years) {
    type = species;
}

void Penguin::makeNoise() {
    cout << "HONK HONK HONK!" << endl;
}

void Penguin::huddle() {
    cout << "The penguin huddles with its friends to stay warm!" << endl;
}

void Penguin::swim() {
    cout << "The penguin dove into the water and started swimming!" << endl;
}