#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <fStream>

#include "StateMachineExampleGame.h"
#include "AudioManager.h"
#include "Game.h"
using namespace std;

int main() {

	Game myGame;

	StateMachineExampleGame gameStateMachine(&myGame);

	myGame.Initialise(&gameStateMachine);
	myGame.RunGameLoop();
	myGame.Deinitialise();

	AudioManager::destroyInstance();

	return 0;
	
}

