#pragma once
#include <iostream>

using namespace std;


class Player
{
private:
	int currentPlayerPosition;
	string name;
public:
	Player();
	void setName(string name);
	string returnName();
	void movePlayer(int amount);
	int playerPosition();
	
	
	
	~Player();
};

