#include "Player.h"


Player::Player()
{
	currentPlayerPosition = 0;
}

void Player::setName(string name)
{
	this->name = name;
}

string Player::returnName()
{
	return name;
}

void Player::movePlayer(int amount)
{
	
	this->currentPlayerPosition= currentPlayerPosition + amount;
	 
}

int Player::playerPosition()
{
	return this->currentPlayerPosition;
}




Player::~Player()
{
}
