//main.cpp
//CS172-1 CS2
//Aaron Borjas
//4/30/2019
//This program is experiements with polymorphism and creates a zoo with 12 animals of four different children classes:
//elephants, giraffes, penguins, and seals. The polymorphic relationship is demonstrated primarly using the for loop 
//at the end of the "main" function. The code describing the functions are located inside the header files for each class

#include <iostream>
#include <string>
#include <vector>
#include "../headers/animal.h"
#include "../headers/elephant.h"
#include "../headers/giraffe.h"
#include "../headers/penguin.h"
#include "../headers/seal.h"

using namespace std;

int main() {
    //creates new elephants with different trunk lengths
    Elephant ele1 = Elephant("Ellie", 37, 6.7);
    Elephant ele2 = Elephant("Julio", 15, 5.8);
    Elephant ele3 = Elephant("Gabby", 43);

    //creates new giraffes with different neck lengths
    Giraffe gir1 = Giraffe("Garfield", 16, 6.8);
    Giraffe gir2 = Giraffe("Conroy", 23, 5.4);
    Giraffe gir3 = Giraffe("Johny", 13);

    //creates new penguins of different species
    Penguin pen1 = Penguin("Geoff", 4, "Chinstrap Penguin");
    Penguin pen2 = Penguin("Henry", 10);
    Penguin pen3 = Penguin("Gavin", 7, "African Penguin");

    //creates different colored seals
    Seal seal1 = Seal("Carlos", 10, "Rainbow");
    Seal seal2 = Seal("Olga", 11);
    Seal seal3 = Seal("Keightlyn", 16, "Purple"); //the use of "Keightlyn" is not serious. I do not condone the use of the name "Keightlyn"

    vector<Animal *> theZoo; //creates a vector of animals called "theZoo"

    //pushes the elephants into the zoo
    theZoo.push_back(&ele1);
    theZoo.push_back(&ele2);
    theZoo.push_back(&ele3);

    //pushes the giraffes into the zoo
    theZoo.push_back(&gir1);
    theZoo.push_back(&gir2);
    theZoo.push_back(&gir3);

    //pushes the penguins into the zoo
    theZoo.push_back(&pen1);
    theZoo.push_back(&pen2);
    theZoo.push_back(&pen3);

    //pushes the seals to the zoo
    theZoo.push_back(&seal1);
    theZoo.push_back(&seal2);
    theZoo.push_back(&seal3); 


    for(int i = 0; i < theZoo.size(); i++) { //iterates through the zoo
        cout << "Animal number " << i+1 << " from theZoo: " << endl; //says what animal is being messed up
        cout << *(theZoo[i]) << endl; //prints out the information about the animal with the operator overload for animal

        cout << "Changing the animal..." << endl << endl; //says that the animal is changing
        theZoo[i]->makeNoise(); //the animal currently being evaluated makes noise
        theZoo[i]->growUp(); //makes the animal currently being evaluated grows up (ages up 1 year)
        
        cout << *(theZoo[i]) << endl; //prints out the information about the animal with the operator overload for animal

        cout << endl; //new line
    }


}