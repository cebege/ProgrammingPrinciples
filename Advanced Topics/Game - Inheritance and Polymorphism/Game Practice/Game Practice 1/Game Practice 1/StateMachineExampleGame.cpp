#include "StateMachineExampleGame.h"
#include "GameState.h"
#include "GameStateMachine.h"

StateMachineExampleGame::StateMachineExampleGame(Game* pOwner)
	: _pOwner(pOwner)
	, _pCurrentState(nullptr)
	, _pNewState(nullptr)
{};

bool StateMachineExampleGame::init()
{
	load(SceneName::MainMenue);
	return true;
}

bool StateMachineExampleGame::update(bool processInput)
{
	bool done = false;
	if (_pNewState != nullptr)
	{
		changeState(_pNewState);
		_pNewState = nullptr;
	}
	if (_pCurrentState)
	{
		done = update(processInput);
	}
	return done;
}

void StateMachineExampleGame::draw()
{
	if (_pCurrentState)
	{
		_pCurrentState->draw();
	}
}

GameState* StateMachineExampleGame::changeState(GameState* pNewState)
{
	if (_pCurrentState)
	{
		_pCurrentState->exit();
	}
	delete _pCurrentState;
	_pCurrentState = pNewState;
	pNewState->enter();
}

void StateMachineExampleGame::cleanUp()
{
	_pCurrentState->exit();
	delete _pCurrentState;
}

bool StateMachineExampleGame:: load(SceneName scene)
{
	switch (scene)
	{
	case SceneName::MainMenue:
		_pNewState = new MainMenue(this);
		break;


	}
}