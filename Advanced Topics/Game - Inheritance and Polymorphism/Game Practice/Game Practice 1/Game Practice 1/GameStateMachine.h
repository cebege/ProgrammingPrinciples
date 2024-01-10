#pragma once

class GameState;

class GameStateMachine
{
public:

	virtual ~GameStateMachine() = default;

	 virtual bool init() = 0;
	 virtual bool update(bool processInput = true) = 0;
	 virtual void draw() = 0;
	 virtual GameState* changeState(GameState* pNewState) = 0;
	 virtual void cleanUp() = 0;

};