#include "../headers/Treasure.h"

Object * Treasure::takeme()
{
	cout << "You got " << this->getValue() << " points!" << endl;
	return this;
}
