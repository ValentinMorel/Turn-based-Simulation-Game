#pragma once

#include "Unit.h"

#define COMBO_COOLDOWN 5

class Custom : public Unit
{
public:
	// Used to construct a brand new character in the CLI -> modularity of the game, create your own class ! :)
	Custom(const std::string& name, const std::string& nick, const int& health, Armor* shield, Weapon* weapon, const std::string& spellChoice, const int& successOdd);
	virtual ~Custom();
	void spell(Unit* enemy) override;

private:
	std::string spellChoice;
};

