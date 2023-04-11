#pragma once

#include "Unit.h"
// Compiler instructions : KNIGHT character description
// Optimized constants that respect DRY principles: define them once, use them 1000 times
// HAS TO be in header file

// Character stats related
#define KNIGHT_NAME "Knight"
#define KNIGHT_HEALTH 20

// Spell related
#define CHARGE_COOLDOWN 3
#define KNIGHT_SUCCESS_ODD 60

class Knight : public Unit
{
public:
	Knight(Weapon* weapon, Armor* armor);
	Knight(const std::string& nick, Weapon* weapon, Armor* armor);
	virtual ~Knight();
	void spell(Unit* enemy) override;
};

