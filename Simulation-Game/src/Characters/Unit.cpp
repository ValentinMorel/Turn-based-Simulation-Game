#include <iostream>

#include "Unit.h"


// Getters
inline int Unit::getHealth()  { return this->health; }
std::string Unit::getName() { return this->name; }
std::string Unit::getNick() { return this->nick; }

// Setters
void Unit::setHealth(int health) { this->health = health; }


template <typename T>
T* Unit::getComponent() {
	for (auto& component : components) {
		T* typedComponent = dynamic_cast<T*>(component);
		if (typedComponent != nullptr) {
			return typedComponent;
		}
	}
	return nullptr;
}

void Unit::addComponent(Component* component) {
	// make this modular, by not adding but by modifying the ptr that has been reset
	components.push_back(component);
}
void Unit::removeComponent(Component* component) {
	components.erase(std::remove(components.begin(), components.end(), component), components.end());
}

// External components setters
//void Unit::setWeapon(Weapon* weapon) { this->weapon = weapon; }

// Gameplay actions related : stun, attack
bool Unit::isSpellUp()
{
	if (Unit::getComponent<Turns>()->turnsBeforeSpellUse > 0) { // Not yet !
		return false;
	}
	return true; // Available !
}

void Unit::updateStats() {
	if (Unit::getComponent<Turns>()->turnsBeforeSpellUse > 0) {
		Unit::getComponent<Turns>()->setTurnsBeforeSpellUse(Unit::getComponent<Turns>()->turnsBeforeSpellUse-1);
	}
	if (Unit::getComponent<Turns>()->turnsNoAttack > 0) {
		Unit::getComponent<Turns>()->setTurnsNoAttack(Unit::getComponent<Turns>()->turnsNoAttack - 1);
	}
}

void Unit::melee(Unit* enemy)
{
	if (enemy->getComponent<Armor>()->getShield() > 0) { // Subtract amount of damage to shield
		int afterShieldHit = enemy->getComponent<Armor>()->getShield() - (Unit::getComponent<Weapon>()->getDamage());
		if (afterShieldHit < 0) {
			enemy->getComponent<Armor>()->setShield(0);
		}
		else {
			enemy->getComponent<Armor>()->setShield(enemy->getComponent<Armor>()->getShield() - (Unit::getComponent<Weapon>()->getDamage()));
		}
		// Check if the shield absorbed all of the damages -> if it didn't we should have a negative result 
		// Add it to health
		if (afterShieldHit < 0) {
			enemy->setHealth(enemy->getHealth() + afterShieldHit);
		}
	}
	else {
		enemy->setHealth(enemy->getHealth() - (Unit::getComponent<Weapon>()->getDamage()));
	}
}

void Unit::melee(Unit* enemy, int factor)
{
	if (enemy->getComponent<Armor>()->getShield() > 0) { // Subtract amount of damage to shield
		int afterShieldHit = enemy->getComponent<Armor>()->getShield() - (Unit::getComponent<Weapon>()->getDamage() * factor);
		if (afterShieldHit < 0) {
			enemy->getComponent<Armor>()->setShield(0);
		}
		else {
			enemy->getComponent<Armor>()->setShield(enemy->getComponent<Armor>()->getShield() - (Unit::getComponent<Weapon>()->getDamage() * factor));
		}
		// Check if the shield absorbed all of the damages -> if it didn't we should have a negative result 
		// Add it to health
		if (afterShieldHit < 0) {
			enemy->setHealth(enemy->getHealth() + afterShieldHit);
		}
	}
	else {
		enemy->setHealth(enemy->getHealth() - (Unit::getComponent<Weapon>()->getDamage() * factor));
	}
	
}

bool Unit::isSuccessful() {
	int odd = this->successOdd / 10;
	std::cout << "Random number < " << odd << " will allow a spell." << std::endl;
	int randomNumber;
	// 0 to 9 represents 10 values
	randomNumber = rand() % 10;
	std::cout << "Result: " << randomNumber << std::endl;

	if (randomNumber < odd) {
		return true;
	}
	return false;
}

void Unit::attack(Unit* enemy)
{

	// Check if spell is available, if so, use it
	// Can succeed or fail : in both case, apply CD
	if (Unit::getComponent<Turns>()->turnsNoAttack <= 0) {
		if (Unit::isSpellUp()) {
			if (Unit::isSuccessful()) {
				this->spell(enemy);
				Unit::getComponent<Turns>()->setTurnsBeforeSpellUse(this->spellCooldown);
				Unit::melee(enemy);
				return;
			}
			if (this->getNick() != "") {
				std::cout << this->getName() << " (" << this->getNick() << ") tried to use his spell, but it failed..." << std::endl;
			}
			else {
				std::cout << this->getName() <<" tried to use his spell, but it failed..." << std::endl;
			}
			Unit::getComponent<Turns>()->setTurnsBeforeSpellUse(this->spellCooldown);	
			Unit::melee(enemy);
			return;
		}

		Unit::melee(enemy);
	}

	Unit::updateStats();

}
