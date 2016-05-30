#include "dice.h"
#include "BoardGame.h"



int main()
{
	BoardGame o;
	do
	{
	o.createPlayers();
	o.play();
	o.whoWins();
	} while (o.playAgain() == true);


}