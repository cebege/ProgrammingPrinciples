#include "Game.h"
#include <conio.h>
#include <Windows.h>
#include <iostream>

using namespace std;

constexpr int kOpenDoorColour = 10;
constexpr int kClosedDoorColour = 12;
constexpr int kRegularDoorColour = 7;

Game::Game()
	:gameOver{ false } {};

Game::~Game() {};

bool Game::Load()
{
	return level1.LoadLevel("Level2.txt", player1.pGetXPosition(), player1.pGetYPosition());
}
void Game::Run()
{
	Draw();
	gameOver = Update();

	if (gameOver)
	{
		Draw();
	}
}

bool Game::isGameOver()
{
	return gameOver;
}

bool Game::Update()
{
	char input = _getch(); // helps the player move without having to press enter every time.

	int new_player_x = player1.GetXPosition();
	int new_player_y = player1.GetYPosition();

	switch (input)
	{
	case 'w':
	case 'W':
	{
		new_player_y--;
		break;
	}
	case 's':
	case 'S':
	{
		new_player_y++;
		break;
	}
	case 'a':
	case 'A':
	{
		new_player_x--;
		break;
	}
	case 'd':
	case 'D':
	{
		new_player_x++;
		break;
	}
	default:
		break;
	}

															
	if (level1.IsSpace(new_player_x, new_player_y))
	{
		player1.SetXYPosition(new_player_x, new_player_y);
	}
	if (level1.IsKey(new_player_x, new_player_y))
	{
		level1.PickUpKey(new_player_x, new_player_y);
		player1.PickUpKey();
		level1.IsSpace(new_player_x, new_player_y); // erase key from map
		player1.SetXYPosition(new_player_x, new_player_y);
	}
	if (level1.IsDoor(new_player_x, new_player_y) && player1.HasKey())
	{
		level1.OpenDoor(new_player_x, new_player_y);
		player1.UseKey();
		level1.IsSpace(new_player_x, new_player_y); // erase door from map
		player1.SetXYPosition(new_player_x, new_player_y);
	}
	if (level1.IsDoor(new_player_x, new_player_y) && !player1.HasKey())
	{
		//PlayDoorClose();
	}
	if (level1.IsGoal(new_player_x, new_player_y))
	{
		level1.IsSpace(new_player_x, new_player_y);
		player1.SetXYPosition(new_player_x, new_player_y);
		return true;
	}
	return false;
}

void Game::Draw()
{
	system("cls");
	for (int y = 0; y < level1.GetHeight(); y++)
	{
		for (int x = 0; x < level1.GetWidth(); x++)
		{
			if (player1.GetXPosition() == x && player1.GetYPosition() == y)
			{
				player1.DrawPlayer();
			}
			else
			{
				int index = level1.GetIndex(x, y);
				HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
				if (level1.IsDoor(x, y))
				{
					if (player1.HasKey())
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
				level1.Draw(x, y);
				}
			}
			cout << endl;
		}
}