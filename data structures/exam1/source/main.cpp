//Exam 1 practical portion
//Aaron Borjas
//CS273-1
//Matt Bell
//This program is for the exam 1 practical portion. The goal is to use polymorphism, which is done with
//an abstract base class called "Figurine" which defines a default figurine. The two child classes of figurine
//are Lego and Transformer. Lego is different because it comes from a set and has a weapon, and transformer
//is unique because it has a "team" (autobot or decepticon) and has a status of "transformed". A Lego's weapon
//is contained in the lego class, and has a property of rarity, along with a name and description.

#include <iostream>
#include <string>
#include "../headers/Figurine.h"
#include "../headers/Lego.h"
#include "../headers/Weapon.h"
#include "../headers/Transformer.h"
using namespace std;

int main() {
    //makes a new lightsaber with a name, description, and rarity
    Weapon lightsaber("Lightsaber", "an elegant weapon for a more civilized age", EPIC);

    //makes a new lego figurine, which is human, male, has a weapon, and is holding a weapon
    Lego legoAnakin(true, MALE, true, lightsaber, "Tusken Raider Encounter");

    //prints the description of the lego figurine "legoAnakin"
    cout << legoAnakin.describe_me() << endl;

    //makes a new transformer figurine, which is not humanoid, an autobot, and is not transformed (it is not a vehicle)
    Transformer optimus("autobot", false);

    //prints the description of the transformer figurine "optimus"
    cout << optimus.describe_me() << endl;

}