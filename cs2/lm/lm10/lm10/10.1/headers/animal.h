#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

using namespace std;

class Animal{
    private:
        //Name of the individual animal
        //Used as a unique identifier
        string name;
        //Current age of the animal in years, rounded up
        int age;
    public:
        //Base empty constructor
        //Sets name to "" and age to 0
        Animal();
        //Named constructor
        //Sets animal's name to n and age to 0
        Animal(string n);
        //Names and aged constructor
        //Sets animal's name to n and age to a
        Animal(string n, int a);

        //Method that will print vocalization or noise made by animal
        //Should be in the form of:
        // "<name>: <noise>"
        virtual void makeNoise() = 0;

        //Adds one year to the age of the animal
        //Post condition: age increments by one
        void growUp();

    protected:
        //Interface method to get name of animal as a string
        string getName() const;
        //Interface method to get age of animal as int
        int getAge() const;

    //Friend function for easily outputing the contents of an animal to output stream
    //Input: out is a currently active output stream (like cout, or an open ofstream)
    //       anml is the Animal instance that is being pushed into the output stream
    //Output: reference to the output stream that was passed in, matches pattern for cout << var << <other stuff>
    friend ostream& operator<<(ostream& out, const Animal & anml);

};

#endif