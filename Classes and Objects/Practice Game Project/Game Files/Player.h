#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Point.h"

class Player
{
private:
	Point playerPosition;
	bool hasKey;

public:
	Player();
	~Player();
	
	void setPlayerXYPosition(int x, int y);
	int getPlayerXPosition() { return playerPosition.x; }
	int getPlayerYPosition() { return playerPosition.y; }

	int* pGetPlayerXPosition() { return &playerPosition.x; }
	int* pGetPlayerYPosition() { return &playerPosition.y; }

	bool playerHasKey() { return hasKey; }
	bool PickUpKey();
	bool UseKey();

	void drawPlayer();
};

#endif
