#include "../headers/giraffe.h"


Giraffe::Giraffe() : Animal() {
    neckLength = 6;
}

Giraffe::Giraffe(string n) : Animal(n, 0) {
    neckLength = 6;
}

Giraffe::Giraffe(string n, int years) : Animal(n, years) {
    neckLength = 6;
}

Giraffe::Giraffe(string n, int years, float neck) : Animal(n, years) {
    neckLength = neck;
}

void Giraffe::makeNoise() {
    //http://time.com/4043387/giraffes-sound-hum/
    //according to this, giraffes hum
    cout << "hmmm...hmmm...." << endl; 
}

void Giraffe::neckWhip() {
    cout << "The giraffe whips its neck in anger!" << endl;
}

void Giraffe::getWater() {
    cout << "The giraffe bends down to get water!" << endl;
}