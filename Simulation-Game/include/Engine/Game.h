#pragma once
#include "Unit.h"

class Game
{
public:
	Game(Unit* player1, Unit* player2);
	virtual ~Game();
	void Run();
	
private: 
	int round = 0;
	void DoRound();
	bool CheckForWin();
	Unit* GetWinner();
	Unit* player1;
	Unit* player2;
};

