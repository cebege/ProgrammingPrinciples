#include "Level.h"
#include <fstream>
#include <iostream>
#include <assert.h>
#include <Windows.h>
#include "Key.h"
#include "Door"

using namespace std;

constexpr char Wal = (char)219;

Level::Level()
	: mPLevel(nullptr)
	, mWidth(0)
	, mHeight(0)
{};
 
Level::~Level()
{
	if (mPLevel != nullptr)
	{
		delete[] mPLevel;
		mPLevel = nullptr;
	}
	while (!mActors.empty())
	{
		mActors.back() = nullptr;
		mActors.pop_back();
	}
}

bool Level::loadLevel(string levelName, int* cursorPositionX, int* cursorPositionY)
{
	levelName.insert(0, "../");
	ifstream levelFile;
	levelFile.open(levelName);

	if (!levelFile)
	{
		cout << "Warning, load incorrect." << endl;
		return false;
	}
	else
	{
		constexpr int tempSize = 25;
		char temp[tempSize];

		levelFile.getline(temp, tempSize, '\n');
		mWidth = atoi(temp);

		levelFile.getline(temp, tempSize, '\n');
		mHeight = atoi(temp);

		mPLevel = new char[mWidth * mHeight];
		levelFile.read(temp, mWidth * mHeight);
		
		bool anyWarnings = convertLevel(cursorPositionX, cursorPositionY);

		if (anyWarnings)
		{
			cout << "There are errors loading level";
			return false;
		}
		else
		{
			cout << "Load successful" << endl;
			return true;
		}
	}
}

void Level::isWall(int x, int y)
{
	mPLevel[getIndex(x, y)] = Wal;
}

void Level::isSpace(int x, int y)
{
	mPLevel[getIndex(x, y)] = ' ';
}

int Level::getIndex(int x, int y)
{
	return x + y * mWidth;
}

PlaceableActor* Level::updateActors(int x, int y)
{
	PlaceableActor* collidedActor = nullptr;

	for (auto actor = mActors.begin(); actor != mActors.end(); ++actor)
	{
		(*actor)->update();

		if ((*actor)->getPositionX() == x && (*actor)->getPositionY() == y)
		{
			assert(collidedActor == nullptr);
			collidedActor = (*actor);
		}
	}
	return collidedActor;
}

void Level::draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int y = 0; y < mHeight; ++y)
	{
		for (int x = 0; x < mWidth; ++x)
		{ 
			int index = getIndex(x, y);
			cout << mPLevel[index];
		}
		cout << endl;
	}

	COORD actorCursorPosition;

	for (auto actor = mActors.begin(); actor != mActors.end(); ++actor)
	{
		if ((*actor)->isActive())
		{
			actorCursorPosition.X = (*actor)->getPositionX();
			actorCursorPosition.Y = (*actor)->getPositionY();
			SetConsoleCursorPosition(console, actorCursorPosition);
			(*actor)->draw();
		}
	}
}

bool Level::convertLevel(int* cursorX, int* cursorY)
{
	bool anyWarnings = false;

	for (int y = 0; y < mHeight; ++y)
	{
		for (int x = 0; x < mWidth; ++x)
		{
			int index = getIndex(x, y);
			
			switch (mPLevel[index])
			{
			case '|':
			case '+':
			case '-':
				mPLevel[index] = Wal;
				break;
			case ' ':
				mPLevel[index] = ' ';
				break;
			case 'r':
				mPLevel[index] = ' ';
				mActors.push_back(new Key (x, y, kRedColour));
				break;
			case 'b':
				mPLevel[index] = ' ';
				mActors.push_back(new Key(x, y, kBlueColour));
				break;
			case 'g':
				mPLevel[index] = ' ';
				mActors.push_back(new Key(x, y, kGreenColour));
				break;
			case '@':
				mPLevel[index] = ' ';
				*cursorX = x;
				*cursorY = y;
				break;


			}

		}
	}


}




