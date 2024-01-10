#include "Level.h"
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <conio.h>
using namespace std;

constexpr char WAL = (char)219;
constexpr char KEY = (char)232;
constexpr char DOR = (char)179;
constexpr char GOL = (char)36;

Level::Level(char* pLevel = nullptr, int width = 0, int height = 0)
	: pLevel{ pLevel }, width{ width }, height{ height } {};

Level::~Level()
{
	if (pLevel != nullptr)
	{
		pLevel = nullptr;
		delete[] pLevel;
	}
}

void Level::drawLevel(int x, int y)
{
	int index = getIndex(x, y);
	cout << pLevel[index];
}

bool Level::loadlevel(string levelName, int* pPlayerPositionX, int* pPlayerPositionY)
{
	levelName.insert(0, "../");
	ifstream levelFile;
	levelFile.open(levelName);

	if (!levelFile)
	{
		cout << "Error";
		delete[] pLevel;
		pLevel = nullptr;
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
		levelFile.read(pLevel, width*height);

		bool anyWarnings = convertLevel(pPlayerPositionX, pPlayerPositionY);
		if (anyWarnings)
		{
			cout << "Error";
			delete[] pLevel;
			pLevel = nullptr;
			return false;
		}
		else
		{
			delete[] pLevel;
			pLevel = nullptr;
			return true;
		}
	}
	delete[] pLevel;
	pLevel = nullptr;
	return false;
}

bool Level::convertLevel(int* pPlayerPositionX, int* pPlayerPositionY)
{
	for (int x = 0; x < width; ++x)
	{
		for (int y = 0; y < height; ++y)
		{
			int index = getIndex(x, y);
			cout << pLevel[index];

			switch (pLevel[index])
			{
			case '|':
			case '+':
			case '-':
				pLevel[index] = WAL;
				break;
			case ' ':
				pLevel[index] = ' ';
				break;
			case 'X':
				pLevel[index] = GOL;
				break;
			case 'D':
				pLevel[index] = DOR;
				break;
			case '*':
				pLevel[index] = KEY;
				break;
			case '@':
				pLevel[index] = ' ';
				if (pPlayerPositionX != nullptr && pPlayerPositionY != nullptr)
				*pPlayerPositionX = x;
				*pPlayerPositionY = y;
				break;
			default:
				cout << "Error in character read ";
				return true;
				break;
			}
		}
	}
	return false;
}

bool Level::isKey(int x, int y)
{
	return pLevel[getIndex(x, y)] = KEY;
}

bool Level::isSpace(int x, int y)
{
	return pLevel[getIndex(x, y)] = ' ';
}

bool Level::isDoor(int x, int y)
{
	return pLevel[getIndex(x, y)] = DOR;
}

bool Level::isWall(int x, int y)
{
	return pLevel[getIndex(x, y)] = WAL;
}

bool Level::useKey(int x, int y)
{
	return pLevel[getIndex(x, y)] = ' ';
}

int Level::getIndex(int x, int y)
{
	return x + y * width;
}

bool Level::isGoal(int x, int y)
{
	return pLevel[getIndex(x, y)] = GOL;
}

