#pragma once
#include "Component.h"

class Armor : public Component
{
public:
	Armor();
	Armor(int shield);
	int getShield();
	void setShield(int shield);
protected:
	int shield = 0;
};
