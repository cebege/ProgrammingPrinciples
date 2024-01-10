#pragma once

#include "GameState.h"
#include "Level.h"
#include "Player.h"
#include <vector>
#include <string>
#include <Windows.h>

class StateMachineExampleGame;

class GameplayState : public GameState
{
private:

	StateMachineExampleGame* _pOwner;
	Level* _pLevel;
	Player _player;

	int _currentLevel;

	int _skipFrameCount;
	static constexpr int kFrameToSkip = 2;

	vector<string>_levelNames;

	bool _beatLevel;

public:

	GameplayState(StateMachineExampleGame* pOwner);
	~GameplayState();

	virtual bool enter() override;
	virtual bool update(bool processInput = true) override;
	virtual void draw() override;
	virtual void exit() override;

private:
	bool load();
	void handleCollision(int newPlayerX, int newPlayerY);
	void drawHUD(const HANDLE& console);

};