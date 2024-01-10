#include "GameplayState.h"
#include "StateMachineExampleGame.h"
#include "Enemy.h"
#include "Key.h"
#include "Door.h"
#include "Money.h"
#include "Goal.h"
#include "AudioManager.h"
#include <Windows.h>
#include <conio.h>
#include <assert.h>

constexpr int kArrowInput = 224;
constexpr int kLeftArrow = 75;
constexpr int kRightArrow = 77;
constexpr int kUpArrow = 72;
constexpr int kDownArrow = 80;

constexpr int kEscape = 27;
constexpr int kBackspace = 8;

GameplayState::GameplayState(StateMachineExampleGame* pOwner)
	: _pOwner(pOwner)
	, _pLevel(nullptr)
	, _currentLevel(0)
	, _skipFrameCount(0)
	, _beatLevel(false)
{
	_levelNames.push_back("Level5.txt");
	_levelNames.push_back("Level5.txt");
	_levelNames.push_back("Level5.txt");
}

GameplayState::~GameplayState()
{
	if (_pLevel != nullptr)
	{
		delete _pLevel;
		_pLevel = nullptr;
	}
}

bool GameplayState::load()
{
	if (_pLevel != nullptr)
	{
		delete _pLevel;
		_pLevel = nullptr;
	}

	_pLevel = new Level();

	return _pLevel->loadlevel(_levelNames.at(_currentLevel), _player.getPositionX_ptr(), _player.getPositionY_ptr());

}

bool GameplayState::update(bool processInput)
{
	if (processInput && !_beatLevel)
	{
		int input = _getch();
		int arrowInput = 0;
		int newPlayerInputX = _player.getPositionX();
		int newPlayerInputY = _player.getPositionY();

		if (input == kArrowInput)
		{
			arrowInput = _getch();
		}
		if (input == kArrowInput && arrowInput == kUpArrow)
		{
			newPlayerInputY--;
		}
		else if (input == kEscape)
		{
			_pOwner->loadScene(StateMachineExampleGame::SceneName::Gameplay);
		}
		else if (char(input) == 'k')
		{
			_player.dropKey();
		}
		else if (newPlayerInputX == _player.getPositionX())
		{

		}
		else
		{
			handleCollision(newPlayerInputX, newPlayerInputY);
		}
	}
	if (_beatLevel)
	{
		++_skipFrameCount;
		if (_skipFrameCount > kFrameToSkip)
		{
			_skipFrameCount = 0;
			_beatLevel = false;
			++_currentLevel;
			if (_currentLevel == _levelNames.size())
			{
				_pOwner->loadScene(StateMachineExampleGame::SceneName::Win);
			}
		}
		else
		{
			load();
		}
	}



	return false;
}

void GameplayState::handleCollision(int newPlayerX, int newPlayerY)
{
	bool isGameDone = false;

	PlaceableActor* collidedActor = _pLevel->updateActors(newPlayerX, newPlayerY);

	if (collidedActor != nullptr && collidedActor->isActive())
	{
		switch (collidedActor->getType())
		{
		case ActorType::Door:

			Door* collidedDoor = dynamic_cast<Door*>(collidedActor);

			if (!collidedDoor->isOpen())
			{
				if (_player.hasKey(collidedDoor->getActorColour()))
				{
					collidedDoor->Open();
					collidedDoor->remove();
					_player.setPositionXY(newPlayerX, newPlayerY);
				}
				else
				{

				}
			}
			else
			{
				_player.setPositionXY(newPlayerX, newPlayerY);
			}

		case ActorType::Goal:

			Goal* collidedGoal = dynamic_cast<Goal*>(collidedGoal);
			collidedGoal->remove();
			_player.setPositionXY(newPlayerX, newPlayerY);
			isGameDone = true;
		}
	}
	else if (_pLevel->isSpace(newPlayerX, newPlayerY))
	{
		_player.setPositionXY(newPlayerX, newPlayerY);
	}
	else if (_pLevel->isWall(newPlayerX, newPlayerY))
	{
		
	}
}
