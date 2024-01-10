#pragma once
#include "GameStateMachine.h"

class GameState;

class Game;

class StateMachineExampleGame : public GameStateMachine
{
private:
	Game* _pOwner;
	GameState* _pCurrentState;
	GameState* _pNewState;

public:

	enum class SceneName
	{
		MainMenue,
		Gameplay,
		Settings,
		Highscore,
		Win,
		Lose
	};

	StateMachineExampleGame(Game* pOwner);

	virtual bool init() override;
	virtual bool update(bool processInput = true) override;
	virtual void draw() override;
	virtual GameState* changeState(GameState* pNewState) override;
	virtual void cleanUp() override;

	bool loadScene(SceneName scene);

};