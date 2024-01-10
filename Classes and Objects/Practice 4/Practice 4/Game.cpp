#include "Game.h"
#include <conio.h>
#include <Windows.h>
#include <iostream>
using namespace std;

Game::Game(bool gameOver)
	: gameOver{ gameOver } {};

Game::~Game()
{

}

void Game::run()
{
	draw();
	gameOver = update();
	if (gameOver)
	{
		draw();
	}
}

bool Game::isGameOver()
{
	return gameOver;
}

void Game::draw()
{
	system("cls");
	for (int y = 0; y < level.getHeight(); ++y)
	{
		for (int x = 0; x < level.getWidth(); ++x)
		{
			if (player.getPlayerPositionX() == x && player.getPlayerPositionY() == y)
			{
				player.drawPlayer();
			}
			else
			{
				level.drawLevel(x, y);
			}
		}
		cout << endl;
	}
}

bool Game::update()
{
	char input = _getch();
	int newPlayerPositionX = player.getPlayerPositionX();
	int newPlayerPositionY = player.getPlayerPositionY();

	switch (input)
	{
	case 'w':
	case 'W':
	{
		newPlayerPositionY--;
		break;
	}
	case 's':
	case 'S':
	{
		newPlayerPositionY++;
		break;
	}
	case 'a':
	case 'A':
	{
		newPlayerPositionX--;
		break;
	}
	case 'd':
	case 'D':
	{
		newPlayerPositionX++;
		break;
	}
	default:
		break;
	}

	if (level.isDoor(newPlayerPositionX, newPlayerPositionY) && player.HasKey())
	{
		player.playerUseKey();
		player.setXYposition(newPlayerPositionX, newPlayerPositionY);
		
	}
	if (level.isSpace(newPlayerPositionX, newPlayerPositionY))
	{
		player.setXYposition(newPlayerPositionX, newPlayerPositionY);
	}
	if (level.isKey(newPlayerPositionX, newPlayerPositionY))
	{
		player.playerHasKey();
		player.setXYposition(newPlayerPositionX, newPlayerPositionY);
		
	}
	if (level.isWall(newPlayerPositionX, newPlayerPositionY))
	{
		
	}
	if (level.isGoal(newPlayerPositionX, newPlayerPositionY))
	{
		player.setXYposition(newPlayerPositionX, newPlayerPositionY);
		return true;
	}
	return false;
}

bool Game::load()
{
	return level.loadLevel("Level1.txt", player.getPlayerPositionX_p(), player.getPlayerPositionY_p());
}
