#pragma once
#include "Player.h"

class Board
{

public:
	Board();
	void positionCheck(Player* p);
private:
	int trapFile();
	int trap1();
	int trap2();
	int trap3();
	int trap4();
	~Board();
};

