#pragma once
#include <vector>
#include "Player.h"

using namespace std;

class PlaceableActor;

class Level
{
private:
	char* mPLevel;
	int mWidth;
	int mHeight;

	vector<PlaceableActor*> mActors;

public:

	Level();
	~Level();

	PlaceableActor* updateActors(int x, int y);

	bool loadLevel(string levelName, int* playerX, int* playerY);

	bool isWall();
	bool isSpace();

	int getHeight() { return mHeight; }
	int getWidth() { return mWidth; }
	int getIndex(int x, int y);

	void draw();

private:
	bool convertLevel(int* playerX, int* playerY);

};