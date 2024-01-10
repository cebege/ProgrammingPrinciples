#include "Level.h"
#include <fstream>
#include <iostream>
#include <Windows.h>

using namespace std;

Level::Level()
	: _pLevel(nullptr)
	, _height(0)
	, _width(0)
{};

Level::~Level()
{
	if (_pLevel != nullptr)
	{
		_pLevel = nullptr;
		delete _pLevel;
	}
	while (!_pActors.empty())
	{
		_pActors.back();
		_pActors.pop_back();

	}
}

bool Level::isSpace(int x, int y)
{
	_pLevel[getIndex(x, y)] == ' ';
}

bool Level::isWall(int x, int y)
{
	_pLevel[getIndex(x, y)] == WAL;
}

bool Level::loadlevel(string levelName, int* playerX, int* playerY)
{
	levelName.insert(0, "../");
	ifstream levelFile;
	levelFile.open(levelName);

	if (!levelFile)
	{
		cout << "Error opening file; 1";
	}
	else
	{
		constexpr int tempSize = 25;
		char temp[tempSize];

		levelFile.getline(temp, tempSize, '\n');
		_width = atoi(temp);

		levelFile.getline(temp, tempSize, '\n');
		_height = atoi(temp);

		_pLevel = new char[_width * _height];
		levelFile.read(temp, _width * _height);

		bool anyWarnings = convertLevel(playerX, playerY);
		if (anyWarnings)
		{
			cout << "There are warnings; 2";
			_pLevel = nullptr;
			delete _pLevel;
			return false;
		}
		else
		{
			return true;
		}
	}
}

bool Level::convertLevel(int* playerX, int* playerY)
{
	bool anyWarnings = false;

	for (int x = 0; x < _width; ++x)
	{
		for (int y = 0; y < _height; ++y)
		{
			int index = getIndex(x, y);

			switch (_pLevel[index])
			{
			case '|':
			case '+':
			case '-':
				_pLevel[index] = WAL;
				break;
			case ' ':
				_pLevel[index] = ' ';
				break;
			case '@':
				_pLevel[index] = ' ';
				*playerX = x;
				*playerY = y;
				break;
			case 'r':
				_pLevel[index] = ' ';
				_pActors.push_back(new Key(x, y, ActorColour::Red));
				break;
				



			}


		}
	}



}

void Level::draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	for (int x = 0; x < _width; ++x)
	{
		for (int y = 0; y < _height; ++y)
		{
			int index = getIndex(x, y);
			cout << _pLevel[index];
		}
		cout << endl;
	}

	COORD actorCursorPosition;

	for (auto actor = _pActors.begin(); actor != _pActors.end(); ++actor)
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

PlaceableActor* Level::updateActors(int x, int y)
{
	PlaceableActor* collidedActor = nullptr;

	for (auto actor = _pActors.begin(); actor != _pActors.end(); ++actor)
	{
		(*actor)->update();
		if (collidedActor != nullptr)
		{
			if ((*actor)->getPositionX() == x && (*actor)->getPositionY() == y)
			{
				collidedActor = (*actor);
			}
		}
	}
}