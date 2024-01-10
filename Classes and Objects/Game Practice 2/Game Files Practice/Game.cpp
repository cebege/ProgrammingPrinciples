#include "Game.h"
#include <conio.h>

using namespace std;

Game::Game()
{

}

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

bool Game::load()
{
	return level.loadLevel("LevelName.txt", player.getPlayerXPositionP(), player.getPlayerYPositionP());
}

bool Game::update()
{
	char Index = _getch();

	int updatePlayerPositionX = player.getPlayerXPosition();
	int updatePlayerPositionY = player.getPlayerYPosition();

	switch (Index)
	{
	case 'W':
	case 'w':
		updatePlayerPositionY--;
		break;
	case 'S':
	case 's':
		updatePlayerPositionY++;
		break;
	case 'A':
	case 'a':
		updatePlayerPositionX--;
		break;
	case 'D':
	case 'd':
		updatePlayerPositionX++;
		break;
	}

	if (level.isSpace(updatePlayerPositionX, updatePlayerPositionY))
	{
		player.setXYPosition(updatePlayerPositionX, updatePlayerPositionY);
	}

	if (level.isDoor(updatePlayerPositionX, updatePlayerPositionY) && player.HasKey())
	{
		level.OpenDoor(updatePlayerPositionX, updatePlayerPositionY);
		player.UseKey();
		level.isSpace(updatePlayerPositionX, updatePlayerPositionY);
		player.setXYPosition(updatePlayerPositionX, updatePlayerPositionY);
	}
	if (level.isGoal(updatePlayerPositionX, updatePlayerPositionY))
	{
		level.isSpace(updatePlayerPositionX, updatePlayerPositionY);
		player.setXYPosition(updatePlayerPositionX, updatePlayerPositionY);
		return true;
	}
	return false;

}
