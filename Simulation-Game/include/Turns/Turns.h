#pragma once
#include "Component.h"

class Turns : public Component
{
public:
	Turns();
	// DON'T INLINE IT !!!!
	void setTurnsNoAttack(int _turnsNoAttack);
	void setTurnsBeforeSpellUse(int _turnsBeforeSpellUse);

	// Fight interruptions
	// We make it public because enemy has to apply effect on it !
	int turnsNoAttack;
	int turnsBeforeSpellUse;
};
