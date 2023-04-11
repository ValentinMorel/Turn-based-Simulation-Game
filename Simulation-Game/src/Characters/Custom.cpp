#include <iostream>
#include <algorithm>
#include "Custom.h"
#include "Orc.h"
#include "Knight.h"

enum class SpellType {
	STUN,
	CHARGE,
	COMBO
};

Custom::Custom(const std::string& name, const std::string& nick, const int& health, Armor* armor, Weapon* weapon, const std::string& spellChoice, const int& successOdd) {
	std::string spellChoiceTransform;
	spellChoiceTransform.resize(spellChoice.size());
	std::transform(spellChoice.begin(), spellChoice.end(), spellChoiceTransform.begin(), ::tolower);
	
	this->addComponent(weapon);
	this->addComponent(armor);
	this->addComponent(new Turns());
	this->name = name;
	this->nick = nick;
	this->health = health;
	this->successOdd = successOdd;
	this->spellChoice = spellChoiceTransform;

}

Custom::~Custom() {};


void Custom::spell(Unit* enemy) {
	SpellType spell{};
	
	if (this->spellChoice == "stun") {
		spell = SpellType::STUN;
		this->spellCooldown = STUN_COOLDOWN;
		
	}
	else if (this->spellChoice == "charge") {
		spell = SpellType::CHARGE;
		this->spellCooldown = CHARGE_COOLDOWN;
		
	}
	else if (this->spellChoice == "combo") {
		spell = SpellType::COMBO;
		this->spellCooldown = COMBO_COOLDOWN;
		
	}

	switch (spell) {
	case SpellType::STUN:
	{
		std::cout << this->getName() << " (" << this->getNick() << ")" << " used STUN!" << std::endl;
		// CD : 5 turns !
		// Penalize enemy's next turn !
		enemy->getComponent<Turns>()->setTurnsNoAttack(STUN_ENEMY_TURNS_NO_ATTACK);
	}
		break;
	case SpellType::CHARGE:
	{
		std::cout << this->getName() << " (" << this->getNick() << ")" << " used CHARGE!" << std::endl;
		// Basically, the spell consists of a boosted melee attack with double power
		// In the future, we can add percentages for thing like buffs
		// CD : 3 turns ! 
		Custom::melee(enemy, 2);
	}
		break;
	case SpellType::COMBO:
	{
		std::cout << this->getName() << " (" << this->getNick() << ")" << " used COMBO!" << std::endl;
		// Basically, the spell consists of a boosted melee attack with triple power, with increased CD
		// CD : 5 turns ! 
		Custom::melee(enemy, 3);
	}
		break;
	
	default:
		// handle unknown spell
		break;
	}
}

