#ifndef _LEVEL_H_
#define _LEVEL_H_
#include "Player.h"
#include <string>
using namespace std;

class Level
{
private:
	char* pLevel;
	int height;
	int width;

public:
	Level();
	~Level();

	void drawLevel(int x, int y);
	bool loadLevel(string levelName, int* pPlayerX, int* pPlayerY);

	bool isKey(int x, int y);
	bool isDoor(int x, int y);
	bool isWall(int x, int y);
	bool isGoal(int x, int y);
	bool isSpace(int x, int y);

	int getHeight() { return height; }
	int getWidth() { return width; }
	int getIndex(int x, int y);

private:
	bool convertLevel(int * pPlayerX, int * pPlayerY);

};


#endif
