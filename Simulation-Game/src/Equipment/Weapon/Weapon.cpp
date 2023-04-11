#include <iostream>
#include "Weapon.h"




Weapon::Weapon() {};
Weapon::Weapon(const std::string& name, int damage) {
	this->name = name; 
	this->damage = damage;
};


int Weapon::getDamage() {
	return this->damage;
}

std::string Weapon::getName() { 
	return this->name;
}

