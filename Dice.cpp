#include "Dice.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


Dice::Dice()
{
	srand(time(NULL));
	this->result = 0;
}

int Dice::diceRoll()
{
	this->result = 0;
	this->result = rand() % 6 + 1;
	return this->showResult();
}

int Dice::showResult()
{
	return this->result;
}

Dice::~Dice()
{
	this->result = 0;
}
