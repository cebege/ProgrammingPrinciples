#include "Level.h"
#include "Money.h"
#include "Door.h"
#include "Player.h"
#include "Key.h"
#include "Enemy.h"
#include "Point.h"
#include "PlaceableActor.h"
#include <fstream>
#include <Windows.h>
#include <ctime>
#include <assert.h>

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
		mPLevel = nullptr;
		delete mPLevel;
	}
	while (!mActors.empty())
	{
		delete mActors.back();
		mActors.pop_back();
	}
}

bool Level::loadLevel(string levelName, int* playerX, int* playerY)
{
	levelName.insert(0, "../");
	ifstream levelFile;
	levelFile.open(levelName);
	if (!levelFile)
	{
		cout << "Errors encountered." << endl;
		return false;
	}
	else
	{
		const int tempSize = 25;
		char temp[tempSize];

		levelFile.getline(temp, tempSize);
		mWidth = atoi(temp);

		levelFile.getline(temp, tempSize);
		mHeight = atoi(temp);

		mPLevel = new char[mWidth * mHeight];
		levelFile.read(mPLevel, mWidth * mHeight);

		if (playerX != nullptr && playerY != nullptr)
		{
			bool anyWarnings = convertLevel(playerX, playerY);
			if (anyWarnings)
			{
				cout << "Warnings";
				system("pause");
				return false;
			}
			else
				return true;
		}
	}
}

void Level::draw()
{

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int y = 0; y < getHeight(); ++y)
	{
		for (int x = 0; x < getWidth(); ++x)
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
			actorCursorPosition.X = (*actor)->getXPosition();
			actorCursorPosition.Y = (*actor)->getYPosition();
			SetConsoleCursorPosition(console, actorCursorPosition);
			(*actor)->draw();
		}
	}
}

bool Level::convertLevel(int* playerX, int* playerY)
{
	bool anyWarnings = false;

	for (int y = 0; y < getHeight(); ++y)
	{
		for (int x = 0; x < getWidth(); ++x)
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
				break;
			case 'r':
				mPLevel[index] = ' '; // cleaning up display in the level array
				mActors.push_back(new Key(x, y, kRedColour)); // turning into actors.
				break;
			case 'b':
				mPLevel[index] = ' ';
				mActors.push_back(new Key(x, y, kBlueColour));
				break;
			case 'g':
				mPLevel[index] = ' ';
				mActors.push_back(new Key(x, y, kGreenColour));
				break;
			case 'R':
				mPLevel[index] = ' ';
				mActors.push_back(new Door(x, y, kRedColour, kRedColourSolid));
				break;
			case 'B':
				mPLevel[index] = ' ';
				mActors.push_back(new Door(x, y, kBlueColour, kBlueColourSolid));
				break;
			case 'G':
				mPLevel[index] = ' ';
				mActors.push_back(new Door(x, y, kGreenColour, kGreenColourSolid));
				break;
			case '@':
				mPLevel[index] = ' ';
				if (playerX != nullptr && playerY != nullptr)
				{
					*playerX = x;
					*playerY = y;
				}
				break;
			case '$':
				mPLevel[index] = ' ';
				mActors.push_back(new Money(x, y, 1 + rand() % 5));
				break;
			case 'e':
				mPLevel[index] = ' ';
				mActors.push_back(new Enemy(x, y, 0, 0));
				break;
			case 'h':
				mPLevel[index] = ' ';
				mActors.push_back(new Enemy(x, y, 3, 0));
				break;
			case 'v':
				mPLevel[index] = ' ';
				mActors.push_back(new Enemy(x, y, 0, 3));
				break;
			default:
				cout << "Error in reading";
				anyWarnings = true;
			}
		}
	}
	return anyWarnings;
}

PlaceableActor* Level::updateActors(int x, int y)
{
	PlaceableActor* collidedActor = nullptr;

	for (auto actor = mActors.begin(); actor < mActors.end(); ++actor)
	{
		(*actor)->update();

		if (x == (*actor)->getXPosition() && y == (*actor)->getYPosition())
		{
			assert(collidedActor == nullptr);
			collidedActor = (*actor);
		}
	}
	return collidedActor;
}

