#include "Game.h"
#include <Windows.h>
#include <conio.h>

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

bool Game::loadLevel()
{
	level.loadlevel("LevelName.txt", player.getPlayerPositionX_p(), player.getPlayerPositionY_p());
}

bool Game::update()
{
	char input = _getch();
	int updatePlayerX = player.getPlayerPositionX();
	int updatePlayerY = player.getPlayerPositionY();

	switch (input)
	{
	case 'w':
	case 'W':
		updatePlayerY--;
		break;
	case 's':
	case 'S':
		updatePlayerY++;
		break;
	case 'a':
	case 'A':
		updatePlayerX--;
		break;
	case 'd':
	case 'D':
		updatePlayerX++;
		break;
	}

	if (level.isDoor(updatePlayerX, updatePlayerY) && player.playerHasKey())
	{
		player.useKey();
		player.setPlayerPosition(updatePlayerX, updatePlayerY);
		level.isSpace(updatePlayerX, updatePlayerY);
	}
	if (level.isKey(updatePlayerX, updatePlayerY))
	{
		player.pickUpKey();
		player.setPlayerPosition(updatePlayerX, updatePlayerY);
		level.isSpace(updatePlayerX, updatePlayerY);
	}
	if (level.isWall(updatePlayerX, updatePlayerY))
	{

	}
	if (level.isGoal(updatePlayerX, updatePlayerY))
	{
		player.setPlayerPosition(updatePlayerX, updatePlayerY);
		level.isSpace(updatePlayerX, updatePlayerY);
		return true;
	}
	return false;
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
	}
}