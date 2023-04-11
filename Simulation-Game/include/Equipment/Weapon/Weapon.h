#pragma once
#include <string>
#include "Component.h"

class Weapon : public Component
{
public:
	Weapon();
	Weapon(const std::string& name, int damage);
	int getDamage();
	std::string getName();
protected:
	int damage = 0;
	std::string name = "";
};



