#include "../headers/animal.h"

//Names and aged constructor
//Sets animal's name to n and age to a
Animal::Animal(string n, int a): name(n), age(a){}

//I change this constructor from a delegated constructor to a normal one because the delegated constructor was not working for me
//Base empty constructor
//Sets name to "" and age to 0
Animal::Animal() {
    name = "";
    age = 0;
}

//I change this constructor from a delegated constructor to a normal one because the delegated constructor was not working for me
//Named constructor
//Sets animal's name to n and age to 0
Animal::Animal(string n) { 
    name = n;
    age = 0;
}

//Adds one year to the age of the animal
//Post condition: age increments by one
void Animal::growUp(){
    age++;
    return;
}

//Interface method to get name of animal as a string
string Animal::getName() const{
    return name;
}
//Interface method to get age of animal as int
int Animal::getAge() const{
    return age;
}

ostream& operator<<(ostream& out, const Animal & anml){
    out << anml.getName() << " (" << anml.getAge() << " yrs)";
    return out;
}