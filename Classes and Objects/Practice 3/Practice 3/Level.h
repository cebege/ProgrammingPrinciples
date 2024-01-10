#include "Player.h"
#include <string>
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

	void drawLevel(int x, int y);
	bool loadlevel(string levelName, int* pPlayerPositionX, int* pPlayerPositionY);
	
	bool isKey(int x, int y);
	bool isSpace(int x, int y);
	bool isWall(int x, int y);
	bool isGoal(int x, int y);

	bool isDoor(int x, int y);
	bool useKey(int x, int y);

	int getWidth() { return width; }
	int getHeight() { return height; }

	int getIndex(int x, int y);
	bool convertLevel(int* pPlayerPositionX, int* pPlayerPositionY);

};
