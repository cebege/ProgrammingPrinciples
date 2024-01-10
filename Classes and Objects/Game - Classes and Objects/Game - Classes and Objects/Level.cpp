#include "Level.h"
#include <iostream>
#include <fstream>

using namespace std;

constexpr char WAL = (char)219;
constexpr char KEY = (char)232;
constexpr char DOR = (char)179;
constexpr char GOL = (char)36;

Level::Level()
	: plevel(nullptr)
	, height(0)
	, width(0)
{

};


Level::~Level()
{ 
	if (plevel != nullptr)
	{
		delete[] plevel;
		plevel = nullptr;
	}
};

bool Level::LoadLevel(string levelName, int* playerX, int* playerY)
{
	levelName.insert(0, "../");
	ifstream levelFile;
	levelFile.open(levelName);
	if (!levelFile)
	{
		cout << "An error has occured." << endl;
		return false;
	}
	else
	{
		constexpr int tempSize = 25;
		char temp[tempSize];

		levelFile.getline(temp, tempSize, '\n');
		width = atoi(temp); // converts integer into width.

		levelFile.getline(temp, tempSize, '\n');
		height = atoi(temp);

		plevel = new char[width * height]; // array that we need to deallocate.
		levelFile.read(plevel, width * height);

		bool anyWarnings = Convert(playerX, playerY);
		if (anyWarnings)
		{
			cout << "There are some warnings in the level data. see above." << endl;
			system("pause");
		}
		return true;
	}
}

void Level::Draw(int x, int y)
{
	int index = GetIndex(x, y);
	cout << plevel[index];
}

bool Level::IsSpace(int x, int y)
{
	return plevel[GetIndex(x, y)] == ' ';
}
bool Level::IsDoor(int x, int y)
{
	return plevel[GetIndex(x, y)] == DOR;
}
bool Level::IsGoal(int x, int y)
{
	return plevel[GetIndex(x, y)] == GOL;
}

bool Level::IsKey(int x, int y)
{
	return plevel[GetIndex(x, y)] == KEY;
}

void Level::PickUpKey(int x, int y)
{
	plevel[GetIndex(x, y)] = ' ';
}
void Level::OpenDoor(int x, int y)
{
	plevel[GetIndex(x, y)] = ' ';
}

bool Level::Convert(int* playerX, int* playerY)
{
	bool anyWarnings = false;

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int intIndex = GetIndex(x, y);

			switch (plevel[intIndex])
			{
			case '+':
			case '-':
			case '|':
			{
				plevel[intIndex] = WAL;
				break;
			}
			case '*':
			{
				plevel[intIndex] = KEY;
				break;
			}
			case 'X':
			{
				plevel[intIndex] = GOL;
				break;
			}
			case 'D':
			{
				plevel[intIndex] = DOR;
				break;
			}
			case '@':
			{
				plevel[intIndex] = ' ';
				if (playerX != nullptr && playerY != nullptr)
				*playerX = x;
				*playerY = y;
				break;
			}
			case ' ':
			{
				break;
			};
			default:
			{
				cout << "Invalid character in file " << plevel[intIndex] << endl;
				anyWarnings = true;
				break;
			}
			}
		}
	}
	return anyWarnings;
}

int Level::GetIndex(int x, int y)
{
	return x + y * width;
}