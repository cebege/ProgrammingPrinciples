#include "Level.h"
#include <fstream>
#include <Windows.h>
#include <iostream>
#include <string>

using namespace std;

constexpr char WAL = (char)219;
constexpr char KEY = (char)232;
constexpr char DOR = (char)179;
constexpr char GOL = (char)36;

Level::Level()
	: pLevel{ nullptr } {};

Level::~Level()
{
	if (pLevel != nullptr)
	{
		delete[] pLevel;
		pLevel = nullptr;
	}
}

bool Level::loadLevel(string levelName, int* pPlayerX, int* pPlayerY)
{
	levelName.insert(0, "../");
	ifstream levelFile;
	levelFile.open(levelName);

	if (!levelFile)
	{
		cout << "Error.";
		return false;
	}
	else
	{
		constexpr int tempSize = 25;
		char temp[tempSize];

		levelFile.getline(temp, tempSize, '\n');
		width = atoi(temp);

		levelFile.getline(temp, tempSize, '\n');
		height = atoi(temp);

		pLevel = new char[width * height];
		levelFile.read(pLevel, width * height);

		bool anyWarnings = convertLevel(pPlayerX, pPlayerY);
		if (anyWarnings)
		{
			cout << "Error in converting file.";
			system("pause");
			delete[] pLevel;
			return false;
		}
		delete[] pLevel;
		return true;
	}
	delete[] pLevel;
	return false;
}

bool Level::convertLevel(int* pPlayerX, int* pPlayerY)
{
	bool anyWarnings = false;
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int index = getIndex(x, y);

			switch (pLevel[index])
			{
			case '|':
			case '+':
			case '-':
				pLevel[index] = WAL;
				break;
			case '*':
				pLevel[index] = KEY;
				break;
			case 'D':
				pLevel[index] = DOR;
				break;
			case 'X':
				pLevel[index] = GOL;
				break;
			case ' ':
				break;
			case '@':
				pLevel[index] = ' ';
				*pPlayerX = x;
				*pPlayerY = y;
				break;
			default:
				cout << "Error converting.";
				anyWarnings = true;
				break;
			}
		}
	}
	return anyWarnings;
}

int Level::getIndex(int x, int y)
{
	return x + y * width;
}

void Level::drawLevel(char * pLevel, int width, int height)
{
	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int index = getIndex(x, y);
			cout << pLevel[index];
		}
	}
}

bool Level::isKey(int x, int y)
{
	if (pLevel[getIndex(x, y)] = KEY);
}

bool Level::isSpace(int x, int y)
{
	if (pLevel[getIndex(x, y)] = ' ');
}

bool Level::isDoor(int x, int y)
{
	if (pLevel[getIndex(x, y)] = DOR);
}

bool Level::isGoal(int x, int y)
{
	if (pLevel[getIndex(x, y)] = GOL);
}

bool Level::isWall(int x, int y)
{
	if (pLevel[getIndex(x, y)] = WAL);
}

bool Level::PickUpKey(int x, int y)
{
	if (pLevel[getIndex(x, y)] = ' ');
}

bool Level::OpenDoor(int x, int y)
{
	if (pLevel[getIndex(x, y)] = ' ');
}