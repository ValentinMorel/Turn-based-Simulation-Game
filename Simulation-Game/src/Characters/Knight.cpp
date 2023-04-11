#include <iostream>
#include "Knight.h"


Knight::Knight(Weapon* weapon, Armor* armor) {
	this->addComponent(weapon);
	this->addComponent(armor);
	this->addComponent(new Turns());
	this->name = KNIGHT_NAME;
	this->health = KNIGHT_HEALTH;
	this->successOdd = KNIGHT_SUCCESS_ODD;
	this->spellCooldown = CHARGE_COOLDOWN;

}

// Define a nick by overloading constructor
Knight::Knight(const std::string& nick, Weapon* weapon, Armor* armor) {
	this->nick = nick;
	this->addComponent(weapon);
	this->addComponent(armor);
	this->addComponent(new Turns());
	this->name = KNIGHT_NAME;
	this->health = KNIGHT_HEALTH;
	this->successOdd = KNIGHT_SUCCESS_ODD;
	this->spellCooldown = CHARGE_COOLDOWN;
}

Knight::~Knight() {};


void Knight::spell(Unit* enemy)
{
	std::cout << "Knight used CHARGE!" << std::endl;
	// Basically, the spell consists of a boosted melee attack with double power
	// In the future, we can add percentages for things like buffs
	Knight::melee(enemy, 2);
}


