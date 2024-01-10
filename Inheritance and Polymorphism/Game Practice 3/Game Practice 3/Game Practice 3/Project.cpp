#include <iostream>
#include "Game.h"

int main() {

	Game myGame;

	if (myGame.load())
	{
		if (!myGame.isGameOver())
		{
			myGame.run();
		}
		if(myGame.getPlayerLives < 0)
	}


}