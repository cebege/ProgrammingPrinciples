#pragma once

class GameState
{
public:
	virtual ~GameState() = default;

	virtual bool enter() {};
	virtual bool update(bool processInput = true) { return false; }
	virtual void draw() = 0;
	virtual void exit() {};

};