#include "Turns.h"
#include <iostream>

Turns::Turns() {
	this->turnsBeforeSpellUse = 0;
	this->turnsNoAttack = 0;
}


void Turns::setTurnsNoAttack(int _turnsNoAttack) { 
	this->turnsNoAttack = _turnsNoAttack; 
}
void Turns::setTurnsBeforeSpellUse(int _turnsBeforeSpellUse) {
	this->turnsBeforeSpellUse = _turnsBeforeSpellUse; 
}
