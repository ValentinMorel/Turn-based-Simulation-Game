#include "Armor.h"
#include <iostream>

Armor::Armor() {}

Armor::Armor(int shield) {
	this->shield = shield;
}

int Armor::getShield() { 

	return this->shield;
}

void Armor::setShield(int shield) {
	this->shield = shield;
}