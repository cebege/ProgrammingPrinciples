#include "Player.h"
#include <string>
#include <Windows.h>

using namespace std;

class Level
{
private:
	char* pLevel;
	int width;
	int height;

public:
	Level(char* pLevel = nullptr, int width = 0, int height = 0);
	~Level();

	bool loadLevel(string levelName, int* playerPositionX_p, int* playerPositionY_p);
	
	void drawLevel(int x, int y);
	bool isKey(int x, int y);
	bool isDoor(int x, int y);
	bool isGoal(int x, int y);
	bool isSpace(int x, int y);
	bool isWall(int x, int y);

	int getIndex(int x, int y);
	int getWidth() { return width; }
	int getHeight() { return height; }

private:
	bool convertLevel(int* playerPositionX_p, int* playerPositionY_p);
};