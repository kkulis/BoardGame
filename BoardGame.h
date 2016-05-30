#include "Board.h"
#include "Dice.h"
#include "Player.h"




#pragma once
class BoardGame
{
public:
	Player* playerBoard[10];
	int nofPlayers;
	int nofPeople;
	int nofComputers;
	Dice* dice;
	Board* board;


public:
	BoardGame();
	void createPlayers();
	void play();
	void whoWins();
	bool endGame();
	bool playAgain();
	void trapCheck(Player* p);
	~BoardGame();
};

