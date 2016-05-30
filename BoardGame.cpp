#include "BoardGame.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

BoardGame::BoardGame()
{
}

void BoardGame::createPlayers()
{
	string name;
	string name2;

	cout << "Witaj w grze planszowej. \n" << endl;
	
	cout << "Zasady sa bardzo proste! Kazdy gracz rzuca kostka i rusza swoj pionek do przodu o ilosc wyrzuconych pol. \n" << endl;
	
	cout << "wygrywa gracz, ktory pierwszy dotrzy na 50 pole. Uwaga!!! Droga do zwyciestwa jest pelna pulapek!!!! Wybierz gracz: \n" << endl;
	
	cout << "Ilu graczy (stetruje czlowiek) chcesz dodac (max 4)?" << endl;
	cin >> nofPeople;

	while (!cin.good())
	{
		cout << "podano bledna informacje:" << endl;
		cin.clear();
		cin.sync();
		cin >> nofPeople;
	}

	if (nofPeople > 4)
	{
		nofPeople = 4;
	}

	for (int i = 0; i < nofPeople; i++)
	{
		playerBoard[i] = new Player;
		cout << "podaj imie gracz nr" << i + 1 << ":" << endl;
		cin >> name;
		playerBoard[i]->setName(name);
	}

	if (nofPeople < 4)
	{
		cout << "ile komputerow chcesz dodac(max" << 4 - nofPeople << ")?" << endl;
		cin >> nofComputers;
	}

	while (!cin.good())
	{
		cout << "podano bledna informacje. Wprowadz dane jeszcze raz:" << endl;
		cin.clear();
		cin.sync();
		cin >> nofComputers;
	}

	if (nofComputers + nofPeople > 4)
	{
		nofComputers = 4 - nofPeople;
	}

	for (int i = nofPeople; i < nofComputers + nofPeople; i++)
	{
		playerBoard[i] = new Player;
		name2 = "S.I. #";
		name2.append(1, i - nofPeople + '1');
		playerBoard[i]->setName(name2);
	}

	nofPlayers = nofComputers + nofPeople;

}

void BoardGame::play()
{
	dice = new Dice();
	board = new Board();
	
	while (this->endGame() == false)
	{

		for (int i = 0; i < nofPlayers; i++)
		{
			cout << playerBoard[i]->returnName() << endl;
			cout << "nacisnij ENTER, aby rzucic kostka i ruszyc pionkiem \n " << endl;
			_getch();
			playerBoard[i]->movePlayer(dice->diceRoll());
			cout << "ruszyles sie o:" << dice->showResult() << "pol \n" << endl;
			cout << "znajdujesz sie na " << playerBoard[i]->playerPosition() << "polu \n" << endl;
			this->trapCheck(playerBoard[i]);
			cout << "znajdujesz sie na " << playerBoard[i]->playerPosition() << "polu \n" << endl;

		}
	}
}

bool BoardGame::endGame()
{
	for (int i = 0; i < nofPlayers; i++)
	{
		
		if (playerBoard[i]->playerPosition() >= 50)
		{
			return true;
		}
		else
			return false;
	}
}

bool BoardGame::playAgain()
{
	{
		int a;
		cout << "czy chcesz zagrac jeszcze raz? 1=tak/ 2=nie?" << endl;
		cin >> a;

		if (a == 1)
		{
			return true;
		}

		else
		{
			cout << "koniec gry" << endl;
		}

	}
}

void BoardGame::whoWins()
{
	Player* winner = playerBoard[0];

	for (int i = 0; i < nofPlayers; i++)
	{
		Player* currentPlayer = playerBoard[i];
		if (currentPlayer->playerPosition() >= 50)
		{
			if (currentPlayer->playerPosition()>winner->playerPosition())
			{
				winner = currentPlayer;
			}
		}
	}

	cout << "wygral gracz:" << winner->returnName() << "!!" << endl;
}


void BoardGame::trapCheck(Player* p)
{
	board->positionCheck(p);
}

BoardGame::~BoardGame()
{
}
