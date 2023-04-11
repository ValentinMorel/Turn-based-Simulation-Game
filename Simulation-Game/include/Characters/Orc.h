#pragma once

#include "Unit.h"
#include "Armor.h"
#include "Weapon.h"

// Compiler instructions : ORC character description
// Optimized constants that respect DRY principles: define them once, use them 1000 times
// HAS TO be in header file

// Base character stats
#define ORC_NAME "Orc"
#define ORC_HEALTH 60

// Spell related
#define ORC_SUCCESS_ODD 20
#define STUN_COOLDOWN 5
#define STUN_ENEMY_TURNS_NO_ATTACK 1

class Orc : public Unit
{
public: 
	Orc(Weapon* weapon, Armor* shield);
	Orc(const std::string& nick, Weapon* weapon, Armor* shield);
	virtual ~Orc();
	void spell(Unit* enemy) override;
};

