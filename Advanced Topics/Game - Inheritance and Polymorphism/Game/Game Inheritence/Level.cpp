#include <Windows.h>
#include "Level.h"
#include <iostream>
#include <fstream>
#include "Player.h"
#include "Enemy.h" // derived Placeable Actor Classes
#include "Key.h"
#include "Door.h"
#include "Goal.h"
#include "Money.h"
#include <assert.h>

using namespace std;

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

	while (!m_pActors.empty())
	{
		delete m_pActors.back(); // return us the elements at end, then delete
		m_pActors.pop_back(); // continue to delete the remaining vector elements.
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

		levelFile.getline(temp, tempSize, '\n'); // line 83 and line 87 link.
		height = atoi(temp);

		plevel = new char[width * height]; // array that needs to be deallocated.
		levelFile.read(plevel, width * height);

		if (playerX != nullptr && playerY != nullptr)
		{
			bool anyWarnings = Convert(playerX, playerY);
			if (anyWarnings)
			{
				cout << "There are some warnings in the level data. see above." << endl;
				system("pause");
			}
		}
		return true;
	}
}

void Level::Draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // temprary variables being deleted at the end of draw.
	SetConsoleTextAttribute(console, (int)ActorColour::Regular); 

	//Draw Level
	for (int y = 0; y < GetHeight(); ++y)
	{
		for (int x = 0; x < GetWidth(); ++x)
		{
			int indexToPoint = GetIndex(x, y);
			cout << plevel[indexToPoint];
		}
		cout << endl;
	}

	COORD actorCursorPosition; // position the cursor at correct location, x and y variables

	// Draw actors

	for (auto actor = m_pActors.begin(); actor != m_pActors.end(); ++actor) // going to the beginning and through the end.
	{
		if ((*actor)->IsActive()) // if active I want to draw. 
		{
			actorCursorPosition.X = (*actor)->GetXPosition();
			actorCursorPosition.Y = (*actor)->GetYPosition();
			SetConsoleCursorPosition(console, actorCursorPosition); // set position manually to this point.
			(*actor)->Draw(); // draw the actors, tempoary variable in line 93 is now finished and deleted from the stack.
		}
	}
}

bool Level::IsSpace(int x, int y)
{
	return plevel[GetIndex(x, y)] == ' ';
}
bool Level::IsWall(int x, int y)
{
	return plevel[GetIndex(x, y)] == WAL;
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
			case ' ':
			{
				break;
			};
			case 'r':
				plevel[intIndex] = ' ';
				m_pActors.push_back(new Key(x, y, ActorColour::Red));
				break;
			case 'g':
				plevel[intIndex] = ' ';
				m_pActors.push_back(new Key(x, y, ActorColour::Green));
				break;
			case 'b':
				plevel[intIndex] = ' ';
				m_pActors.push_back(new Key(x, y, ActorColour::Blue));
				break;
			case 'R':
				plevel[intIndex] = ' ';
				m_pActors.push_back(new Door(x, y, ActorColour::Red, ActorColour::RedSolid));
				break;
			case 'G':
				plevel[intIndex] = ' ';
				m_pActors.push_back(new Door(x, y, ActorColour::Green, ActorColour::GreenSolid));
				break;
			case 'B':
				plevel[intIndex] = ' ';
				m_pActors.push_back(new Door(x, y, ActorColour::Blue, ActorColour::BlueSolid));
				break;
			case 'X':
				plevel[intIndex] = ' ';
				m_pActors.push_back(new Goal(x, y));
				break;
			case '$':
				plevel[intIndex] = ' ';
				m_pActors.push_back(new Money(x, y, 1 + rand() % 5));
				break;
			case '@':
			{
				plevel[intIndex] = ' ';
				if (playerX != nullptr && playerY != nullptr)
				{
					*playerX = x;
					*playerY = y;
				}
				break;
			}
			case 'e':
				m_pActors.push_back(new Enemy(x, y));
				plevel[intIndex] = ' '; // clear level
				break;
			case 'h': // horiztonal enemy
				m_pActors.push_back(new Enemy(x, y, 3, 0));
				plevel[intIndex] = ' ';
				break;
			case 'v': // vertical enemy
				plevel[intIndex] = ' ';
				m_pActors.push_back(new Enemy(x, y, 0, 2));
				plevel[intIndex] = ' ';
				break;
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

// Updates all actors and returns a colliding actor is there is one.

PlaceableActor* Level::UpdateActors(int x, int y ) // pass in x and y of player.
{

	PlaceableActor* collidedActor = nullptr;

	for (auto actor = m_pActors.begin(); actor != m_pActors.end(); ++actor)
	{
		(*actor)->Update(); //update all actors

		if (x == (*actor)->GetXPosition() && y == (*actor)->GetYPosition()) // collision occured
		{
			assert(collidedActor == nullptr); // if assertion fails, two points have met.
			collidedActor = (*actor); // points to the location of the collision.
		}
	}
	return collidedActor;
}