#include "Level.h"
#include <string>
#include <fstream>
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

constexpr char WAL = (char)219;
constexpr char KEY = (char)232;
constexpr char DOR = (char)179;
constexpr char GOL = (char)36;

Level::Level(char* pLevel, int width, int height)
	: pLevel{ pLevel }, width{ width }, height{ height } {};

Level::~Level()
{
	if (pLevel != nullptr)
	{
		delete[] pLevel;
		pLevel = nullptr;
	}
}

bool Level::loadLevel(string levelName, int* playerPositionX_p, int* playerPositionY_p)
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

		if (playerPositionX_p != nullptr && playerPositionY_p != nullptr)
		{
			bool anyWarnings = convertLevel(playerPositionX_p, playerPositionY_p);
			if (anyWarnings)
			{
				cout << "Error!";
				system("pause");
			}
			return true;
		}
	}
}

bool Level::convertLevel(int* playerPositionX_p, int* playerPositionY_p)
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
			case ' ':
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
			case '@':
				pLevel[index] = ' ';
				if (playerPositionX_p != nullptr && playerPositionY_p != nullptr)
				{
					*playerPositionX_p = x;
					*playerPositionY_p = y;
				}
				break;
			default:
				cout << "Error in character at " << pLevel[index];
				return true;
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

void Level::drawLevel(int x, int y)
{
	int index = getIndex(x, y);
	cout << pLevel[index];
}

bool Level::isKey(int x, int y)
{
	return pLevel[getIndex(x, y)] == KEY;
}

bool Level::isDoor(int x, int y)
{
	return pLevel[getIndex(x, y)] == DOR;
}

bool Level::isGoal(int x, int y)
{
	return pLevel[getIndex(x, y)] == GOL;
}

bool Level::isSpace(int x, int y)
{
	return pLevel[getIndex(x, y)] == ' ';
}

bool Level::isWall(int x, int y)
{
	return pLevel[getIndex(x, y)] == WAL;
}