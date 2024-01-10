#pragma once
#include "Point.h"

class Player
{

	Point playerPosition;
	bool hasKey;

public:
	Player();
	~Player();

	int GetXPosition() { return playerPosition.x; }
	int GetYPosition() { return playerPosition.y; }

	int* pGetXPosition() { return &(playerPosition.x); }
	int* pGetYPosition() { return &(playerPosition.y); }

	void SetXYPosition(int x, int y);

	bool HasKey() { return hasKey; }
	void PickUpKey() { hasKey = true; }
	void UseKey() { hasKey = false; }

	void DrawPlayer();

};


