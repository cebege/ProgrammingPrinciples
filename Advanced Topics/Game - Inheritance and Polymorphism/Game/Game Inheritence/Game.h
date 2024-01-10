#pragma once
#include "GameStateMachine.h"


class Game
{
public:
	GameStateMachine* m_pStateMachine;

public:
	Game();
	void Initialise(GameStateMachine* pStateMachine);
	void RunGameLoop();
	void Deinitialise();

private:
	bool Update(bool processInput = true);
	void Draw();

};
