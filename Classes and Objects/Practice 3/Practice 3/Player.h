#include "Point.h"

class Player
{
private:
	bool hasKey;
	Point playerPosition;

public:
	Player();
	~Player();

	void setPlayerPosition(int x, int y);
	int getPlayerPositionX() { return playerPosition.x; }
	int getPlayerPositionY() { return playerPosition.y; }
	int* getPlayerPositionY_p() { return &(playerPosition.y); }
	int* getPlayerPositionX_p() { return &(playerPosition.x); }
	void drawPlayer();

	bool playerHasKey() { hasKey = true; }
	bool useKey() { hasKey = false; }
	bool pickUpKey() { hasKey = true; }

};
