////////////////////////////////
// title: Object.h
// descr: Pure virtual superclass for Exit and Treasure
//
// describeme() displays the object name and verbose description
// pure virtual function takeme() displays an appropriate message
// depending on whether this is an exit or a treasure.
//
// Author: Matthew Bell and CS273-Fall 2018
// Last updated: 10/16/2018
////////////////////////////////

#include <string>
#include <iostream>
using namespace std;
#ifndef OBJECT_H_
#define OBJECT_H_

class Object {
private:
	string name;
	string descr;
	int value; //For exits, this will be where it takes you. For treasures, it's point value.
public:
	Object(string name = "Thingy",
		string descr = "The thingy is nondescript.",
		int value = -1) : name(name), descr(descr), value(value) {}

	void describeme() { 
		cout << descr << endl; 
	}

	string getName() { 
		return name; 
	}

	int getValue() { 
		return value; 
	}

	virtual Object* takeme() = 0;
};

#endif