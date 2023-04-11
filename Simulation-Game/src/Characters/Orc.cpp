#include <iostream>

#include "Orc.h"

Orc::Orc(Weapon* weapon, Armor* armor) {
	this->addComponent(weapon);
	this->addComponent(armor);
	this->name = ORC_NAME;
	this->health = ORC_HEALTH;
	this->successOdd = ORC_SUCCESS_ODD;
	this->spellCooldown = STUN_COOLDOWN;

}

// Define a nick by overloading constructor
Orc::Orc(const std::string& nick, Weapon* weapon, Armor* armor) {
	this->nick = nick;
	this->addComponent(weapon);
	this->addComponent(armor);
	this->addComponent(new Turns());
	this->name = ORC_NAME;
	this->health = ORC_HEALTH;
	this->successOdd = ORC_SUCCESS_ODD;
	this->spellCooldown = STUN_COOLDOWN;
}

Orc::~Orc() {};



void Orc::spell(Unit* enemy) 
{
	std::cout << "Orc used STUN !" << std::endl;
	// Penalize enemy's next turn !
	enemy->getComponent<Turns>()->setTurnsNoAttack(STUN_ENEMY_TURNS_NO_ATTACK);
	
}
