#include "Game.h"
#include "Enemy.h"
#include "Key.h"
#include "Player.h"
#include "Money.h"
#include "Door.h"
#include "Goal.h"
#include "PlaceableActor.h"
#include <conio.h>
#include <Windows.h>

constexpr int kArrowInput = 224;
constexpr int kLeftArrow = 75;
constexpr int kRightArrow = 77;
constexpr int kUpArrow = 72;
constexpr int kDownArrow = 80;

constexpr int kEscape = 27;
constexpr int kBackspace = 8;

using namespace std;

Game::Game()
	: mGameOver(false)
{};

Game::~Game()
{};

bool Game::load()
{
	mLevel.loadLevel("Level1.txt", mPlayer.getXPositionP(), mPlayer.getYPositionP();
}

void Game::run()
{
	draw();

	mGameOver = update();

	while (mGameOver)
	{
		draw();
	}
}

bool Game::update()
{
	int input = _getch();
	int arrowInput = 0;
	int newPlayerX = mPlayer.getXPosition();
	int newPlayerY = mPlayer.getYPosition();

	if (input == kArrowInput)
	{
		arrowInput = _getch();
	}

	if ((input == kArrowInput && arrowInput == kUpArrow) ||
		(char)input == 'w' && char(input) == 'W')
	{
		newPlayerY--;
	}

	if (input == kEscape)
	{
		return true;
	}

	if ((char)input == 'z' || (char)input == 'Z')
	{
		mPlayer.dropKey();
	}
}

bool Game::handleCollision(int newPlayerX, int newPlayerY)
{
	PlaceableActor* collidedActor = mLevel.updateActors(newPlayerX, newPlayerY);

	if (collidedActor != nullptr && collidedActor->isActive())
	{
		Enemy* collidedEnemy = dynamic_cast<Enemy*>(collidedActor);

		if (collidedEnemy)
		{
			collidedEnemy->remove();
			mPlayer.setXYposition(newPlayerX, newPlayerY);
			mPlayer.decrementLives();
			if (mPlayer.getLives() < 0)
			{
				return true;
			}
		}
	}
}

void Game::draw()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");

	mLevel.draw();

	COORD actorCusorPosition;

	actorCusorPosition.X = mPlayer.getXPosition();
	actorCusorPosition.Y = mPlayer.getYPosition();
	SetConsoleCursorPosition(console, actorCusorPosition);
	mPlayer.draw();

	COORD currentCursorPosition;

	actorCusorPosition.X = 0;
	actorCusorPosition.Y = mLevel.getHeight();
	SetConsoleCursorPosition(console, actorCusorPosition);
}