#include "Board.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


Board::Board()
{

}

void Board::positionCheck(Player* p)
{
	int playerPosition = p->playerPosition();
	switch (playerPosition)
	{
	case 3:
		p->movePlayer(trap1());
		break;
	case 8:
		p->movePlayer(trap2());
		break;
	case 12:
		p->movePlayer(trap3());
		break;
	case 17:
		p->movePlayer(trap4());
		break;
	case 22:
		p->movePlayer(trap1());
		break;
	case 27:
		p->movePlayer(trap3());
		break;
	case 32:
		p->movePlayer(trap2());
		break;
	case 37:
		p->movePlayer(trapFile());
		break;
	case 41:
		p->movePlayer(trap3());
		break;
	case 44:
		p->movePlayer(trap4());
		break;
	case 46:
		p->movePlayer(trap3());
		break;
	default:
		break;
	}
}


int Board::trap1()
{
	cout << "cofasz sie o 3 pola" << endl;
	return -3;
}

int Board::trap2()
{
	cout << "przenosisz sie 2 pola wprzod" << endl;
	return 2;
}

int Board::trap3()
{
	cout << "przenosisz sie 5 pol wprzod" << endl;
	return 5;
}

int Board::trap4()
{
	cout << "cofasz sie 4 pola do tylu" << endl;
	return -4;
}

int Board::trapFile()
{
	string line;
	int num;
	ifstream traps;
	traps.open("traps.txt", ifstream::out);
	
	traps >> num;
	getline(traps, line);
	cout << line << endl;
	
	return num;
}
	


	


Board::~Board()
{
	
}
