//evennumber.cpp
//CS172-1 CS2
//Aaron Borjas
//2/18/19
//implementing evennumber.h and evennumber.cpp, showing that they work

#include <iostream>
#include "../headers/evennumber.h"
using namespace std;

int main() {
    EvenNumber first = EvenNumber(); //first constructor

    int num; //placeholder for user input
    cout << "Enter an even number for the second even number: "; //tells user what to enter
    cin >> num; //gets user input

    EvenNumber second = EvenNumber(num); //second constructor

    //testing the methods for the first even number
    cout << "The value of the first EvenNumber is " << first.getValue() << endl;
    cout << "The value before the first EvenNumber is " << first.getPrevious() << endl;
    cout << "The value after the first EvenNumber is " << first.getNextNumber() << endl;

    cout << endl << endl;

    //testing the methods for the second even number
    cout << "The value of the second EvenNumber is " << second.getValue() << endl;
    cout << "The value before the second EvenNumber is " << second.getPrevious() << endl;
    cout << "The value after the second EvenNumber is " << second.getNextNumber() << endl << endl;

    EvenNumber iteration = first.getValue(); //creates a new EvenNumber called iteration, which is equal to the value of the first EvenNumber
    while(iteration.getValue() <= second.getValue()) { //while the value of the first even number is less than the value of the second even number
        cout << iteration.getValue() << " "; //prints the value of iteration
        iteration = iteration.getNextNumber(); //changes iteration to be equal to the number after the current iteration
    }
}