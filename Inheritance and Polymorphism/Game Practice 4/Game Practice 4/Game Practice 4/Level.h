#pragma once
#include "Player.h"
#include <vector>
#include <string>

using namespace std;

class Level
{
private:
	char* mPLevel;
	int mWidth;
	int mHeight;

	vector <PlaceableActor*> mActors;

public:

	Level();
	~Level();

	bool loadLevel(string levelName, int* cursorPositionX, int* cursorPositionY);

	void isWall(int x, int y);
	void isSpace(int x, int y);

	int getIndex(int x, int y);

	PlaceableActor* updateActors(int x, int y);

	void draw();

private:
	bool convertLevel(int* cursorX, int* cursorY);

};