#include "Game.h"
#include "Unit.h"
#include <iostream>

Game::Game(Unit* _player1, Unit* _player2)
{
	player1 = _player1;
	player2 = _player2;
};

Game::~Game() {};

void Game::DoRound() {
	this->round++;
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	std::cout << "                                      TURN "<< this->round                      << std::endl;
	std::cout << "------------------------------------------------------------------------------" << std::endl;

	std::cout << "\nPLAYER 1: " << player1->getName() << " (" << player1->getNick() << ") : " << player1->getHealth() << " HP, " << player1->getComponent<Armor>()->getShield() << " Shield" << std::endl;

	std::cout << "turns no attack: " << player1->getComponent<Turns>()->turnsNoAttack << std::endl;
	std::cout << "turns before spell use: " << player1->getComponent<Turns>()->turnsBeforeSpellUse << std::endl;

	int p2StartHealth = player2->getHealth();
	int p2StartShield = player2->getComponent<Armor>()->getShield();
	
	// PLAYER 1 attacks PLAYER 2
	player1->attack(player2);

	int p2EndHealth = player2->getHealth();
	int p2EndShield = player2->getComponent<Armor>()->getShield();

	if (p2StartHealth == p2EndHealth && p2StartShield == p2EndShield) {

		std::cout << player1->getName() << " (" << player1->getNick() << ") passed his turned, nothing done !" << std::endl;
	}
	else {
		std::cout << player1->getName() << " (" << player1->getNick() << ") attacked  ---> " << player2->getName() << " (" << player2->getNick() << ") : " << player2->getHealth() << " HP (" << (p2EndHealth - p2StartHealth) << "), " << player2->getComponent<Armor>()->getShield() << " Shield (" << (p2EndShield - p2StartShield) << ") " << std::endl;
	}

	if (player2->getHealth() <= 0) {
		return;
	}

	std::cout << "\n\nPLAYER 2: " << player2->getName() << " (" << player2->getNick() << ") : " << player2->getHealth() << " HP, " << player2->getComponent<Armor>()->getShield() << " Shield" << std::endl;
	std::cout << "turns no attack: " << player2->getComponent<Turns>()->turnsNoAttack << std::endl;
	std::cout << "turns before spell use: " << player2->getComponent<Turns>()->turnsBeforeSpellUse << std::endl;
	
	int p1StartHealth = player1->getHealth();
	int p1StartShield = player1->getComponent<Armor>()->getShield();

	// PLAYER 2 attacks PLAYER 1
	player2->attack(player1);

	int p1EndHealth = player1->getHealth();
	int p1EndShield = player1->getComponent<Armor>()->getShield();

	if (p1StartHealth == p1EndHealth && p1StartShield == p1EndShield) {
		std::cout << player2->getName() << " (" << player2->getNick() << ") passed his turned, nothing done !\n" << std::endl;
	}
	else {
		std::cout << player2->getName() << " (" << player2->getNick() << ") attacked ---> " << player1->getName() << " (" << player1->getNick() << ") : " << player1->getHealth() << " HP (" << (p1EndHealth - p1StartHealth) <<"), " << player1->getComponent<Armor>()->getShield() << " Shield (" << (p1EndShield - p1StartShield) << ") \n" << std::endl;
	}

	if (player1->getHealth() <= 0) {
		return;
	}
};

// Check if one player reached 0 health to determine if we should stop the game
bool Game::CheckForWin() {
	return player1->getHealth() <= 0 || player2->getHealth() <= 0;
};

Unit* Game::GetWinner() {
	if (player1->getHealth() > 0) {
		return player1;
	}
	else if (player1->getHealth() <= 0 && player2->getHealth() <= 0) {
		return player1;
	}
	else {
		return player2;
	}
};


// Main game loop
void Game::Run() {

	while (!CheckForWin())
	{
		DoRound();
	}

	Unit* winner = GetWinner();
	std::cout << "\n------------------------------------------------------------------------------" << std::endl;
	std::cout << "                                    RESULT "									    << std::endl;
	std::cout << "------------------------------------------------------------------------------" << std::endl;
	std::cout << "\nWE GOT A WINNER !!!!" << std::endl;
	if (winner->getNick() != "") {
		std::cout << winner->getName() << " (" << winner->getNick() << ") " << " has won on round at " << this->round << "th round" << std::endl;
	}
	else {
		std::cout << winner->getName() << " has won on round at " << this->round << "th round" << std::endl;
	}
	std::cout << "\n------------------------------------------------------------------------------" << std::endl;

};