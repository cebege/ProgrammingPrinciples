// Remeber to insert pause system within the any warnings message.
// Remember to position x and y within pPlayer within the player switch.

#include "Level.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

constexpr char WAL = (char)219;
constexpr char KEY = (char)232;
constexpr char DOR = (char)179;
constexpr char GOL = (char)36;

Level::Level()
	: pLevel{ nullptr }{};

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
	}
	else
	{
		constexpr int tempSize = 50; // ??
		char temp[tempSize];

		levelFile.getline(temp, tempSize, '\n'); // delimitor, cingetlin function, reads the first line
		width = atoi(temp);

		levelFile.getline(temp, tempSize, '\n'); // reads second line.
		height = atoi(temp);

		pLevel = new char[width * height];
		levelFile.read(pLevel, width * height); // reads the file data, based on the width and height.

		bool anyWarnings = convertLevel(pPlayerX, pPlayerY);
		if (anyWarnings)
		{
			cout << "Errors";
			system("pause");
		}
		else
		{
			return true;
		}
	}
}

bool Level::convertLevel(int* pPlayerX, int* pPlayerY)
{
	bool anyWarnings = false;

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int Index = getIndex(x, y); // 
			cout << pLevel[Index];

			switch (pLevel[Index])
			{
			case '|':
			case '-':
			case '+':
				pLevel[Index] = WAL;
				break;
			case 'X':
				pLevel[Index] = GOL;
				break;
			case '*':
				pLevel[Index] = KEY;
				break;
			case 'D':
				pLevel[Index] = DOR;
				break;
			case ' ':
				break;
			case '@':
				pLevel[Index] = ' ';
				*pPlayerX = x;
				*pPlayerY = y;
				break;
			default:
				cout << "Error in reading at " << pLevel[Index];
				anyWarnings = true;
				break;
			}
		}
	}
	return anyWarnings;
}

void Level::drawLevel(int x, int y)
{
	int Index = getIndex(x, y);
	for (int i = 0; i < width * height; ++i)
	{
		cout << pLevel[Index];
	}
}

bool Level::isKey(int x, int y)
{
	return (pLevel[getIndex(x, y)] == KEY);
}

bool Level::isDoor(int x, int y)
{
	return (pLevel[getIndex(x, y)] == DOR);
}

bool Level::isWall(int x, int y)
{
	return (pLevel[getIndex(x, y)] == WAL);
}

bool Level::isGoal(int x, int y)
{
	return (pLevel[getIndex(x, y)] == GOL);
}

bool Level::isSpace(int x, int y)
{
	return (pLevel[getIndex(x, y)] == ' ');
}

int Level::getIndex(int x, int y)
{
	return x + y * width;
}