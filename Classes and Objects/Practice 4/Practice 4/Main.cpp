#include <iostream>
#include <Windows.h>
#include "Game.h"

int main() {
	Game myGame;

	if (myGame.load())
	{
		while (!myGame.isGameOver())
		{
			myGame.run();
		}
		cout << "You Win!" << endl;
	}
	else
	{
		cout << "Game did not load" << endl;
	}


	return 0;
}