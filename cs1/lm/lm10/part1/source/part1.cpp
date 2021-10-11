//part1.cpp
//CS171-1
//Aaron Borjas
//11/16/18
//This program uses a class to have two characters battle, and once one character has below 0 health, the winner is declared.

#include <iostream> //cin and cout
#include <string> //string
#include <cstdlib>//rand()
#include <ctime>//time
using namespace std;

class Character { //character class for a video game character (based on the game overwatch)
    public:
        //class variables
        string name; //name
        string role; //role (tank, support, damage)
        string weapon; //Primary weapon
        int health; //amount of hitpoints (no armor or shields)
        string mainAbility; //the main ability that the character uses (generally the ability bound to shift)
        int abilityDamage; //the amount of damage the ability does
        string ultimate; //the ultimate ability of the character, which does a guarunteed amount of damage, generally more than normal abilities
        int ultimateDamage; //amount of dmg the ultimate does
        bool dead; //if the character is dead or not

        Character() { //default constructor
            dead = false; //the character starts off alive
        }

        Character(string hero, string primaryWeapon) { //constructor to implement a character by putting in hero and primary weapon while initializing the object
            name = hero; //sets character's name to what hero is equal
            weapon = primaryWeapon; //sets the character's weapon to what was inputed for the primary weapon
            dead = false; //character starts off alive
        }

        //function printCharacter
        //Prints the basic outline of the character
        //Inputs - NA
        //Outputs - Prints the class variables specific to chosen object
        void printCharacter() { 
            cout << "Character's name: " << name << endl;
            cout << name << "'s role: " << role << endl;
            cout << name <<"'s weapon: " << weapon << endl;
            cout << name <<"'s health: " << health << endl;
            cout << name << "'s main ability: " << mainAbility << endl;
            cout << name << "'s main ability damage: " << abilityDamage << endl;
            cout << name << "'s passive ability: " << ultimate << endl;
        }

        //function getDamaged
        //damages a character for a given amount of damage
        //Inputs - a positive integer to indicate damage
        //Outputs - prints who got damaged and then the remaining health of the damaged character
        void getDamaged(unsigned int damage) {
            cout << name << " was hit with " << damage << " damage!" << endl; 
            health = health - (damage); //health is equal to health-damage
            cout << name << "'s health is now " << health << endl;
        }

        //function useUlt
        //uses the character's ultimate ability on the enemy character.
        //Inputs - the enemy character, which passes by reference. This makes it so that the value of their health actually changes
        //Outputs - None
        void useUlt(Character& enemy) {
            cout << name << " uses their ultimate, " << ultimate << " on " << enemy.name << " for " << ultimateDamage << " damage!" << endl;

            enemy.getDamaged(ultimateDamage); //damages the enemy with the character's ultimate damage
        }

        //function attack
        //This function uses the previous two functions to have one character attack another character, possibly using their ultimate ability or their main ability
        //Inputs - the enemy character, which passes by reference. Along with that, a true or false value to indicate whether or not the character uses their main ability.
        //Outputs - Prints out the attacks, the abilities used, and who was defeated
        void attack(Character& enemy, bool useAbility) {
            int damage = rand() % (enemy.health); //damage is a random value from 0 to the value of the enemy's health
            if(useAbility) { //if the character's ability is chosen to be used...
                cout << name << " attacks " << enemy.name << " with their " << mainAbility << "!" << endl;
                enemy.getDamaged(abilityDamage); //damage the enemy with the amount of damage the ability is worth.
                if(enemy.health <= 0) { //if the enemy's health is at or below 0, 
                    cout << enemy.name << " was defeated!";
                    dead = true; //change dead to true
                }
            }
            else if((rand() % 101) > 90) { //otherwise, if a random number between 0 and 100 is greater than 90...
                useUlt(enemy); //use the character's ult on the enemy
                if(enemy.health <= 0) { //if the enemy's health is at or below 0...
                    cout << enemy.name << " was defeated!";
                    dead = true; //change dead to true;
                }
            }
            else { //otherwise, if none of the above if statements are true...
                cout << name << " attacks " << enemy.name << " with their primary weapon, " << weapon << "!" << endl;
                enemy.getDamaged(damage); //the enemy is damaged with a value from 0 to the amount of health they had at the start of this function (from int damage)
                if(enemy.health <= 0) { // if the enemy's health is at or below 0...
                    cout << enemy.name << " was defeated!";
                    dead = true; //change dead to true
                }
            }
        }
}; //class Character ends here

//function battle
//starts a battle which lasts until one out of two characters dies
//Inputs - two Characters, both with all the Character variables initialized as a value
//outputs - prints out the battle between both characters until one of the character's health drops below zero
void battle(Character one, Character two) {
    while( (!one.dead) && (!two.dead) ) { //while both characters are alive.
        one.attack(two, static_cast<bool>(rand()%2)); //first character attacks the second, and randomly uses their ability
        if(two.health <= 0) { //if the second character's health is below or at zero (this makes it so that the second character doesn't attack after they are dead)
            two.dead = true; //the second Character is dead
        }
        else { //otherwise if the second character's health is above zero
            cout << endl << endl; //two new lines
            two.attack(one, static_cast<bool>(rand()%2)); //second character attacks the first, and randomly uses their ability

            cout << endl  << endl;
        }
    }
}


int main() {
    srand(time(NULL)); //seeds for rand()

    Character genji("Genji", "Shuriken"); //new character called Genji who's main weapons are shurikens
    genji.role = "Damage"; //genji is a damage character
    genji.health = 200; // genji has 200 health
    genji.mainAbility = "Swift Strike"; //genji's main ability is swift strike
    genji.abilityDamage = 50; //genji does 50 damage with his main ability
    genji.ultimate = "Dragonblade"; //genji's ultimate is dragonblade
    genji.ultimateDamage = 840; //dragonblade has 7 slashes for 120 dmg each

    Character winston("Winston", "Tesla Cannon"); //new character called Winston who's main weapon is a tesla cannon
    winston.role = "Tank"; //Winston is a tank
    winston.health = 500; //winston has 500 health
    winston.mainAbility = "Jump Pack"; //winston's main ability is jump pack
    winston.abilityDamage = 45; //winston's ability does 45 damage
    winston.ultimate = "Primal Rage"; //winston's is primal rage
    winston.ultimateDamage = 465; //primal rage does has 6 punches for 40 dmg per punch plus 5 jumps * 45 dmg per jump

    genji.printCharacter(); //print genji and his main attributes
    cout << endl;

    winston.printCharacter(); //prints winston and his main attributes
    cout << endl;

    cout << "-----------------------------------" << endl;
    cout << "           FIGHT TIME          " << endl;
    cout << "-----------------------------------" << endl << endl;

    battle(genji, winston); //initiate a battle between genji and winston
}