#include <stdexcept>
#include <string>
#include "../headers/Location.h"

int Location::exitLocation(string name)
{
	list<Exit>::iterator cur = exits.begin();
	while (cur != exits.end()) {
		if (cur->getName() == name) // found it!
			return cur->getValue();
		++cur;
	}

	//Otherwise, we didn't find it
	return -1;
}

Object* Location::find(string name)
{
	Object* item = nullptr;
	list<Treasure>::iterator cur = inventory.begin();
	while (cur != inventory.end()) {
		if (cur->getName() == name) { // Found it!
			item = cur->takeme();
			inventory.erase(cur); // No longer here
			break;
		}
	}
	return item;
}

//Lists exits
void Location::listExits()
{
	list<Exit>::iterator it = exits.begin();
	while (it != exits.end()) {
		it->describeme();
		++it;
	}
}

//List treasures in the room inventory
void Location::listTreasures()
{
	list<Treasure>::iterator it = inventory.begin();
	while (it != inventory.end()) {
		it->describeme();
		++it;
	}
}

//Display the verbose description
void Location::describe()
{
	//Display the short name and overall description of the setting
	cout << name << endl;
	cout << descr << endl;

	//Display any exits
	if(!(exits.empty()))
		listExits();

	//Display any treasures
	if(!(inventory.empty()))
		listTreasures();
}
