#include "../headers/director.h"
using namespace std;

Director::Director() {

}

Director::Director(string dirName, int dirAge, string dirPrevious) {
    name = dirName;
    age = dirAge;
    previousMovie = dirPrevious;
}

string Director::getName() {
    return name;
}

int Director::getAge() {
    return age;
}

string Director::getPrevious() {
    return previousMovie;
}

void Director::print() {
    cout << "The director's name is: " << name << endl;
    cout << name << "'s age is: " << age << endl;
    cout << name << "'s previous movie is: " << previousMovie << endl;
}