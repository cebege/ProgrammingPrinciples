#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "Player.h"
#include <string>

class Level
{
private:
	char * pLevel;
	int height;
	int width;

public:
	Level();
	~Level();


	void drawLevel(char* pLevel, int width, int height);

	bool isKey(int x, int y);
	bool isDoor(int x, int y);
	bool isGoal(int x, int y);
	bool isWall(int x, int y);
	bool isSpace(int x, int y);

	bool PickUpKey(int x, int y);
	bool OpenDoor(int x, int y);

	int getHeight() { return height; }
	int getWidth() { return width; }
	int getIndex(int x, int y);
	bool loadLevel(string levelName, int* pPlayerX, int* pPlayerY);

private:

	bool convertLevel(int* pPlayerX, int* pPlayerY);
};

#endif



