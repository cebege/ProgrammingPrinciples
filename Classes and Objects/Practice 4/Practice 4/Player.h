#include "Point.h"
#include <Windows.h>

class Player
{
private:
	Point playerPosition;
	bool hasKey;

public:
	Player(bool hasKey = false);
	~Player();

	void setXYposition(int x, int y);

	int getPlayerPositionX() { return playerPosition.x; }
	int getPlayerPositionY() { return playerPosition.y; }
	int* getPlayerPositionX_p() { return &(playerPosition.x); }
	int* getPlayerPositionY_p() { return &(playerPosition.y); }

	bool HasKey() { return hasKey; }
	void playerHasKey() { hasKey = true; }
	void playerUseKey() { hasKey = false; }

	void drawPlayer();




};