#pragma once
#include <string>
#include "Weapon.h"
#include "Armor.h"
#include "Turns.h"
#include <vector>
#include <iostream>

// Define seed once
#define SEED srand((unsigned)time(0));
#define NO_WEAPON_DAMAGE 0

class Unit 
{
public:

	template <typename T>
	T* getComponent();

	void addComponent(Component* component);
	void removeComponent(Component* component);

	// Results of an attack / heal
	void setHealth(int health);

	// Getters are safe to use from the outside : characteristics.
	// 
	// Names
	std::string getName();
	std::string getNick();

	// Numeric data
	inline int getHealth();

	// all attack related actions wrapper -> encapsulation
	void attack(Unit* enemy);



protected:
	std::vector<Component*> components;
	// infos variables, no influence
	std::string name;
	std::string nick = "";

	// game related variables
	int health; 
	int successOdd;
	int spellCooldown;

	//Used to update data : turns no attack / before spell is usable
	void updateStats();

	// Check special attack availability
	bool isSpellUp();

	void melee(Unit* enemy);
	void melee(Unit* enemy, int factor);
	// Special attack -> the only thing that is different from one character to another
	// Override it in the concerned class
	virtual void spell(Unit* enemy) = 0;

	bool isSuccessful();

	
};

