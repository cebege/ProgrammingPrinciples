#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "Point.h"

constexpr char kPlayer = '@';

class Player
{
private:
	bool hasKey;
	Point playerPosition;

public:
	Player();
	~Player();

	bool PickUpKey() { hasKey = true; }
	bool HasKey() { hasKey = true; }
	bool UseKey() { hasKey = false; }
	
	int * getPlayerXPositionP() { return &playerPosition.x; }
	int * getPlayerYPositionP() { return &playerPosition.y; }
	
	int getPlayerXPosition() { return playerPosition.x; }
	int getPlayerYPosition() { return playerPosition.y; }
	void setXYPosition(int x, int y);
	void drawPlayer();

};

#endif