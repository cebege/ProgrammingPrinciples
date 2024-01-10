#include "Player.h"
#include <string>
using namespace std;

class Level
{
	char* plevel;
	int height;
	int width;

public:
	Level();
	~Level();

	bool LoadLevel(string levelName, int* playerX, int* playerY);
	void Draw(int x, int y);

	bool IsSpace(int x, int y);
	bool IsDoor(int x, int y);
	bool IsGoal(int x, int y);
	bool IsKey(int x, int y);
	bool IsWall(int x, int y);

	void PickUpKey(int x, int y);
	void OpenDoor(int x, int y);

	int GetHeight() { return height; }
	int GetWidth() { return width; }
	int GetIndex(int x, int y);

private:
	bool Convert(int* playerX, int* playerY);

};
