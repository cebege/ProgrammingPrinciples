#include "Game.h"
#include <conio.h>
#include <Windows.h>
#include <iostream>

constexpr int kOpenDoorColour = 10;
constexpr int kClosedDoorColour = 12;
constexpr int kRegularDoorColour = 7;

Game::Game()
	: gameOver(false) {};

Game::~Game() {};

bool Game::load()
{
	return level.loadLevel("Level1.txt", player.pGetPlayerXPosition(), player.pGetPlayerYPosition());
}

bool Game::run() // someone else 
{
	draw();
	gameOver = update();
	if (gameOver)
	{
		draw();
	}
}

void Game::draw()
{
	system("cls");
	for (int y = 0; y < level.getHeight(); ++y)
	{
		for (int x = 0; x < level.getWidth(); ++x)
		{
			if (player.getPlayerXPosition() == x && player.getPlayerYPosition() == y)
			{
				player.drawPlayer();
			}
			else
			{
				int index = level.getIndex(x, y);
				HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
				if (level.isDoor(x, y))
				{
					if (player.playerHasKey())
					{
						SetConsoleTextAttribute(console, kOpenDoorColour);
					}
					else
					{
						SetConsoleTextAttribute(console, kClosedDoorColour);
					}
				}
				else
				{
					SetConsoleTextAttribute(console, kRegularDoorColour);
				}
				level.drawLevel(x, y);
			}
		}
	}
}

bool Game::update()
{
	char Input = _getch();

	int newPlayerX = player.getPlayerXPosition();
	int newPlayerY = player.getPlayerXPosition();

	switch (Input)
	{
	case 'a':
	case 'A':
		newPlayerX--;
		break;
	case 'd':
	case 'D':
		newPlayerX++;
		break;
	case 'w':
	case 'W':
		newPlayerY--;
		break;
	case 's':
	case 'S':
		newPlayerY++;
		break;
	}



}

