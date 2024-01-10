#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fStream>
#include "Game.h"
using namespace std;

int main() {

	Game myGame;

	if (myGame.load())
	{
		while (!myGame.isGameOver())
		{
			myGame.Run();
		}
		if (myGame.didUserQuit())
		{
			cout << "Thanks for playing!" << endl;
		}
		if (myGame.getPlayerLives() < 0)
		{
			cout << "You lose!" << endl;
		}
		else
		{
			cout << "You win!" << endl;
		}
	}
	else
	{
		cout << "Game did not load" << endl;
	}
	
}

//void PlayDoorClose()
//{
//	Beep(500, 75); // frequency and duration
//	Beep(500, 75);
//}
//void PlayerDoorOpen()
//{
//	Beep(1397, 97);
//}
//void PickUpKey()
//{
//	Beep(1568, 100);
//}
//void Win()
//{
//	Beep(1568, 200);
//	Beep(1568, 200);
//	Beep(1568, 200);
//	Beep(1245, 1000);
//	Beep(1397, 200);
//	Beep(1397, 200);
//	Beep(1397, 200);
//	Beep(1175, 1000);
//}