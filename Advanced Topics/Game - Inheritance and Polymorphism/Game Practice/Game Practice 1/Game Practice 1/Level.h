#pragma once
#include "Player.h"
#include <vector>
#include <string>

class Level
{
private:

	int _height;
	int _width;
	char* _pLevel;
	vector<PlaceableActor*>_pActors;

	bool convertLevel(int* playerX, int* playerY);

public:

	Level();
	~Level();

	bool loadlevel(string levelName, int* playerX, int* playerY);
	void draw();
	void updateLevel();

	PlaceableActor* updateActors(int x, int y);


	int getHeight() { return _height; }
	int getWidth() { return _width; }
	int getIndex(int x, int y) { return x + y * _width; }

	bool isSpace(int x, int y);
	bool isWall(int x, int y);

	static constexpr char WAL = (char)219;

};