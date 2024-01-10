#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fStream>
#include "Game.h"
using namespace std;

int main() {

	Game myGame;

	if (myGame.loadLevel())
	{
		while (!myGame.isGameOver())
		{
			myGame.run();
		}
		cout << "You Win!" << endl;
		// PlayWinSound.
	}
	{
		cout << "Game did not load. Terminating now!" << endl;
	}

}