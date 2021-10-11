#include "../headers/seal.h"

Seal::Seal() : Animal() {
    color = "Grey";
}

Seal::Seal(string n) : Animal(n, 0) {
    color = "Grey";
}

Seal::Seal(string n, int years) : Animal(n, years) {
    color = "Grey";
}

Seal::Seal(string n, int years, string c) : Animal(n, years) {
    color = c;
}

void Seal::makeNoise() {
    cout << "ort ort ort :D" << endl;
}

void Seal::clap() {
    cout << "*seal claps*" << endl;
}

void Seal::swim() {
    cout << "The seal jumped in the water and started swimming!" << endl;
}